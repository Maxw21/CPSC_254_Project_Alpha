#ifndef _INTERPRETER_H
#define _INTERPRETER_H

#include <string>
#include <map>
#include <fstream>
using namespace std;

class Interpreter {
public:
	Interpreter();
	~Interpreter();
	int bin_parser_inorder(string, int, int);
	int bin_parser_revorder(string, int);
	string bin_to_message(int, map<int, char>);
	void message_output_rw(int, int);

private:
	char* binary;
	string outMsg;
	int wordCount;
	int wordTotal;
	int i;
	int j;
	map<int, char> binMap1;
	map<int, char> binMap2;
	ofstream outFile;
	void message_output_fields(int, int, string);
};

#endif