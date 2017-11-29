#include "interpreter.h"
#include <iostream>
#include <sstream>

Interpreter::Interpreter() {
	binary = "";									//	Assign binary conversion from hex to bin cpp
	outMsg = "";									//	Output message
	wordCount = 0;									//	Track number of words from from parser
	wordTotal = 0;
	i = 0;
	j = 0;
	binMap1 = {};									// Use 2 bitMaps to separate binary conversion into 2 binary-converted fields, ex:
	binMap2 = {};									// 1A022DFE -> 1A02: Map1 = 0001101000000010 and 2DFE: Map2 = 0010110111111110
	outFile.open("new_test_data.log", ios_base::app);
}

Interpreter::~Interpreter() {}

void Interpreter::list_of_data(list<MemoryData*> dataList) {
	ptr = dataList.front();
	while (true) {
		// INITIALIZE FIRST NODE DATA
		list_address = data.getAddress();
		list_data = data.getData();
		list_line_number = data.getLineNumber;
		list_time = data.getTime();
		
		// IF FIRST NODE ADDRESS IS COMMAND CALL AND WORD DATA IS ZERO
		if ((list_data == "00000000") && ((list_address == "40000810") || (list_address == "40000C18"))) {
			message_output_rw(list_line_number, 0);
			dataList.pop_front();
			ptr = dataList.front();

			// INCREMENT NODE
			list_data = data.getData();
			list_address = data.getAddress();
			list_line_number = data.getLineNumber();
		}

		// IF FIRST NODE ADDRESS IS COMMAND CALL AND WORD DATA IS NOT ZERO
		else if ((list_data != "00000000") && ((list_address == "40000810") || (list_address == "40000C18"))) {
			// CONVERT HEX TO DECIMAL FOR WORD TOTAL
			stringstream stream;
			stream << list_data;
			stream >> hex >> wordTotal;

			// OUTPUT LINE NUMBER, COMMAND CALL, AND WORD TOTAL
			message_output_rw(list_line_number, wordTotal);

			// POP COMMAND CALL NODE AND MOVE TO ACTUAL DATA
			dataList.pop_front();
			ptr = dataList.front();

			// INITIALIZE ADDRESS, BINARY, AND LINE NUMBER OF CURRENT NODE
			list_address = data.getAddress();	
			list_data = data.getData();			
			list_line_number = data.getLineNumber();
			binary = hex_to_bin(list_data);

			// POP CURRENT NODE TO COMPARE ADDRESS WITH NEXT NODE
			dataList.pop_front();				
			ptr = dataList.front();				
			list_address_2 = data.getAddress();

			if (list_address < list_address_2) {
				bin_parser_inorder(binary, 0, wordTotal, lineNum);
				wordCount = 2;

				while (list_address <= "4000086B") {
					list_address = data.getAddress();
					list_data = data.getData();
					binary = hex_to_bin(list_data);
					list_line_number = data.getLineNumber();

					bin_parser_inorder(binary, wordCount, wordTotal, lineNum);
					dataList.pop_front();
					ptr = dataList.front();
				}
			}
			else if (list_address > list_address_2) {
				wordCount = wordTotal;
				bin_parser_revorder(binary, wordCount, lineNum);
				
				while (list_address >= "40000818") {
					list_address = data.getAddress();
					list_data = data.getData();
					binary = hex_to_bin(list_data);
					list_line_number = data.getLineNumber();

					bin_parser_revorder(binary, wordCount, lineNum);
					dataList.pop_front();
					ptr = dataList.front();
				}
			}
		}
	}
}

// Hex to Binary Conversion
#pragma region
string Interpreter::hex_to_bin(string hexadecimal)
{
	string bin = "";
	for (int i = 0; i < hexadecimal.length(); i++)
	{
		switch (hexadecimal.at(i))
		{
		case '0': bin.append("0000");
			break;
		case '1': bin.append("0001");
			break;
		case '2': bin.append("0010");
			break;
		case '3': bin.append("0011");
			break;
		case '4': bin.append("0100");
			break;
		case '5': bin.append("0101");
			break;
		case '6': bin.append("0110");
			break;
		case '7': bin.append("0111");
			break;
		case '8': bin.append("1000");
			break;
		case '9': bin.append("1001");
			break;
		case 'A': bin.append("1010");
			break;
		case 'B': bin.append("1011");
			break;
		case 'C': bin.append("1100");
			break;
		case 'D': bin.append("1101");
			break;
		case 'E': bin.append("1110");
			break;
		case 'F': bin.append("1111");
			break;
		default:
			break;
		}
	}
	return bin;
}
#pragma endregion

// If the addresses are in ascending value order, then output in order
int Interpreter::bin_parser_inorder(string binary, int wordCount, int wordTotal, int lineNum) {
	while (true) {
		int x = wordCount;

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
int Interpreter::bin_parser_revorder(string binary, int wordCount, int lineNum) {
	while (true) {
		int x = wordCount;

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
#pragma region
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
#pragma endregion

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