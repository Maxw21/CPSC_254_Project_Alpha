#ifndef _INTERPRETER_H
#define _INTERPRETER_H

#include <string>
using namespace std;

class Interpreter {
public:
	Interpreter();
	~Interpreter();

	string word_fld_name(int);

	string word_0_dscr(int);
	string word_1_dscr(int);
	string word_4_15_38_40_dscr(int);
	string word_22_dscr(int);
	string word_37_dscr(int);

private:
	char* binConv;
	int binVal;
	int wordNumber;
	string fieldName;
	string description;
};

#endif