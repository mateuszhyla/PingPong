//---------------------------------------------------------------------------

#ifndef PingPongH
#define PingPongH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TPingPongWindow : public TForm
{
__published:	// IDE-managed Components
        TShape *Background;
        TImage *LeftPaddle;
        TTimer *LeftPaddleUp;
        TTimer *LeftPaddleDown;
        TImage *RightPaddle;
        TTimer *RightPaddleDown;
        TTimer *RightPaddleUp;
        TImage *Ball;
        TTimer *BallTimer;
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall LeftPaddleUpTimer(TObject *Sender);
        void __fastcall LeftPaddleDownTimer(TObject *Sender);
        void __fastcall RightPaddleUpTimer(TObject *Sender);
        void __fastcall RightPaddleDownTimer(TObject *Sender);
        void __fastcall BallTimerTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPingPongWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPingPongWindow *PingPongWindow;
//---------------------------------------------------------------------------
#endif
