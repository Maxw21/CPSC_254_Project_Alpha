#include "parser.h"
#include <fstream>

using namespace std;

ifstream dataFile;
fstream rwStream;

int main() {

	list<MemoryData*> dataList;

	Parser* parser = new Parser();
	parser->parseData();
	dataList = parser->getList();
	
	return 0;
}