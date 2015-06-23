#pragma once


// Error dialog

class Error : public CDialogEx
{
	DECLARE_DYNAMIC(Error)

public:
	Error(CWnd* pParent = NULL);   // standard constructor
	virtual ~Error();

// Dialog Data
	enum { IDD = IDD_ERROR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
