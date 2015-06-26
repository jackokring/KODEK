#include "stdafx.h"
#include "fileIO.h"
#include <iostream>
#include <fstream>
using namespace std;

fileIO::fileIO(bool read, CString name)
{
	if (read) {
		ifstream io(name, ios::in | ios::binary | ios::ate);
		if (!io.good()) {
			open = false;
			return;
		}
		open = true;
		reading = true;
	} else {
		ofstream io(name, ios::out | ios::binary | ios::ate | ios::trunc);
		if (!io.good()) {
			open = false;
			return;
		}
		open = true;
		reading = false;
	}
	if (read) {
		io.seekg(0, ios::end);
		size = io.tellg();//set for writing later and elsewhere
		io.seekg(sizeof(int) - (size % 4), ios::end);
	}
}

int fileIO::get() {
	if (!reading) return 0;
	io.seekg(-(long) sizeof(int), ios::beg);
	streampos tmp = io.tellg();
	int x = 0;
	for (int i = 0; i < 4; i++) {
		char y;
		io.get(y);
		x <<= 8;
		x |= y;
	}
	io.seekg(tmp, ios::beg);
	return x;
}

void fileIO::setSize(long long x) {
	size = x;
}

void fileIO::put(long x) {
	if (reading) return;
	for (int i = 0; i < 4; i++) {
		if (io.tellp() >= size) return;
		char y = (x >> 24) & 255;
		io.put(y);
		x <<= 8;
	}
}

fileIO::~fileIO()
{
	if (open) io.close();//flush
}
