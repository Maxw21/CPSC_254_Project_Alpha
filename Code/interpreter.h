#ifndef _INTERPRETER_H
#define _INTERPRETER_H

#include <string>
#include <map>
using namespace std;

class Interpreter {
public:
	Interpreter();
	~Interpreter();
	int bin_parser(string, int);
	string bin_to_message(int, map<int, char>);

private:
	char* binary;
	string outMsg;
	int wordCount;
	int wordTotal;
	int i;
	int j;
	map<int, char> binMap1;
	map<int, char> binMap2;
	void message_output(int, string);
};

#endif