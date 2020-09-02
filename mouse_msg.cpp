
long __stdcall on_mouse(HWND hwnd,UINT message,UINT wparam,long lparam)

{
	if(message==WM_RBUTTONDOWN)
	{
	//MessageBox(hwnd,"WM_RBUTTONDOWN=0x0204",0,0);
	}
	else if(message==WM_LBUTTONDOWN)
	{

	char text[32];
	int x=(unsigned short)lparam;
	int y=HIWORD(lparam);
	HDC hdc=GetDC(hwnd);

	sprintf(text,"(%d , %d)",x,y);
	//TextOut(hdc,0,0,text,strlen(text));

	HWND h=0;
	
	pixel_thick(hdc,x,y,10,cc_global);

	h=GetDlgItem(hwnd,10);
	SendMessage(h,WM_SETTEXT,strlen(text),(long)text);

	h=GetDlgItem(hwnd,20);
	SendMessage(h,LB_ADDSTRING,0,(long)text);

	h=GetDlgItem(hwnd,30);
	SendMessage(h,CB_ADDSTRING,0,(long)text);

	h=GetDlgItem(hwnd,40);
	SendMessage(h,WM_SETTEXT,strlen(text),(long)text);

	h=GetDlgItem(hwnd,50);
	SendMessage(h,WM_SETTEXT,strlen(text),(long)text);

	//SetPixel(hdc,x,y,RGB(250,0,0));
	}
	else if(message==WM_MOUSEMOVE)
	{
		if(wparam==MK_LBUTTON)
		{
		int x=(unsigned short)lparam;
		int y=HIWORD(lparam);
		HDC hdc=GetDC(hwnd);

		
		pixel_thick(hdc,x,y,10,cc_global);
		}

	}
	
return 0;
}