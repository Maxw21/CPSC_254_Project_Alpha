#include "parser.h"

Parser::Parser() { }

Parser::~Parser() { }

void Parser::makeList() {
	MemoryData* memoryPointer;
	MemoryData* newData;
	string dataString = "";
	string dataStringTok[14];
	int lineNumber = 2;
	bool getTime = false;


	dataFile.open("test_data.log", ios::in);

	if (!dataFile.is_open()) {
		exit(1);
	}

	// Discard first line in text file
	getline(dataFile, dataString);

	// Get first line of data
	getline(dataFile, dataString);
	istringstream streamBuffer(dataString);
	for (int i = 0; i < 14; i++) {
		streamBuffer >> dataStringTok[i];
	}
	if (dataStringTok[6].compare("0x40000810") == 0 || dataStringTok[6].compare("0x40000C18") == 0) {
			newData = new MemoryData(dataStringTok[6],dataStringTok[7],dataStringTok[9],dataStringTok[10],lineNumber);
			dataList.push_back(newData);
			getTime = true;
	}

	while (!dataFile.eof()) {

		lineNumber++;
		string dataStringTok[14] = { "" };
		getline(dataFile, dataString);
		istringstream streamBuffer(dataString);
		for (int i = 0; i < 14; i++) {
			streamBuffer >> dataStringTok[i];
		}

		// Set the time for the previous valid stream
		if (getTime == true) {
			memoryPointer = dataList.back();
			memoryPointer->setTime(dataStringTok[2]);
			getTime = false;
		}

		// Check if the address should be entered into the list
		if(!dataStringTok[1].compare("") == 0) {
			if (dataStringTok[6].compare("40000810") == 0 || dataStringTok[6].compare("40000C18") == 0) {
				newData = new MemoryData(dataStringTok[6], dataStringTok[7], dataStringTok[9], dataStringTok[10], lineNumber);
				dataList.push_back(newData);
				getTime = true;
			}
			if (dataStringTok[6].compare("IACK=7") == 0) {}
			else if (stoll(dataStringTok[6],0,16) >= stoll("40000818",0,16) && stoll(dataStringTok[6], 0, 16) <= stoll("40000C14", 0, 16)) {
				newData = new MemoryData(dataStringTok[6], dataStringTok[7], dataStringTok[9], dataStringTok[10], lineNumber);
				dataList.push_back(newData);
				getTime = true;
			}
			else if (stoll(dataStringTok[6], 0, 16) >= stoll("40000C20", 0, 16) && stoll(dataStringTok[6], 0, 16) <= stoll("4000101C", 0, 16)) {
				newData = new MemoryData(dataStringTok[6], dataStringTok[7], dataStringTok[9], dataStringTok[10], lineNumber);
				dataList.push_back(newData);
				getTime = true;
			}
		}
	}

	dataFile.close();
}

list<MemoryData*> Parser::getList() {
	return dataList;
}