#ifndef _INTERPRETER_H
#define _INTERPRETER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <fstream>
#include <list>
#include <sstream>
#include <math.h>
#include "memorydata.h"
using namespace std;

class Interpreter {
public:
	Interpreter();
	~Interpreter();
	int bin_parser_inorder(string, int, int, int);
	int bin_parser_revorder(string, int, int);
	string bin_to_message(int, map<int, char>);
	void list_of_data(list<MemoryData*>);
	void message_output_rw(int, int, string, string);

private:
	string binary;
	string outMsg;
	string list_address;
	string list_address_comp;
	string list_address_2;
	string list_address_2_comp;
	string list_data;
	string list_time;
	string list_size;
	string cycle;
	stringstream timeConverter;
	stringstream byteConverter;
	string bitConverter;
	int byteSize;
	bool gotTime;
	string timeSize;
	double timeCount;
	double RsTdTime;
	double RsTdByte;
	double RdTsTime;
	double RdTsByte;
	double WsTdTime;
	double WsTdByte;
	double WdTsTime;
	double WdTsByte;
	int list_line_number;
	int wordCount;
	int wordTotal;
	int i;
	int j;
	map<int, char> binMap1;
	map<int, char> binMap2;
	ofstream outFile;
	MemoryData* data;
	void message_output_fields(int, int, string);
	string hex_to_bin(string);
	void timeBit(string, string, string, string);
};

#endif
