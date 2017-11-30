#include "memorydata.h"

MemoryData::MemoryData() {
	address = "";
	data = "";
	cycle = "";
	time = "";
	lineNumber = 0;
}

MemoryData::MemoryData(string address, string data, string size, string cycle, string time, int lineNumber) {
	this->address = address;
	this->data = data;
	this->cycle = cycle;
	this->size = size;
	this->time = time;
	this->lineNumber = lineNumber;
}

MemoryData::~MemoryData() { }

void MemoryData::setTime(string time) {
	this->time = time;
}

string MemoryData::getAddress() {
	return address;
}

string MemoryData::getData() {
	return data;
}

string MemoryData::getTime() {
	return time;
}

int MemoryData::getLineNumber() {
	return lineNumber;
}

string MemoryData::getCycle() {
	return cycle;
}

string MemoryData::getSize() {
	return size;
}