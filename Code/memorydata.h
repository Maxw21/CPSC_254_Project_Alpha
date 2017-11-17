#ifndef _MEMORYDATA_H
#define _MEMORYDATA_H

#include <string>
using namespace std;

class MemoryData {
public:
	MemoryData();
	MemoryData(string, string, string, string, int);
	~MemoryData();
	void setTime(string);
private:
	string address;
	string data;
	string time;
	string size;
	string cycle;
	int lineNumber;
};

#endif