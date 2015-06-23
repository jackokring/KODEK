// Error.cpp : implementation file
//

#include "stdafx.h"
#include "KODEK.h"
#include "Error.h"
#include "afxdialogex.h"


// Error dialog

IMPLEMENT_DYNAMIC(Error, CDialogEx)

Error::Error(CWnd* pParent /*=NULL*/)
	: CDialogEx(Error::IDD, pParent)
{

}

Error::~Error()
{
}

void Error::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Error, CDialogEx)
	ON_BN_CLICKED(IDOK, &Error::OnBnClickedOk)
END_MESSAGE_MAP()


// Error message handlers


void Error::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
