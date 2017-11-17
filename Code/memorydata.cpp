#include "memorydata.h"

MemoryData::MemoryData() {
	address = "";
	data = "";
	time = "";
	size = "";
	cycle = "";
}

MemoryData::MemoryData(string address, string data, string size, string cycle, int lineNumber) {
	this->address = address;
	this->data = data;
	this->size = size;
	this->cycle = cycle;
	this->lineNumber = lineNumber;
}

MemoryData::~MemoryData() { }

void MemoryData::setTime(string time) {
	this->time = time;
}