#include <string>
using namespace std;

class MemoryData {
public:
	MemoryData();
	MemoryData(string, string, string, string);
	~MemoryData();
	string setTime(string);
private:
	string address;
	string data;
	string time;
	string size;
	string cycle;
};