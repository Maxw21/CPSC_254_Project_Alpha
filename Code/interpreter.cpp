#include "interpreter.h"

Interpreter::Interpreter() {
	bit = -1;	// Subject to change
	description = "";
}

Interpreter::~Interpreter() {}

string Interpreter::word_0(int value) {
	switch (value) {
	case 0: description = "no recording";
		break;
	case 2: description = "no processing";
		break;
	case 3: description = "processing & recording";
		break;
	default: description = "unknown";
	}
	return description;
}

string Interpreter::word_1(int value) {
	switch (value) {
	case 4: description = "Type A";
		break;
	case 5: description = "Type B";
		break;
	case 6: description = "Type C";
		break;
	default: description = "unknown";
	}
	return description;
}

string Interpreter::word_4_15_38_40(int value) {
	switch (value) {
	case 0: description = "disable";
		break;
	case 1: description = "enable";
		break;
	default: description = "unknown";
		break;
	}
	return description;
}

string Interpreter::word_22(int value) {
	switch (value) {
	case 0: description = "Right";
		break;
	case 1: description = "Left"
		break;
	default: description = "unknown";
	}
	return description;
}

string Interpreter::word_37(int value) {
	switch (value) {
	case 0: description = "even";
		break;
	case 1: description = "odd";
		break;
	default: description = "unknown";
	}
	return description;
}