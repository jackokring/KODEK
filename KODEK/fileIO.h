#include <iostream>
#include <fstream>
using namespace std;
#pragma once
class fileIO
{
public:
	fileIO(bool read, CString name);
	~fileIO();
	int get();
	void put(long x);//but 32 bit
	void setSize(long long x);
	long long getPos();
	streampos size;
	fstream io;
	bool reading;
	bool open;
};

