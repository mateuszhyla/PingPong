//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PingPong.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPingPongWindow *PingPongWindow;

int x = +3, y = +3;

//---------------------------------------------------------------------------
__fastcall TPingPongWindow::TPingPongWindow(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPingPongWindow::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{

  if(Key==0x57) LeftPaddleUp->Enabled=true;
  if(Key==0x53) LeftPaddleDown->Enabled=true;
  if(Key==VK_UP) RightPaddleUp->Enabled=true;
  if(Key==VK_DOWN) RightPaddleDown->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TPingPongWindow::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{

  if(Key==0x57) LeftPaddleUp->Enabled=false;
  if(Key==0x53) LeftPaddleDown->Enabled=false;
  if(Key==VK_UP) RightPaddleUp->Enabled=false;
  if(Key==VK_DOWN) RightPaddleDown->Enabled=false;
}

//---------------------------------------------------------------------------

void __fastcall TPingPongWindow::LeftPaddleUpTimer(TObject *Sender)
{
if(LeftPaddle->Top > WallTop->Top + WallTop->Height)
{
LeftPaddle->Top -= 10;
}
}
//---------------------------------------------------------------------------
void __fastcall TPingPongWindow::LeftPaddleDownTimer(TObject *Sender)
{
if((LeftPaddle->Top + LeftPaddle->Height) < WallBottom->Top )
{
LeftPaddle->Top += 10;
}
}
//---------------------------------------------------------------------------
void __fastcall TPingPongWindow::RightPaddleUpTimer(TObject *Sender)
{
if(RightPaddle->Top > WallTop->Top + WallTop->Height)
{
RightPaddle->Top -= 10;
}
}
//---------------------------------------------------------------------------
void __fastcall TPingPongWindow::RightPaddleDownTimer(TObject *Sender)
{
if((RightPaddle->Top + RightPaddle->Height) < WallBottom->Top )
{
RightPaddle->Top += 10;
}
}
//---------------------------------------------------------------------------
void __fastcall TPingPongWindow::BallTimerTimer(TObject *Sender)
{

Ball->Left+=x; Ball->Top+=y;


if (Ball->Top <= WallTop->Top + WallTop->Height) y=-y;
if ((Ball->Top + Ball->Height) >= WallBottom->Top) y=-y;

if ((Ball->Top <= LeftPaddle->Top + LeftPaddle->Height)
&& (Ball->Top + Ball->Height >= LeftPaddle->Top)
&& (Ball->Left <= LeftPaddle->Left + LeftPaddle->Width))
{
playSound();
x=-x;
}

if ((Ball->Top <= RightPaddle->Top + RightPaddle->Height)
&& (Ball->Top + Ball->Height >= RightPaddle->Top)
&& (Ball->Left + Ball->Width >= RightPaddle->Left))
{
playSound();
x=-x;
}
}
//---------------------------------------------------------------------------

void __fastcall TPingPongWindow::playSound()
{
sndPlaySound("snd/paddleHit1.wav", SND_ASYNC);
}

