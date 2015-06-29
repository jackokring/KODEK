// Security.cpp : implementation file
//

#include "stdafx.h"
#include "KODEK.h"
#include "Security.h"
#include "afxdialogex.h"


// Security dialog

IMPLEMENT_DYNAMIC(Security, CDialogEx)

Security::Security(CWnd* pParent /*=NULL*/)
	: CDialogEx(Security::IDD, pParent)
{

}

Security::~Security()
{
}

void Security::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Security, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &Security::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &Security::OnBnClickedOk)
END_MESSAGE_MAP()


// Security message handlers


void Security::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void Security::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
