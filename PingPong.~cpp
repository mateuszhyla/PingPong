//---------------------------------------------------------------------------
#include <iostream>
#include <vcl.h>
#pragma hdrstop
#include "PingPong.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;

TPingPongWindow *PingPongWindow;

int x = +3, y = +3;
int player1Counter = 0, player2Counter = 0;

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
playSound("paddleHit1");
x=-x;
}

if (Ball->Left + Ball->Width < LeftPaddle->Left)
{
playSound("lost");
BallTimer->Enabled = false;
player2Counter++;
Player2Score->Caption = player2Counter;
resetPositions();
}

if ((Ball->Top <= RightPaddle->Top + RightPaddle->Height)
&& (Ball->Top + Ball->Height >= RightPaddle->Top)
&& (Ball->Left + Ball->Width >= RightPaddle->Left))
{
playSound("paddleHit1");
x=-x;
}

if (Ball->Left > RightPaddle->Left + RightPaddle->Width)
{
playSound("lost");
BallTimer->Enabled = false;
player1Counter++;
Player1Score->Caption = player1Counter;
resetPositions();
}

}
//---------------------------------------------------------------------------

void __fastcall TPingPongWindow::playSound(string type)
{
string path = "snd/" + type + ".wav";
TCHAR tcharFileName[ 256 ] = { '\0' };
strcpy( tcharFileName, path.c_str() );
sndPlaySound(tcharFileName, SND_ASYNC);
}

void __fastcall TPingPongWindow::resetPositions()
{
LeftPaddle->Left = 30; LeftPaddle->Top = 200;
RightPaddle->Left = 704; RightPaddle->Top = 200;

Ball->Left = 361; Ball->Top = 224;
Sleep(2000);
BallTimer->Enabled = true;
}

