#include <interpreter.h>

Interpreter::Interpreter() {
	bit = -1;
}

Interpreter::~Interpreter() {}

string Interpreter::word0(int value) {
	switch (value) {
	case 0: cout << "no recording";
		break;
	case 2: cout << "no processing";
		break;
	case 3: cout << "processing & recording";
		break;
	default: cout << "unknown";
	}
}

void Interpreter::word1(int value) {
	switch (value) {
	case 4: cout << "Type A";
		break;
	case 5: cout << "Type B";
		break;
	case 6: cout << "Type C";
		break;
	default: cout << "unknown";
	}
}

void Interpreter::word4(int value) {
	switch (value) {
	case 0: cout << "disable";
		break;
	case 1: cout << "enable";
		break;
	default: cout << "unknown";
		break;
	}
}

void Interpreter::word5(int value) {
	switch (value) {
		
	}
}