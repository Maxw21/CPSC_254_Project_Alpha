#include "memorydata.h"

MemoryData::MemoryData() {
	address = "";
	data = "";
	time = "";
	size = "";
	cycle = "";
}

MemoryData::MemoryData(string address, string data, string size, string cycle) {
	this->address = address;
	this->data = data;
	this->size = size;
	this->cycle = cycle;
}

MemoryData::~MemoryData() { }

string MemoryData::setTime(string time) {
	this->time = time;
}