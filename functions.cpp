UINT create_menu(HWND hwnd)
{
HMENU hmenu=CreateMenu();
	if(!hmenu)
	return GetLastError();

HMENU hmenu_popup_window=CreatePopupMenu();
AppendMenu(hmenu,MF_POPUP,(UINT_PTR)hmenu_popup_window,"&Window");
AppendMenu(hmenu_popup_window,MF_STRING,100,"&Change window color");
AppendMenu(hmenu_popup_window,MF_STRING,200,"&Change window font");

HMENU hmenu_popup_wc=CreatePopupMenu();
AppendMenu(hmenu,MF_POPUP,(UINT_PTR)hmenu_popup_wc,"&Windows Controls");
AppendMenu(hmenu_popup_wc,MF_STRING,102,"&Static");




HMENU hmenu_popup_options=CreatePopupMenu();
AppendMenu(hmenu, MF_POPUP, (UINT_PTR)hmenu_popup_options, "&Common Dialogs");
AppendMenu(hmenu_popup_options,MF_STRING,300,"&Choose Font");
AppendMenu(hmenu_popup_options,MF_STRING,400,"&Choose Color");
AppendMenu(hmenu_popup_options,MF_STRING,500,"&Print");
AppendMenu(hmenu_popup_options,MF_STRING,600,"&Find Text");
AppendMenu(hmenu_popup_options,MF_STRING,700,"&Open File");
SetMenu(hwnd,hmenu);

HMENU hmenu_popup_regions=CreatePopupMenu();
AppendMenu(hmenu, MF_POPUP, (UINT_PTR)hmenu_popup_regions, "&Regions");
AppendMenu(hmenu_popup_regions,MF_STRING,111,"&Circle");
AppendMenu(hmenu_popup_regions,MF_STRING,222,"&Round Rect");
AppendMenu(hmenu_popup_regions,MF_STRING,333,"&Rect");


HMENU hmenu_popup_math=CreatePopupMenu();
AppendMenu(hmenu,MF_POPUP,(UINT_PTR)hmenu_popup_math,"&Mathematics");
AppendMenu(hmenu_popup_math,MF_STRING,1322,"&Arithmetic");

HMENU hpopup=CreatePopupMenu();
InsertMenu(hpopup,MF_BYPOSITION,MF_BYPOSITION|MF_STRING,777,(char *)"Graphical Functions");
AppendMenu(hmenu_popup_math,MF_STRING|MF_POPUP,(UINT)hpopup,"&Geometry");


HMENU hmenu_popup_paint=CreatePopupMenu();
AppendMenu(hmenu,MF_POPUP,(UINT_PTR)hmenu_popup_paint,"&Paint");
AppendMenu(hmenu_popup_paint,MF_STRING,4444,"&Paint");

HMENU hmenu_popup_thr=CreatePopupMenu();
AppendMenu(hmenu,MF_POPUP,(UINT_PTR)hmenu_popup_thr,"&Threads");
AppendMenu(hmenu_popup_thr,MF_STRING,501,"&Start");
//AppendMenu(hmenu_popup_thr,MF_STRING,502,"&Pause");




HMENU hmenu_popup_about=CreatePopupMenu();
AppendMenu(hmenu,MF_POPUP,(UINT_PTR)hmenu_popup_about,"&About");
AppendMenu(hmenu_popup_about,MF_STRING,132,"&Help");






return 0;
}

//-----------------------------------------------------------
HFONT create_font(HWND hwnd)
{
HFONT hfont;
hfont=CreateFont(15,5,0,0,FW_BOLD,0,0,0,ANSI_CHARSET, 
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
      DEFAULT_PITCH | FF_DONTCARE,"Tahoma");
SendMessage(hwnd,WM_SETFONT,(UINT)hfont,0);
return hfont;
}

//---------------------------------------------------------------
void pixel_thick(HDC hdc,int x,int y,int p,ULONG rgb)
{


	for( int j=-p;j<p;j++)
	{    
		for( int g=-p;g<p;g++)
		{	
		SetPixel(hdc,x+g,y+j,rgb);
		}
	}
}

//---------------------------------------------------------------

ULONG thrd_function(void *data)
{
SYSTEMTIME st;

char str[255];
		while(1)
		{
			GetSystemTime(&st);
			sprintf(str,"%d	st.wYear- %d	st.wMonth-  %d st.Day-  %d	st.wHour-  %d	st.wMinute-  %d	st.wSecond-  %d	st.wMilliseconds-");
		TextOut(0,0,0,str,255);
		}


}



