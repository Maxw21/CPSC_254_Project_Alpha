#ifndef _PARSER_H
#define _PARSER_H

#include "memorydata.h"
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

extern ifstream dataFile;

class Parser {
public:
	Parser();
	~Parser();
	void makeList();
	list<MemoryData*> getList();
	
private:
	list<MemoryData*> dataList;
};

#endif