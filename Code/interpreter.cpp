#include "interpreter.h"
#include <iostream>

Interpreter::Interpreter() {
	binary = "";									//	Assign binary conversion from hex to bin cpp
	outMsg = "";									//	Output message
	wordCount = 0;									//	Track number of words from from parser
	i = 0;
	j = 0;
	binMap1 = {};									// Use 2 bitMaps to separate binary conversion into 2 binary-converted fields, ex:
	binMap2 = {};									// 1A022DFE -> 1A02: Map1 = 0001101000000010 and 2DFE: Map2 = 0010110111111110
	outFile.open("new_test_data.log", ios_base::app);
}

Interpreter::~Interpreter() {}

// If the addresses are in ascending value order, then output in order
int Interpreter::bin_parser_inorder(string binary, int wordCount, int wordTotal) {
	while (true) {
		int x = wordCount;
		int lineNum = 0;

		for (i = 15, j = 0; i > -1; i--, j++) {
			binMap1[i] = binary.at(j);
		}
		if (x == 0 || x == 1 || x == 4 || x == 5 || x == 10 || x == 15 || x == 22 || x == 32 || x == 37 || x == 38 || x == 40 || x == 41) {
			outMsg = bin_to_message(x, binMap1);
			message_output_fields(lineNum, x, outMsg);
		}
		x++;

		for (i = 15, j = 16; i > -1; i--, j++) {
			binMap2[i] = binary.at(j);
		}
		if (x == 0 || x == 1 || x == 4 || x == 5 || x == 10 || x == 15 || x == 22 || x == 32 || x == 37 || x == 38 || x == 40 || x == 41) {
			outMsg = bin_to_message(x, binMap2);
			message_output_fields(lineNum, x, outMsg);
		}
		x++;

		if (x >= wordTotal)
			outFile << endl;

		return x;
	}
}

// If the addresses are in descending value order, then output in reverse order
int Interpreter::bin_parser_revorder(string binary, int wordCount) {
	while (true) {
		int x = wordCount;
		int lineNum = 0;

		for (i = 15, j = 16; i > -1; i--, j++) {
			binMap2[i] = binary.at(j);
		}
		if (x == 0 || x == 1 || x == 4 || x == 5 || x == 10 || x == 15 || x == 22 || x == 32 || x == 37 || x == 38 || x == 40 || x == 41) {
			outMsg = bin_to_message(x, binMap2);
			message_output_fields(lineNum, x, outMsg);
		}
		x--;

		for (i = 15, j = 0; i > -1; i--, j++) {
			binMap1[i] = binary.at(j);
		}
		if (x == 0 || x == 1 || x == 4 || x == 5 || x == 10 || x == 15 || x == 22 || x == 32 || x == 37 || x == 38 || x == 40 || x == 41) {
			outMsg = bin_to_message(x, binMap1);
			message_output_fields(lineNum, x, outMsg);
		}
		if (x <= 0)
			outFile << endl;
		x--;

		return x;
	}
}

// Output messages depending on word number, see assignment
string Interpreter::bin_to_message(int wordCount, map<int, char> binMap) {
	switch (wordCount) {
	case 0: {
		if (binMap[14] == '1' && binMap[13] == '1')
			return "Rec_Ctrl = 3 (processing & recording)";
		else if (binMap[14] == '1' && binMap[13] == '0')
			return "Rec_Ctrl = 2 (no processing)";
		else if (binMap[14] == '0' && binMap[13] == '0')
			return "Rec_Ctrl = 0 (no recording)";
		else
			return "Rec_Ctrl = 1 (unknown)";
		break;
	}
	case 1: {
		if (binMap[15] == '1') {
			if (binMap[14] == '1' && binMap[13] == '0')
				return "Cmd_Type = 6 (Type C)";
			else if (binMap[14] == '0' && binMap[13] == '1')
				return "Cmd_Type = 5 (Type B)";
			else if (binMap[14] == '0' && binMap[13] == '0')
				return "Cmd_Type = 4 (Type A)";
			else
				return "Cmd_Type = 7 (unknown)";
		}
		else if (binMap[15] == '0')
			if (binMap[14] == '1' && binMap[13] == '1')
				return "Cmd_Type = 3 (unknown)";
			else if (binMap[14] == '1' && binMap[13] == '0')
				return "Cmd_Type = 2 (unknown)";
			else if (binMap[14] == '0' && binMap[13] == '1')
				return "Cmd_Type = 1 (unknown)";
			else
				return "Cmd_Type = 0 (unknown)";
		break;
	}
	case 4: {
		if (binMap[0] == '1')
			return "Rec_Raw = 1 (enable)";
		else
			return "Rec_Raw = 0 (disable)";
		break;
	}
	case 5: {
		int total = 0;
		for (int i = 0; i < 7; i++) {
			if (binMap[i] == '1')
				total += (pow(2, i));
		}
		return ("Cmd_ID = " + to_string(total));
	}
	case 10: {
		int total = 0;
		for (int i = 11; i < 16; i++) {
			if (binMap[i] == '1')
				total += (pow(2, (i - 11)));
		}
		return ("Num_Responses = " + to_string(total));
	}
	case 15: {
		if (binMap[2] == '1')
			return "Reset_Enable = 1 (enable)";
		else
			return "Reset_Enable = 0 (disable)";
	}
	case 22: {
		if (binMap[3] == '1')
			return "Direction = 1 (left)";
		else
			return "Direction = 0 (right)";
	}
	case 32: {
		int total = 0;
		for (int i = 0; i < 15; i++) {
			if (binMap[i] == '1')
				total += (pow(2, i));
		}
		return ("Num_Samples = " + to_string(total));
	}
	case 37: {
		if (binMap[15] == '1')
			return "Parity = 1 (odd)";
		else
			return "Parity = 0 (even)";
	}
	case 38: {
		if (binMap[14] == '1')
			return "Test = 1 (enable)";
		else
			return "Test = 0 (disable)";
	}
	case 40: {
		if (binMap[7] == '1')
			return "Ctrl_Enable = 1 (enable)";
		else
			return "Ctrl_Enable = 0 (disable)";
	}
	case 41: {
		int total = 0;
		for (int i = 8; i < 15; i++) {
			if (binMap[i] == '1')
				total += (pow(2, (i - 8)));
		}
		return ("Code = " + to_string(total));
	}
	}
}

// Output formatting depending on line number, word number, field names, and descriptions
void Interpreter::message_output_fields(int lineNum, int wordNum, string message) {
	outFile << "Line " << lineNum << ": Word " << wordNum << ": " << message << endl;
}

// Output formatting depending on line number, word number, and read or write command
void Interpreter::message_output_rw(int lineNum, int wordNum) {
	if (wordNum == 0) {
		outFile << "Line " << lineNum << ": <<RD/WR StoD/DtoS>> command: 0 words" << endl << endl;
	}
	else
		outFile << "Line " << lineNum << ": <<RD/WR StoD/DtoS>> command: " << wordNum << " words" << endl;
}