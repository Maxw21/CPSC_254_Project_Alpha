#ifndef _INTERPRETER_H
#define _INTERPRETER_H

#include <string>
#include <map>
#include <fstream>
#include <list>
#include "memorydata.h"
#include "field_name_commands.h"
using namespace std;

class Interpreter {
public:
	Interpreter();
	~Interpreter();
	int bin_parser_inorder(string, int, int, int);
	int bin_parser_revorder(string, int, int);
	void list_of_data(list<MemoryData*>);
	void message_output_rw(int, int);

private:
	string binary;
	string outMsg;
	string list_address;
	string list_address_2;
	string list_data;
	string list_time;
	int list_line_number;
	int wordCount;
	int wordTotal;
	int i;
	int j;
	map<int, char> binMap1;
	map<int, char> binMap2;
	ofstream outFile;
	MemoryData data;
	void message_output_fields(int, int, string);
	string hex_to_bin(string);
};

#endif