#include "parser.h"
#include <fstream>

using namespace std;

ifstream dataFile;
fstream rwStream;

int main() {

	Parser* parser = new Parser();
	parser->parseData();
	return 0;
}