/*
---Dragging the Tree-View Item----

  


// Main_OnMouseMove - drags an item in a tree-view control,  
//     highlighting the item that is the target. 
// hwndParent - handle of the parent window 
// hwndTV - handle of the tree-view control 
// xCur and yCur - x- and y-coordinates of the mouse cursor 
void Main_OnMouseMove(HWND hwndParent, HWND hwndTV, LONG xCur, LONG yCur) 
{ 
    HTREEITEM htiTarget;  // handle of target item 
    TV_HITTESTINFO tvht;  // hit test information 
 
    if (g_fDragging) { 

 
        // Drag the item to the current position of the mouse cursor. 
        ImageList_DragMove(xCur, yCur); 
 
        // Find out if the cursor is on the item. If it is, highlight 
        // the item as a drop target. 
        tvht.pt.x = xCur; 
        tvht.pt.y = yCur; 
        if ((htiTarget = TreeView_HitTest(hwndTV, &tvht)) != NULL) { 
            TreeView_SelectDropTarget(hwndTV, htiTarget); 
        } 
    } 
    return; 
} 
 */

//------------------------Adding Tree-View Items---------------------------------------

HTREEITEM AddItemToTree(HWND hwndTV, LPSTR lpszItem, int nLevel) 

{ 
    TV_ITEM tvi; 
    TV_INSERTSTRUCT tvins; 
    static HTREEITEM hPrev = (HTREEITEM) TVI_FIRST; 
    static HTREEITEM hPrevRootItem = NULL; 
    static HTREEITEM hPrevLev2Item = NULL; 
    HTREEITEM hti; 
 
    tvi.mask = TVIF_TEXT | TVIF_IMAGE 
        | TVIF_SELECTEDIMAGE | TVIF_PARAM; 
 
    // Set the text of the item. 
    tvi.pszText = lpszItem; 
    tvi.cchTextMax = lstrlen(lpszItem); 
 
    // Assume the item is not a parent item, so give it a 

    // document image. 
    tvi.iImage = 0; 
    tvi.iSelectedImage = 0; 
 
    // Save the heading level in the item's application-defined 
    // data area. 
    tvi.lParam = (LPARAM) nLevel; 
 
    tvins.item = tvi; 
    tvins.hInsertAfter = hPrev; 
 
    // Set the parent item based on the specified level. 
    if (nLevel == 1) 
        tvins.hParent = TVI_ROOT; 
    else if (nLevel == 2) 
        tvins.hParent = hPrevRootItem; 
    else 

        tvins.hParent = hPrevLev2Item; 
 
    // Add the item to the tree-view control. 
    hPrev = (HTREEITEM) SendMessage(hwndTV, TVM_INSERTITEM, 0, 
         (LPARAM) (LPTV_INSERTSTRUCT) &tvins); 
 
    // Save the handle of the item. 
    if (nLevel == 1) 
        hPrevRootItem = hPrev; 
    else if (nLevel == 2) 
        hPrevLev2Item = hPrev; 
 
    // The new item is a child item. Give the parent item a 
    // closed folder bitmap to indicate it now has child items. 

    if (nLevel > 1) { 
        hti = TreeView_GetParent(hwndTV, hPrev); 
        tvi.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE; 
        tvi.hItem = hti; 
        tvi.iImage =0; 
        tvi.iSelectedImage = 0; 
        TreeView_SetItem(hwndTV, &tvi); 
    } 
 
    return hPrev; 
}

