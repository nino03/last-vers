long __stdcall on_cmd(HWND hwnd,UINT message,UINT wparam,long lparam)
{
	HWND h;
		switch(LOWORD(wparam))
		{
		
		case 200: hfont_global=select_font(hwnd);
			SendMessage(hwnd,WM_SETFONT,(UINT)hfont_global,0);
		break;
		case 100: cc_global=color(hwnd);
			SetClassLong(hwnd,GCL_HBRBACKGROUND,(LONG)CreateSolidBrush(cc_global));
			InvalidateRect(hwnd,0,1);
			SendMessage(hwnd,WM_PAINT,0,0);
		break;
		case 300: hfont_global=select_font(hwnd);break;
		case 400: cc_global=color(hwnd);break;
		case 500: print_dialog(hwnd);break;
		case 700: open_file(hwnd);break;

		case 501:
		{
		ULONG thrd_id=0;
	
	struct THRD_DATA thrd_data;

	thrd_data.tm=0;
	thrd_data.hwnd=hwnd;
	thrd_data.pt.x=0;
	thrd_data.pt.y=0;

	void *thrd_h=CreateThread(0,0,(PTHREAD_START_ROUTINE)thrd_timer_funct,(void *)&thrd_data,0,&thrd_id);

	
	thrd_data.tm=0;
	thrd_data.hwnd=hwnd;
	thrd_data.pt.x=0;
	thrd_data.pt.y=20;
	thrd_h=CreateThread(0,0,(PTHREAD_START_ROUTINE)thrd_timer_funct,(void *)&thrd_data,0,&thrd_id);

	

		}
		break;


		case 777:

			h=GetDlgItem(hwnd,10);
			DestroyWindow(h);

			h=GetDlgItem(hwnd,20);
			DestroyWindow(h);

			h=GetDlgItem(hwnd,30);
			DestroyWindow(h);

			h=GetDlgItem(hwnd,40);
			DestroyWindow(h);

			h=GetDlgItem(hwnd,50);
			DestroyWindow(h);

			CreateWindow("button","Sin",WS_VISIBLE|WS_CHILD,30,20,50,50,hwnd,(HMENU)67,0,0);

			CreateWindow("button","Parabola",WS_VISIBLE|WS_CHILD,100,20,50,50,hwnd,(HMENU)68,0,0);

			CreateWindow("button","Clean",WS_VISIBLE|WS_CHILD,500,20,50,50,hwnd,(HMENU)69,0,0);


		break;

		case 67:
		{
		float y;//,a=4,b=5,c=6;
			for(float x=-150;x<150;x+=0.1)
			{
			y=50*sin(0.1*x+9);
			//y=a*x*x+b*x+c;
			//SetPixel(GetDC(hwnd),200+x,200+y,RGB(x*y+30,x*y+78,x*y));
			SetPixel(GetDC(hwnd),200+x,200+y,RGB(0,0,0));
			}
		}
		
		break;

		case 68:
		{
		float y;//,a=4,b=5,c=6;

		

			for(float x=-100;x<100;x+=0.1)
			{
			y=-0.01*x*x;
			//y=a*x*x+b*x+c;
			
			SetPixel(GetDC(hwnd),200+x,200+y,RGB(0,0,0));
			}
		}
		break;

		case 69:

		InvalidateRect(hwnd,0,1);

		break;




		case 132:
		WinExec("F:\\Projs\\Main\\HELP\\winhlp32.exe",1);
		break;

		case 111:
			RECT r;
			GetClientRect(hwnd,&r);
			HRGN hrgn=CreateEllipticRgn(r.left,r.top,r.right,r.bottom);
//			SelectClipRgn(hdc,);
			SetWindowRgn(hwnd,hrgn,1);

			int w,h;
			w=r.right-r.left;
			h=r.bottom-r.top;
			FrameRgn(GetDC(hwnd),hrgn,CreateSolidBrush(RGB(200,200,40)),w,h);
		break;
		
		}


return 0;
}