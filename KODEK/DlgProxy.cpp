
// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "KODEK.h"
#include "DlgProxy.h"
#include "KODEKDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKODEKDlgAutoProxy

IMPLEMENT_DYNCREATE(CKODEKDlgAutoProxy, CCmdTarget)

CKODEKDlgAutoProxy::CKODEKDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CKODEKDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CKODEKDlg)))
		{
			m_pDialog = reinterpret_cast<CKODEKDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CKODEKDlgAutoProxy::~CKODEKDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CKODEKDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CKODEKDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CKODEKDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Note: we add support for IID_IKODEK to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {6B64E0EC-AB4F-4805-819B-8B8AF3FC3786}
static const IID IID_IKODEK =
{ 0x6B64E0EC, 0xAB4F, 0x4805, { 0x81, 0x9B, 0x8B, 0x8A, 0xF3, 0xFC, 0x37, 0x86 } };

BEGIN_INTERFACE_MAP(CKODEKDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CKODEKDlgAutoProxy, IID_IKODEK, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {590EAB33-FC7A-42E4-B010-45975C44C06F}
IMPLEMENT_OLECREATE2(CKODEKDlgAutoProxy, "KODEK.Application", 0x590eab33, 0xfc7a, 0x42e4, 0xb0, 0x10, 0x45, 0x97, 0x5c, 0x44, 0xc0, 0x6f)


// CKODEKDlgAutoProxy message handlers


STDMETHODIMP CKODEKDlgAutoProxy::code(CHAR* file, LONG* val)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}


STDMETHODIMP CKODEKDlgAutoProxy::decode(CHAR* file, LONG* val)
{
	AFX_MANAGE_STATE(AfxGetAppModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}
