#include "memorydata.h"

MemoryData::MemoryData() {
	address = "";
	data = "";
	size = "";
	cycle = "";
	time = "";
	lineNumber = 0;
}

MemoryData::MemoryData(string address, string data, string size, string cycle, string time, int lineNumber) {
	this->address = address;
	this->data = data;
	this->size = size;
	this->cycle = cycle;
	this->time = time;
	this->lineNumber = lineNumber;
}

MemoryData::~MemoryData() { }

void MemoryData::setTime(string time) {
	this->time = time;
}