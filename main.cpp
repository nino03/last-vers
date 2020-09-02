#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <commdlg.h>
#include <commctrl.h>
//SetTimer(hwnd,timer Id-234,100,0);
//KillTimer(hwnd,timer id 234);
//SYSTEMTIME st
//GetSistemTime(&st)
#pragma comment(lib,"comctl32.lib")

#include "toolbar.cpp"
#include "defines.h"
#include "globals.h"
#include "dialogs.cpp"
#include "functions.cpp"
#include "paint.cpp"
#include "mouse_msg.cpp"
#include "kbd_msg.cpp"
#include "timer.cpp"
#include "cmd_msg.cpp"
#include "on_create.cpp"
#include "on_destroy_msg.cpp"

//----------------------------------------------------------------
long __stdcall w_m_function(HWND hwnd,UINT message,UINT wparam,long lparam)
{
	switch(message)
	{
		case WM_CREATE:
		on_create(hwnd,message,wparam,lparam);
		break;
		
		case WM_COMMAND:
		on_cmd(hwnd,message,wparam,lparam);
		break;
		
		case WM_LBUTTONDBLCLK:
		on_mouse(hwnd,message,wparam,lparam);
		break;

		case WM_PAINT:
		on_paint(hwnd,message,wparam,lparam);
		break;

		case WM_KEYDOWN:
		on_kbd(hwnd,message,wparam,lparam);
		break;

		case WM_DESTROY:
		exit(1);
		break;
	}

return DefWindowProc(hwnd,message,wparam,lparam);
}
//----------------------------------------------------------------

//int __stdcall WinMain(HINSTANCE,HINSTANCE,char *,int)
void main()
{
HWND hwnd=0;
int X,Y,W,H;
ULONG style=0;

WNDCLASS wc;
ZeroMemory(&wc,sizeof(WNDCLASS));

wc.style=CS_DBLCLKS;
wc.lpfnWndProc=(WNDPROC)&w_m_function;
wc.lpszClassName="myclass";
wc.hbrBackground=(HBRUSH)CreateSolidBrush(RGB(200,200,200));
wc.hIcon=(HICON)LoadImage(0,"c:\\1.ico",IMAGE_ICON,16,16,LR_LOADFROMFILE);

	if(RegisterClass(&wc)==0)
	{
	MessageBox(hwnd,"RegisterClass error",0,0);
	return;
	}


//mtavari fanjara:
style=WS_VISIBLE|WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN;
X=10;Y=30;W=700;H=500;
hwnd=CreateWindow("myclass","Main",style,X,Y,W,H,0,0,0,0);

	
MSG msg;
int s=1;
	while(s!=0)
	{
	s=GetMessage(&msg,0,0,0);
	TranslateMessage(&msg);
	DispatchMessage(&msg);
	}
}