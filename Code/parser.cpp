#include "parser.h"
#include <vector>

Parser::Parser() { }

Parser::~Parser() { }

void Parser::parseData() {
	string dataString;
	int lineNumber = 1;
	MemoryData* newData;
	string dataStringTok[4] = { "" };

	dataFile.open("test_data.log", ios::in);

	if (!dataFile.is_open()) {
		exit(1);
	}
	dataFile.ignore(82);
	while (!dataFile.eof()) {
		dataFile >> dataStringTok[0];
		if (dataStringTok[0] == "40000810") {
			dataFile >> dataStringTok[1];
			dataFile.ignore(11);
			dataFile >> dataStringTok[2];
			dataFile.ignore(53);
			dataFile >> dataStringTok[3];
			dataFile.ignore(54);
			newData = new MemoryData(dataStringTok[0], dataStringTok[1], dataStringTok[2], dataStringTok[3], lineNumber);
			dataList.push_back(newData);
		}
		else if (dataStringTok[0] == "40000C18") {
			dataFile >> dataStringTok[1];
			dataFile.ignore(11);
			dataFile >> dataStringTok[2];
			dataFile.ignore(53);
			dataFile >> dataStringTok[3];
			dataFile.ignore(54);
			newData = new MemoryData(dataStringTok[0], dataStringTok[1], dataStringTok[2], dataStringTok[3], lineNumber);
			dataList.push_back(newData);
		}
		else if (dataStringTok[0].compare("IACK=7") == 0) { dataFile.ignore(144); }
		else if (stoll(dataStringTok[0], 0, 16) >= stoll("40000C20", 0, 16) && stoll(dataStringTok[0], 0, 16) <= stoll("4000101C", 0, 16)) {
			dataFile >> dataStringTok[1];
			dataFile.ignore(11);
			dataFile >> dataStringTok[2];
			dataFile.ignore(53);
			dataFile >> dataStringTok[3];
			dataFile.ignore(54);
			newData = new MemoryData(dataStringTok[0], dataStringTok[1], dataStringTok[2], dataStringTok[3], lineNumber);
			dataList.push_back(newData);
		}
		else if (stoll(dataStringTok[0], 0, 16) >= stoll("40000818", 0, 16) && stoll(dataStringTok[0], 0, 16) <= stoll("40000C14", 0, 16)) {
			dataFile >> dataStringTok[1];
			dataFile.ignore(11);
			dataFile >> dataStringTok[2];
			dataFile.ignore(53);
			dataFile >> dataStringTok[3];
			dataFile.ignore(54);
			newData = new MemoryData(dataStringTok[0], dataStringTok[1], dataStringTok[2], dataStringTok[3], lineNumber);
			dataList.push_back(newData);
		}
		else
			dataFile.ignore(144);

		lineNumber++;
	}
}

list<MemoryData*> Parser::getList() {
	return dataList;
}