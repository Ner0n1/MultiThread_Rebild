//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Write_T::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
int i=0;
__fastcall Write_T::Write_T(TEvent *Event, bool CreateSuspended)
	: TThread(CreateSuspended), Event(Event)
{
	FreeOnTerminate = true;
}
//---------------------------------------------------------------------------
void __fastcall Write_T::Execute()
{
	while (true)
	{
		 if (Terminated)
		 {
			break;
		 }
		if (Event -> WaitFor(0) == wrSignaled)
		{
			i++;
			Synchronize(&BlocksCount);
			Sleep(20);
			Event -> ResetEvent();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall Write_T::BlocksCount()
{
	Form1 -> Label5 -> Caption = UnicodeString(i);
}
