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
extern fstream rwStream;

class Parser {
public:
	Parser(string);
	~Parser();
	list<MemoryData*> getList();
	void parseData();
	
private:
	string fileName;
	list<MemoryData*> dataList;
};

#endif