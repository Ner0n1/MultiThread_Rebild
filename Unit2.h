//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class Read_T : public TThread
{
private:
	class Write_T* ProcessThreadPtr;
	TEvent* Event;
	const WCHAR *name;
protected:
	void __fastcall Execute();
	void __fastcall SizeError();
	void __fastcall DiskError();
	void __fastcall PosError();
	void __fastcall Finished();
	void __fastcall RBError();
public:
	__fastcall Read_T(wchar_t *disk,bool CreateSuspended);
};
BYTE *Block;
//---------------------------------------------------------------------------
#endif
