// About.cpp : implementation file
//

#include "stdafx.h"
#include "KODEK.h"
#include "About.h"
#include "afxdialogex.h"


// About dialog

IMPLEMENT_DYNAMIC(About, CDialogEx)

About::About(CWnd* pParent /*=NULL*/)
	: CDialogEx(About::IDD, pParent)
{

}

About::~About()
{
}

void About::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(About, CDialogEx)
	ON_BN_CLICKED(IDOK_ABOUT, &About::OnClickedOK)
END_MESSAGE_MAP()


// About message handlers


void About::OnClickedOK()
{
	CDialogEx::OnOK();
}
