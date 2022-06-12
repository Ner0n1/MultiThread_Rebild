//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <windows.h>
#include <string.h>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int bl = 4;
const WCHAR *name = L"\\\\.\\C:";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Edit1 -> Text = UnicodeString(bl);
	Edit2 -> Text = UnicodeString(name);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Button1 -> Enabled = false;
	Button2 -> Enabled = true;
	Edit1 -> Enabled = false;
	Edit2 -> Enabled = false;
	wchar_t *disk = (Edit2 -> Text).c_str();
	ReadThreadPtr = new Read_T(disk,false);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	ReadThreadPtr->Terminate();
	Button1 -> Enabled = true;
	Button2 -> Enabled = false;
	Edit1 -> Enabled = true;
	Edit2 -> Enabled = true;
}
//---------------------------------------------------------------------------