/*
//-------------------tool bar-------------------------

HIMAGELIST g_hImageList = NULL;

HWND CreateSimpleToolbar(HWND hWndParent)
{
    // Declare and initialize local constants.
    const int ImageListID    = 0;
    const int numButtons     = 3;
    const int bitmapSize     = 16;
    
    const DWORD buttonStyles = BTNS_AUTOSIZE;

    // Create the toolbar.
    HWND hWndToolbar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL, 
                                      WS_CHILD | TBSTYLE_WRAPABLE, 0, 0, 0, 0, 
                                      hWndParent, NULL, g_hInst, NULL);
        
    if (hWndToolbar == NULL)
        return NULL;

    // Create the image list.
    g_hImageList = ImageList_Create(bitmapSize, bitmapSize,   // Dimensions of individual bitmaps.
                                    ILC_COLOR16 | ILC_MASK,   // Ensures transparent background.
                                    numButtons, 0);

    // Set the image list.
    SendMessage(hWndToolbar, TB_SETIMAGELIST, 
                (WPARAM)ImageListID, 
                (LPARAM)g_hImageList);

    // Load the button images.
    SendMessage(hWndToolbar, TB_LOADIMAGES, 
                (WPARAM)IDB_STD_SMALL_COLOR, 
                (LPARAM)HINST_COMMCTRL);

    // Initialize button info.
    // IDM_NEW, IDM_OPEN, and IDM_SAVE are application-defined command constants.
    
    TBBUTTON tbButtons[numButtons] = 
    {
        { MAKELONG(STD_FILENEW,  ImageListID), IDM_NEW,  TBSTATE_ENABLED, buttonStyles, {0}, 0, (INT_PTR)L"New" },
        { MAKELONG(STD_FILEOPEN, ImageListID), IDM_OPEN, TBSTATE_ENABLED, buttonStyles, {0}, 0, (INT_PTR)L"Open"},
        { MAKELONG(STD_FILESAVE, ImageListID), IDM_SAVE, 0,               buttonStyles, {0}, 0, (INT_PTR)L"Save"}
    };

    // Add buttons.
    SendMessage(hWndToolbar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
    SendMessage(hWndToolbar, TB_ADDBUTTONS,       (WPARAM)numButtons,       (LPARAM)&amp;tbButtons);

    // Resize the toolbar, and then show it.
    SendMessage(hWndToolbar, TB_AUTOSIZE, 0, 0); 
    ShowWindow(hWndToolbar,  TRUE);
    
    return hWndToolbar;
}

/*

HWND CreateAToolBar(HWND hwndParent) 
{ 
    HWND hwndTB; 
    TBADDBITMAP tbab; 
    TBBUTTON tbb[3]; 
    char szBuf[16]; 
    int iCut, iCopy, iPaste; 
 
    // Ensure that the common control DLL is loaded. 
    InitCommonControls(); 
 
    // Create a toolbar that the user can customize and that has a 

    // tooltip associated with it. 
    hwndTB = CreateWindowEx(0, TOOLBARCLASSNAME,(LPSTR)NULL, 
        WS_CHILD|TBSTYLE_TOOLTIPS|CCS_ADJUSTABLE, 
        0,0,0,0,hwndParent,(HMENU)62,0,NULL); 
 
    // Send the TB_BUTTONSTRUCTSIZE message, which is required for 
    // backward compatibility. 
    SendMessage(hwndTB, TB_BUTTONSTRUCTSIZE, 
        (WPARAM) sizeof(TBBUTTON), 0); 
 
    // Add the bitmap containing button images to the toolbar. 

    tbab.hInst =0; 
    tbab.nID   = IDB_BUTTONS; 
    SendMessage(hwndTB, TB_ADDBITMAP, (WPARAM) NUM_BUTTON_BITMAPS, 
        (WPARAM) &tbab); 
 
    // Add the button strings to the toolbar. 
    LoadString(0, IDS_CUT, (LPSTR) &szBuf,100); 
    iCut = SendMessage(hwndTB, TB_ADDSTRING, 0, (LPARAM) (LPSTR) szBuf); 
 
    LoadString(0,IDS_COPY,(LPSTR)&szBuf,100); 
    iCopy = SendMessage(hwndTB, TB_ADDSTRING, (WPARAM) 0, 
        (LPARAM) (LPSTR) szBuf); 

 
    LoadString(0, IDS_PASTE, (LPSTR) &szBuf,100); 
    iPaste = SendMessage(hwndTB, TB_ADDSTRING, (WPARAM) 0, 
        (LPARAM) (LPSTR) szBuf); 
 
    // Fill the TBBUTTON array with button information, and add the 
    // buttons to the toolbar. 
    tbb[0].iBitmap = BMP_CUT; 
    tbb[0].idCommand = IDM_CUT; 
    tbb[0].fsState = TBSTATE_ENABLED; 
    tbb[0].fsStyle = TBSTYLE_BUTTON; 
    tbb[0].dwData = 0; 
    tbb[0].iString = iCut; 
 
    tbb[1].iBitmap = BMP_COPY; 

    tbb[1].idCommand = IDM_COPY; 
    tbb[1].fsState = TBSTATE_ENABLED; 
    tbb[1].fsStyle = TBSTYLE_BUTTON; 
    tbb[1].dwData = 0; 
    tbb[1].iString = iCopy; 
 
    tbb[2].iBitmap = BMP_PASTE; 
    tbb[2].idCommand = IDM_PASTE; 
    tbb[2].fsState = TBSTATE_ENABLED; 
    tbb[2].fsStyle = TBSTYLE_BUTTON; 
    tbb[2].dwData = 0; 
    tbb[2].iString = iPaste; 
 
    SendMessage(hwndTB, TB_ADDBUTTONS, (WPARAM) NUM_BUTTONS, 
        (LPARAM) (LPTBBUTTON) &tbb); 

 
    ShowWindow(hwndTB, SW_SHOW); 
    return hwndTB; 
} 
 */