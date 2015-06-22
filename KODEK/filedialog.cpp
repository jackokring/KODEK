#include "stdafx.h"
#include <afxwin.h>

wchar_t * fileDefault;

CString FileOpen(bool load)
{
	// szFilters is a text string that includes two file name filters: 
	// "*.my" for "MyType Files" and "*.*' for "All Files."
	TCHAR szFilters[] = _T("Any Files (*.*)|*.*||");
	int flags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
	fileDefault = (fileDefault == NULL) ? _T("") : fileDefault;
	TCHAR * fileDef = fileDefault;
	if (load) {
		int flags = OFN_FILEMUSTEXIST;
	}
	
	// Create an Open dialog; the default file name extension is ".my".
	CFileDialog fileDlg(load, NULL, fileDef,
		flags, szFilters);

	// Display the file dialog. When user clicks OK, fileDlg.DoModal()  
	// returns IDOK. 
	if (fileDlg.DoModal() == IDOK)
	{
		CString pathName = fileDlg.GetPathName();

		// Implement opening and reading file in here. 

		//Change the window's title to the opened file's title.
		CString fileName = fileDlg.GetFileTitle();

		fileDlg.GetSafeOwner()->SetWindowText(fileName);
		return pathName;
	} else return NULL;
}