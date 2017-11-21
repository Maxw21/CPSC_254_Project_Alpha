#include "interpreter.h"

Interpreter::Interpreter() {
	binConv = "";
	binVal = -1;	// Subject to change
	description = "";
	fieldName = "";
}

Interpreter::~Interpreter() {}

/* FIELD NAME :
 * Checks which word number it is after binary conversion,  *
 * then assigns a field name to whichever number it is		*/
#pragma region

string Interpreter::word_fld_name(int wordNumber) {
	switch (wordNumber) {
	case 0: fieldName = "Red_Ctrl";
		break;
	case 1: fieldName = "Cmd_Type";
		break;
	case 4: fieldName = "Rec_Rawr";
		break;
	case 5: fieldName = "Cmd_ID";
		break;
	case 10: fieldName = "Num_Responses";
		break;
	case 15: fieldName = "Reset_Enable";
		break;
	case 22: fieldName = "Direction";
		break;
	case 32: fieldName = "Num_Samples";
		break;
	case 37: fieldName = "Parity";
		break;
	case 38: fieldName = "Test";
		break;
	case 40: fieldName = "Ctrl_Enable";
		break;
	case 41: fieldName = "Code";
		break;
	default: fieldName = "error - check code";
	}
	return fieldName;
}
#pragma endregion

/* DEDSCRIPTION :
 * Checks the value of a word according to word number		*
 * after binary conversion, then assigns a command after	*/
#pragma region

string Interpreter::word_0_dscr(int binVal) {
	switch (binVal) {
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

string Interpreter::word_1_dscr(int binVal) {
	switch (binVal) {
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

string Interpreter::word_22_dscr(int binVal) {
	switch (binVal) {
	case 0: description = "Right";
		break;
	case 1: description = "Left";
		break;
	default: description = "unknown";
	}
	return description;
}

string Interpreter::word_37_dscr(int binVal) {
	switch (binVal) {
	case 0: description = "even";
		break;
	case 1: description = "odd";
		break;
	default: description = "unknown";
	}
	return description;
}

string Interpreter::word_4_15_38_40_dscr(int binVal) {
	switch (binVal) {
	case 0: description = "disable";
		break;
	case 1: description = "enable";
		break;
	default: description = "unknown";
		break;
	}
	return description;
}
#pragma endregion