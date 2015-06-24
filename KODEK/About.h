#pragma once


// About dialog

class About : public CDialogEx
{
	DECLARE_DYNAMIC(About)

public:
	About(CWnd* pParent = NULL);   // standard constructor
	virtual ~About();

// Dialog Data
	enum { IDD = IDABOUT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedOK();
	afx_msg void OnBnClickedWww();
};
