
// DlgProxy.h: header file
//

#pragma once

class CKODEKDlg;


// CKODEKDlgAutoProxy command target

class CKODEKDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CKODEKDlgAutoProxy)

	CKODEKDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CKODEKDlg* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

// Implementation
protected:
	virtual ~CKODEKDlgAutoProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CKODEKDlgAutoProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	STDMETHOD(code)(CHAR* file, LONG* val);
	STDMETHOD(decode)(CHAR* file, LONG* val);
};

