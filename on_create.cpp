long __stdcall on_create(HWND hwnd,UINT message,UINT wparam,long lparam)
{
create_menu(hwnd);
HFONT hfont=create_font(hwnd);


HWND hw=0;
int X,Y,W,H;
DWORD style=WS_VISIBLE|WS_CHILD|WS_BORDER;

X=10;Y=30;W=100;H=100;
hw=CreateWindow("button","button",style,X,Y,W,H,hwnd,(HMENU)10,0,0);
SendMessage(hw,WM_SETFONT,(UINT)hfont,0);

X=150;Y=30;W=100;H=100;
hw=CreateWindow("listbox","listbox",style,X,Y,W,H,hwnd,(HMENU)20,0,0);
SendMessage(hw,WM_SETFONT,(UINT)hfont,0);

X=300;Y=30;W=100;H=100;
hw=CreateWindow("combobox","combobox",style,X,Y,W,H,hwnd,(HMENU)30,0,0);
SendMessage(hw,WM_SETFONT,(UINT)hfont,0);


X=450;Y=30;W=100;H=100;
hw=CreateWindow("static","static",style|SS_ELLIPSISMASK,X,Y,W,H,hwnd,(HMENU)40,0,0);
SendMessage(hw,WM_SETFONT,(UINT)hfont,0);

X=600;Y=30;W=100;H=100;
hw=CreateWindow("edit","edit",style,X,Y,W,H,hwnd,(HMENU)50,0,0);
SendMessage(hw,WM_SETFONT,(UINT)hfont,0);

style=WS_VISIBLE|WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN;
X=1310;Y=230;W=200;H=100;
//CreateWindow("1223","Main",style,X,Y,W,H,0,0,0,0);

CreateWindow("trackbar","edit",style,10,10,100,100,hwnd,(HMENU)50,0,0);



TVITEM tvitem;
tvitem.mask=TVIF_TEXT;
tvitem.pszText="item";
tvitem.cchTextMax=lstrlen(tvitem.pszText);

TV_INSERTSTRUCT tv_ins;

tv_ins.item=tvitem;
tv_ins.hParent=TVI_ROOT;

SendMessage(hw,TVM_INSERTITEM,(WPARAM)0,(long)&tvitem);



//InitCommonControls();
hw=CreateWindow("SysTreeView32","tree",WS_VISIBLE|WS_CHILD|TVS_HASLINES,10,200,100,100,hwnd,(HMENU)10000,0,0);

AddItemToTree(hw,"Item_1",1);
AddItemToTree(hw,"Item_1-1",2);

AddItemToTree(hw,"Item_2",1);

AddItemToTree(hw,"Item_3",1);
AddItemToTree(hw,"Item_3-1",2);


AddItemToTree(hw,"Item_4",1);
AddItemToTree(hw,"Item_5",1);


hw=CreateWindow("SysTreeView32","tree",WS_VISIBLE|WS_CHILD|TVS_HASLINES,10,200,100,100,hwnd,(HMENU)10000,0,0);


CreateAToolBar1(hwnd,1234,0);


long __stdcall	w_m_function(HWND,UINT,WPARAM,LPARAM);
long (__stdcall*oldproc)					(HWND,UINT,WPARAM,LPARAM);

	oldproc=(long (__stdcall*)(HWND,UINT,WPARAM,LPARAM))
	SetWindowLong(hwnd,GWL_WNDPROC,(long)w_m_function);
	


return 0;
}