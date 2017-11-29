#include "parser.h"
#include "interpreter.h"
#include <fstream>

using namespace std;

ifstream dataFile;
fstream rwStream;

int main() {

	list<MemoryData*> dataList;
	Parser* parser = new Parser();
	Interpreter* interpreter = new Interpreter();

	parser->parseData();
	dataList = parser->getList();
	interpreter->list_of_data(dataList);
	
	return 0;
}