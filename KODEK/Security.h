#pragma once


// Security dialog

class Security : public CDialogEx
{
	DECLARE_DYNAMIC(Security)

public:
	Security(CWnd* pParent = NULL);   // standard constructor
	virtual ~Security();

// Dialog Data
	enum { IDD = IDD_SECURITY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
