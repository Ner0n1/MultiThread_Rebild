//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class Write_T : public TThread
{
private:
	TEvent* Event;
protected:
	void __fastcall Execute();
	void __fastcall BlocksCount();
public:
	__fastcall Write_T(TEvent* Event,bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
