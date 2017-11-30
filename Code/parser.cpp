#include "parser.h"
#include <vector>

Parser::Parser(string fileName) {
	this->fileName = fileName;
}

Parser::~Parser() { }

void Parser::parseData() {
	string dataString;
	int lineNumber = 1;
	MemoryData* newData;
	string dataStringTok[4] = { "" };
	string testString;
	if (fileName != "") {
		dataFile.open(fileName, ios::in);
	}

	if (!dataFile.is_open()) {
		return;
	}
	//Skip to address location
	dataFile.ignore(82);
	while (!dataFile.eof()) {
		dataFile >> dataStringTok[0];
		testString = "0x";
		testString.append(dataStringTok[0]);
		// If the address is valid save the data from the line into memorydata object and store those in a list
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
		else if (testString >= "0x40000C20" && testString <= "0x40000C73") {
			dataFile >> dataStringTok[1];
			dataFile.ignore(11);
			dataFile >> dataStringTok[2];
			dataFile.ignore(53);
			dataFile >> dataStringTok[3];
			dataFile.ignore(54);
			newData = new MemoryData(dataStringTok[0], dataStringTok[1], dataStringTok[2], dataStringTok[3], lineNumber);
			dataList.push_back(newData);
		}
		else if (testString >= "0x40000818" && testString <= "0x4000086B") {
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