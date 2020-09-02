HFONT select_font(HWND hwnd)
{
HDC hdc=GetDC(hwnd);      // display device context of owner window
CHOOSEFONT cf;            // common dialog box structure
static LOGFONT lf;        // logical font structure
static DWORD rgbCurrent;  // current text color
HFONT hfont, hfontPrev;
DWORD rgbPrev;


// Initialize CHOOSEFONT
ZeroMemory(&cf, sizeof(cf));
//lf.lfEscapement=70;
cf.lStructSize = sizeof (cf);
cf.hwndOwner = hwnd;
cf.lpLogFont = &lf;
cf.lpLogFont->lfEscapement=70;
cf.rgbColors = rgbCurrent;
cf.Flags = CF_SCREENFONTS | CF_EFFECTS;

	if (ChooseFont(&cf)==TRUE)
	{
	hfont = CreateFontIndirect(cf.lpLogFont);
	hfontPrev =(HFONT)SelectObject(hdc,hfont);
	SendMessage(hwnd,WM_SETFONT,(UINT)hfont,0);

	rgbCurrent= cf.rgbColors;
	rgbPrev = SetTextColor(hdc, rgbCurrent);
	//TextOut(hdc,200,200,"568568568568",12);
	//SetBkMode(hdc,1);
	
	}

return hfont;
}
//------------------------------------------------------------------------

ULONG color(HWND hwnd)
{
CHOOSECOLOR cc;                 // common dialog box structure  
static COLORREF acrCustClr[16]; // array of custom colors 

HBRUSH hbrush;                  // brush handle
static DWORD rgbCurrent;        // initial color selection

// Initialize CHOOSECOLOR 
ZeroMemory(&cc, sizeof(CHOOSECOLOR));
cc.lStructSize = sizeof(CHOOSECOLOR);
cc.hwndOwner = hwnd;
cc.lpCustColors = (LPDWORD) acrCustClr;
cc.rgbResult = rgbCurrent;

cc.Flags = CC_FULLOPEN | CC_RGBINIT;
 
			if (ChooseColor(&cc)==TRUE) 
			{
				hbrush = CreateSolidBrush(cc.rgbResult);
				rgbCurrent = cc.rgbResult; 
				//InvalidateRect(hwnd,0,1);
				//SendMessage(hwnd,WM_PAINT,0,0);
			}

return cc.rgbResult;
}
//------------------------------------------------------------------------
UINT print_dialog(HWND hwnd)
{
PRINTDLG pd;


// Initialize PRINTDLG
ZeroMemory(&pd, sizeof(PRINTDLG));
pd.lStructSize = sizeof(PRINTDLG);
pd.hwndOwner   = hwnd;
pd.hDevMode    = NULL;      // Don't forget to free or store hDevMode.
pd.hDevNames   = NULL;      // Don't forget to free or store hDevNames.
pd.Flags       = PD_USEDEVMODECOPIESANDCOLLATE | PD_RETURNDC; 
pd.nCopies     = 1;
pd.nFromPage   = 0xFFFF;  
pd.nToPage     = 0xFFFF; 
pd.nMinPage    = 1; 
pd.nMaxPage    = 0xFFFF; 

UINT error_code=1;

			if (PrintDlg(&pd)==TRUE)
			{

				// GDI calls to render output. 

				// Delete DC when done.
				DeleteDC(pd.hDC);
			}
			else 
			error_code=GetLastError();



return error_code; 
}
//----------------------------------------------------------------
/*
int find_text(HWND hwnd,UINT message,long lparam)
{

UINT uFindReplaceMsg;  // message identifier for FINDMSGSTRING  

uFindReplaceMsg = RegisterWindowMessage(FINDMSGSTRING);


FINDREPLACE fr;       // common dialog box structure
         
CHAR szFindWhat[80];  // buffer receiving string
HWND hdlg = NULL;     // handle of Find dialog box
 
// Initialize FINDREPLACE
ZeroMemory(&fr, sizeof(FINDREPLACE));
fr.lStructSize = sizeof(FINDREPLACE);
fr.hwndOwner = hwnd;
fr.lpstrFindWhat = szFindWhat;
fr.wFindWhatLen = 80;
fr.Flags = 0;

hdlg = FindText(&fr);

LPFINDREPLACE lpfr;
 
		if (message == uFindReplaceMsg)
		{ 

    // Get pointer to FINDREPLACE structure from lParam.

    lpfr = (LPFINDREPLACE)lparam;

    // If the FR_DIALOGTERM flag is set, 
    // invalidate the handle identifying the dialog box. 

		if (lpfr->Flags & FR_DIALOGTERM)
		{ 
        hdlg = NULL; 
        return 0; 
        } 

    // If the FR_FINDNEXT flag is set, 
    // call the application-defined search routine
    // to search for the requested string. 

    if (lpfr->Flags & FR_FINDNEXT) 
      SearchFile(lpfr->lpstrFindWhat,(BOOL)(lpfr->Flags & FR_DOWN),(BOOL)(lpfr->Flags & FR_MATCHCASE)); 

    return 0; 
 
		}

} */
//-------------------------------------------------------------------
OPENFILENAME open_file(HWND hwnd)
{

OPENFILENAME ofn;       // common dialog box structure
char szFile[260];       // buffer for filename
HANDLE hf;              // file handle

// Initialize OPENFILENAME
ZeroMemory(&ofn, sizeof(OPENFILENAME));
ofn.lStructSize = sizeof(OPENFILENAME);
ofn.hwndOwner = hwnd;
ofn.lpstrFile = szFile;
ofn.nMaxFile = sizeof(szFile);
ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
ofn.nFilterIndex = 1;
ofn.lpstrFileTitle = NULL;
ofn.nMaxFileTitle = 0;
ofn.lpstrInitialDir = NULL;
ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

// Display the Open dialog box. 

if (GetOpenFileName(&ofn)==TRUE) 
    hf = CreateFile(ofn.lpstrFile,GENERIC_READ,0,(LPSECURITY_ATTRIBUTES)NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,(HANDLE)NULL);

return ofn;
}
//---------------------------------------------------------------------


