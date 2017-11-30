#include "parser.h"
#include "interpreter.h"
#include <fstream>

using namespace std;

ifstream dataFile;
fstream rwStream;

int main(int argc, char *argv[]) {
	string fileName = argv[1];
	list<MemoryData*> dataList;
	Parser* parser = new Parser(fileName);
	Interpreter* interpreter = new Interpreter();

	parser->parseData();
	dataList = parser->getList();
	interpreter->list_of_data(dataList);
	
	return 0;
}
