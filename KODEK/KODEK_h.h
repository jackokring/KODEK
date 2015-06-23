

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Jun 23 16:05:06 2015
 */
/* Compiler settings for KODEK.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __KODEK_h_h__
#define __KODEK_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IKODEK_FWD_DEFINED__
#define __IKODEK_FWD_DEFINED__
typedef interface IKODEK IKODEK;

#endif 	/* __IKODEK_FWD_DEFINED__ */


#ifndef __KODEK_FWD_DEFINED__
#define __KODEK_FWD_DEFINED__

#ifdef __cplusplus
typedef class KODEK KODEK;
#else
typedef struct KODEK KODEK;
#endif /* __cplusplus */

#endif 	/* __KODEK_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __KODEK_LIBRARY_DEFINED__
#define __KODEK_LIBRARY_DEFINED__

/* library KODEK */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_KODEK;

#ifndef __IKODEK_DISPINTERFACE_DEFINED__
#define __IKODEK_DISPINTERFACE_DEFINED__

/* dispinterface IKODEK */
/* [uuid] */ 


EXTERN_C const IID DIID_IKODEK;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("6B64E0EC-AB4F-4805-819B-8B8AF3FC3786")
    IKODEK : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IKODEKVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IKODEK * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IKODEK * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IKODEK * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IKODEK * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IKODEK * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IKODEK * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IKODEK * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IKODEKVtbl;

    interface IKODEK
    {
        CONST_VTBL struct IKODEKVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IKODEK_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IKODEK_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IKODEK_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IKODEK_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IKODEK_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IKODEK_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IKODEK_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IKODEK_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_KODEK;

#ifdef __cplusplus

class DECLSPEC_UUID("590EAB33-FC7A-42E4-B010-45975C44C06F")
KODEK;
#endif
#endif /* __KODEK_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


