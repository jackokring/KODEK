
// KODEKDlg.h : header file
//

#pragma once
#include "stdafx.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "resource.h"

class CKODEKDlgAutoProxy;

// CKODEKDlg dialog
class CKODEKDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CKODEKDlg);
	friend class CKODEKDlgAutoProxy;

// Construction
public:
	CKODEKDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CKODEKDlg();

// Dialog Data
	enum { IDD = IDD_KODEK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	CKODEKDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;
	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
//	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDecompress();
	afx_msg void OnBnClickedCompress();
	afx_msg void OnEnChangeSeed();
	CButton compressButton;
	CButton decompressButton;
	CEdit seedEntry;
	CProgressCtrl progressBar;
	CButton aboutButton;
	afx_msg void OnBnClickedAbout();

	static enum state here;

	bool code(CHAR* file, LONG* val);
	bool decode(CHAR* file, LONG* val);
	bool close();
	bool name(CHAR* buffer, LONG* len, LONG* val);
	bool stream(CHAR* buffer, LONG* len, LONG* val);
};
