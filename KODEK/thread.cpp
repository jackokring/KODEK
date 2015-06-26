#include "stdafx.h"
#include "KODEKDlg.h"
#include "thread.h"
#include "Enumerations.h"
#include "fileIO.h"

char * buff;
long * lenref;

void bgTask(CKODEKDlg *that) {
	if (that->here == DECOMPRESS_FILENAME) return;//prevent tri thread test
	/* In reality ACTION_DECOMPRESS must wait for DECOMPRESS_FILENAME to finish */
	error(that);
}