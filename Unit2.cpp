//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include <stdio.h>
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Read_T::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
//const WCHAR *name = L"\\\\.\\C:";
DWORD block_size;

void __fastcall Read_T::SizeError()
{
	Form1 -> Label1 -> Caption = L"Block can't be less 512 bytes";
}

void __fastcall Read_T::DiskError()
{
	Form1 -> Label1 -> Caption = L"Can't open disk!";
}

void __fastcall Read_T::PosError()
{
	Form1 -> Label1 -> Caption = L"Position error!";
}

void __fastcall Read_T::Finished()
{
	Form1 -> Label1 -> Caption = L"Finished!";
}

void __fastcall Read_T::RBError()
{
	Form1 -> Label1 -> Caption = L"Can't read block";
}

__fastcall Read_T::Read_T(wchar_t *disk,bool CreateSuspended)
	: TThread(CreateSuspended)
{
	block_size = (Form1 -> Edit1 -> Text).ToInt()*1024;
	if (block_size < 512)
	{
		Synchronize(&SizeError);
		return;
	}
	name = (Form1 -> Edit2 -> Text).c_str();
	FreeOnTerminate = true;
	Event = new TEvent(NULL, true, false, "", false);
}
//---------------------------------------------------------------------------
void __fastcall Read_T::Execute()
{
	HANDLE Handle = CreateFileW(L"\\\\.\\C:", GENERIC_READ,
	FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,
	NULL);
	if (Handle == INVALID_HANDLE_VALUE)
	{
	   Synchronize(&DiskError);
	   return void();
	}
	LARGE_INTEGER Offset;
	Offset.QuadPart = 0;
	unsigned long Pos = SetFilePointer(Handle, Offset.LowPart,
	&Offset.HighPart, FILE_BEGIN);
	if (Pos != Offset.LowPart)
	{
	   CloseHandle(Handle);
	   Synchronize(&PosError);
	   return void();
	}

	BYTE *Block = new BYTE[block_size];
	DWORD BytesToRead;

	ProcessThreadPtr = new Write_T(Event, false);
	while (true){
		if (Terminated) {
			 Synchronize(&Finished);
			break;
		}

		bool ReadBlock = ReadFile(Handle,Block, block_size, &BytesToRead, NULL);
		if (ReadBlock == false || BytesToRead != block_size) {
			Synchronize(&RBError);
			break;
		}
		Event -> SetEvent();
		while(Event -> WaitFor(0) == wrSignaled){
			Sleep(50);
		}
	}
	CloseHandle(Handle);
	ProcessThreadPtr -> Terminate();
	delete ProcessThreadPtr;
}

//---------------------------------------------------------------------------
