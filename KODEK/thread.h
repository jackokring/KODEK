//dialogs
extern bool FileOpen(bool load);
extern CString fileDefault;
extern void error(CKODEKDlg *that);

//algorithm
extern long * access;
extern void compress(int x);
extern int decompress();

//buffers
extern char * buff;
extern long * lenref;//keep *lenref zero until done
extern void progress(CProgressCtrl *myCtrl, int pos);