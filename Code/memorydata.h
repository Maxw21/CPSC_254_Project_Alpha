#ifndef _MEMORYDATA_H
#define _MEMORYDATA_H

#include <string>
using namespace std;

class MemoryData {
public:
	MemoryData();
	MemoryData(string, string, string, string, string, int);
	~MemoryData();
	void setTime(string);
	string getAddress();
	string getData();
	string getTime();
	int getLineNumber();
	string getCycle();
	string getSize();

private:
	string address;
	string data;
	string cycle;
	string size;
	string time;
	int lineNumber;
};

#endif