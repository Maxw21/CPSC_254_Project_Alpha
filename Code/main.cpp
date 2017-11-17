#include "parser.h"
#include <fstream>

ifstream dataFile;

using namespace std;



int main() {

	Parser* parser = new Parser();
	parser->makeList();

	return 0;
}