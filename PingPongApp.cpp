//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("PingPong.cpp", PingPongWindow);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TPingPongWindow), &PingPongWindow);
                 ShowMessage(
                 "This is basic PingPong multiplayer Simulator \n\nPlayer 1 controls: \n Move up: w \n Move down: s \n\nPlayer 2 controls: \n Move up: up \n Move down: down \n\n To move the ball press enter. To continue - press enter" );
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
