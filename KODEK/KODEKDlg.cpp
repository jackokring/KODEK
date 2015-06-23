
// KODEKDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KODEK.h"
#include "KODEKDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKODEKDlg dialog


IMPLEMENT_DYNAMIC(CKODEKDlg, CDialogEx);

CKODEKDlg::CKODEKDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CKODEKDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CKODEKDlg::~CKODEKDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

static bool running = false;//process active?

static void progress(CProgressCtrl *myCtrl, int pos) {//MUST pass controls by reference
	int nLower, nUpper;
	myCtrl->GetRange(nLower, nUpper);
	myCtrl->SetPos((nUpper - nLower) * pos / 100);
}

static void run(CKODEKDlg *that, bool active) {
	running = !active;//opposite of control active
	that->seedEntry.EnableWindow(active);
	that->compressButton.EnableWindow(active);
	that->decompressButton.EnableWindow(active);
	if (active) progress(&that->progressBar, 0);
}

void CKODEKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDCOMPRESS, compressButton);
	DDX_Control(pDX, IDDECOMPRESS, decompressButton);
	DDX_Control(pDX, IDSEED, seedEntry);
	DDX_Control(pDX, IDPERCENT, progressBar);
	DDX_Control(pDX, IDABOUT, aboutButton);
}

BEGIN_MESSAGE_MAP(CKODEKDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDDECOMPRESS, &CKODEKDlg::OnBnClickedDecompress)
	ON_BN_CLICKED(IDCOMPRESS, &CKODEKDlg::OnBnClickedCompress)
	ON_BN_CLICKED(IDABOUT, &CKODEKDlg::OnBnClickedAbout)
END_MESSAGE_MAP()


// CKODEKDlg message handlers

BOOL CKODEKDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	SendDlgItemMessage(IDABOUT, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)m_hIcon);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKODEKDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKODEKDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CKODEKDlg::OnClose()
{
	run(this, true);
	if (CanExit())
		CDialogEx::OnClose();
}

//void CKODEKDlg::OnOK()
//{
//	if (CanExit())
//		CDialogEx::OnOK();
//}

void CKODEKDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CKODEKDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

extern CString FileOpen(bool load);
extern wchar_t * fileDefault;

static CString named;

//The functions below should thread the while loop
void CKODEKDlg::OnBnClickedDecompress()
{
	run(this, false);
	fileDefault = _T("test");
	if ((named = FileOpen(false)) == "") {
		run(this, true);
		return;
	}
	while (running);
	run(this, true);
}


void CKODEKDlg::OnBnClickedCompress()
{
	run(this, false);
	fileDefault = NULL;
	if ((named = FileOpen(true)) == "") {
		run(this, true);
		return;
	}
	while (running);
	run(this, true);
}


void CKODEKDlg::OnBnClickedAbout()
{
	// TODO: Add your control notification handler code here
}
