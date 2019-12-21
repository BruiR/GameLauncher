//---------------------------------------------------------------------------

#ifndef UnitInfoH
#define UnitInfoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TFormInfo : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageClose;
	void __fastcall ImageCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormInfo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormInfo *FormInfo;
//---------------------------------------------------------------------------
#endif
