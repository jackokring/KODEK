
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
	
protected:
	HRESULT code(CHAR* file, LONG* val);

	enum
	{
		dispidstream = 5L,
		dispidname = 4L,
		dispidclose = 3L,
		dispiddecode = 2L,
		dispidcode = 1L
	};
	HRESULT decode(CHAR* file, LONG* val);
	HRESULT close();
	HRESULT name(CHAR* buffer, LONG* len, LONG* val);
	HRESULT stream(CHAR* buffer, LONG* len, LONG* val);
};

