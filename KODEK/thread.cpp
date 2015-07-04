#include "stdafx.h"
#include "KODEKDlg.h"
#include "thread.h"
#include "Enumerations.h"
#include "fileIO.h"

char * buff;
long * lenref;//keep *lenref zero until done

static CKODEKDlg * dlg;

static enum state what() {
	return dlg->here;
}

static void showProgress(int percent) {
	progress(&dlg->progressBar, percent);
}

static void decompFileName()  {
	/* Decompress the file name. And leave the seed below the filename. 
	Use buff [256] and a temp idx. set lenref to exit. */
	*lenref = 1;//unlock
	return;//prevent tri thread test
}

static void showError() {
	/* Show error dialog when there is a checksum or other error. */
	error(dlg);
}

static void compFile() {
	/* Compress a file including a filename header.
	Use fileDefault as name. */
	showError();
}

static void decompFile() {
	/* Decompress a file minus the filename header. 
	Use fileDefault as name. */
	showError();
}

static void stream() {
	/* Decompress a file minus the filename header.
	Use buff [lenref] and a temp idx. Set lenref to actual on exit. */
	showError();
}

void bgTask(CKODEKDlg *that) {
	/* In reality ACTION_DECOMPRESS must wait for DECOMPRESS_FILENAME to finish */
	dlg = that;//for easy modular functions
	switch (what()) {
	//case START: break;
	case ACTION_COMPRESS: compFile(); break;
	case ACTION_DECOMPRESS: decompFile(); break;
	case ACTION_STREAM: stream(); break;
	//case END: break;
	//case TERM: break;
	//case ERRORBOX: break;
	case DECOMPRESS_FILENAME: decompFileName(); break;
	}
}