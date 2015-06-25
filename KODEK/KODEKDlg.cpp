
// KODEKDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KODEK.h"
#include "KODEKDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include "About.h"
#include "Error.h"

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

static enum state { START, ACTION_COMPRESS, ACTION_DECOMPRESS, ACTION_COMPRESS_STREAM, ACTION_STREAM, END, TERM, ERRORBOX };
static enum state here = END;

extern void bgTask(CKODEKDlg *that);//can call error function

static bool run(CKODEKDlg *that, enum state newHere);//forward

static UINT BackThread(LPVOID pParam) {
	CKODEKDlg * gui = (CKODEKDlg *)pParam;
	bgTask(gui);
	run(gui, END);//the thread has completed
	return 0;
}

static void progress(CProgressCtrl *myCtrl, int pos) {//MUST pass controls by reference
	int nLower, nUpper;
	myCtrl->GetRange(nLower, nUpper);
	myCtrl->SetPos((nUpper - nLower) * pos / 100);
}

void error(CKODEKDlg *that) {
	run(that, ERRORBOX);
}

static bool run(CKODEKDlg *that, enum state newHere) {
	if (newHere == ERRORBOX) {
		newHere = END;
		Error dlg;
		dlg.DoModal();
	}
	if (here != END && newHere == START) {
		return true;//not allowed!!
	}
	if(here != TERM) here = newHere;
	if (that != NULL) {
		if (here == END) {
			progress(&that->progressBar, 0);
			that->GetSafeOwner()->SetWindowText(_T("KODEK"));
		}
		that->seedEntry.EnableWindow(here == END);
		that->compressButton.EnableWindow(here == END);
		that->decompressButton.EnableWindow(here == END);
	}
	if (here == TERM) return true;//exit don't do anything
	if (here != END && here != START) {
		AfxBeginThread(BackThread, that);
	}
	return false;//OK
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
	run(this, TERM);
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
	run(this, TERM);
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

extern bool FileOpen(bool load);
extern CString fileDefault;

//The functions below should thread the while loop
void CKODEKDlg::OnBnClickedDecompress()
{
	if(run(this, START)) return;
	fileDefault = _T("test.cpp");//TODO: where name inside, then after name decode process
	if (FileOpen(false)) {
		run(this, ACTION_DECOMPRESS);
		return;
	}
	run(this, END);
}

void CKODEKDlg::OnBnClickedCompress()
{
	if(run(this, START)) return;
	fileDefault = _T("");
	if (FileOpen(true)) {
		run(this, ACTION_COMPRESS);
		return;
	}
	run(this, END);
}

void CKODEKDlg::OnBnClickedAbout()
{
	About dlg;
	dlg.DoModal();
}

//if(run(this, START)) return; is the lock, and ...

bool CKODEKDlg::code(CHAR* file, LONG* val)
{
	// TODO: Add your dispatch handler code here

	return true;
}

bool CKODEKDlg::decode(CHAR* file, LONG* val)
{
	// TODO: Add your dispatch handler code here

	return true;
}


bool CKODEKDlg::close()
{
	//if (run(this, TERM)) return;

	return true;
}


bool CKODEKDlg::streamCode(CHAR* file, LONG* val)
{
	// TODO: Add your dispatch handler code here

	return true;
}


bool CKODEKDlg::stream(CHAR* buffer, LONG* len, LONG* val)
{
	// TODO: Add your dispatch handler code here

	return true;
}
