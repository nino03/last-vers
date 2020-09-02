
long __stdcall on_kbd(HWND hwnd,UINT message
					,UINT wparam,long lparam)
{

	switch(wparam)
	{
	case VK_RETURN:	break;
	case VK_TAB:	break;
	case VK_ESCAPE:exit(1);break;	
	
	}
return 0;
}