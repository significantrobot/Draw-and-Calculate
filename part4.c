#include <stdio.h>

int main() {
	//*
	//This code is written to recieve a reverse hexadecimal number and convert it to decimal.
	//It will recieve the input characters one by one, redefine them as integers,
	//and convert them individually into their base 16 counterpart
	//by multiplying them to the power of their index and adding each index together.
	//For 16 ^ 0 and 16 ^ 1, an "if" condition is used,
	//and for all other 16^x a "for" loop defined by "exponent" is used to calculate the exponent.
	//This was done in order to avoid multiplication by zero.
	//Invalid text triggers an error message and prevents the program from printing out the sum.
	//*

	char HexKeyStroke; //hex value input
	int SumToPrint, DecimalValue;
	int HowManyTimes, ToThePower; //used in "for" loop to calculate exponent
	int ErrorChar, ErrorFlag = 0; //the value to print in the error message, and the flag that triggers is
	int exponent = 0;

	printf("Please enter a hex number in reverse\n");
	scanf(" %c", &HexKeyStroke);     //detection of first input character
	while (HexKeyStroke != '\n') {
			if (HexKeyStroke != '\n') {                                         //this block converts char to int counterpart
				if (HexKeyStroke == 'a' || HexKeyStroke == 'A') { DecimalValue = 10; }
				else if (HexKeyStroke == 'b' || HexKeyStroke == 'B') { DecimalValue = 11; }
				else if (HexKeyStroke == 'c' || HexKeyStroke == 'C') { DecimalValue = 12; }
				else if (HexKeyStroke == 'd' || HexKeyStroke == 'D') { DecimalValue = 13; }
				else if (HexKeyStroke == 'e' || HexKeyStroke == 'E') { DecimalValue = 14; }
				else if (HexKeyStroke == 'f' || HexKeyStroke == 'F') { DecimalValue = 15; }
				else if (HexKeyStroke >= '0' && HexKeyStroke <= '9') { DecimalValue = ("%d", (HexKeyStroke - '0')); }
				else if (HexKeyStroke >= 0 && HexKeyStroke <= 127) {    //any input other than 0-f will trigger the error msg
					ErrorFlag = 1;
					ErrorChar = ("%c", HexKeyStroke);
					printf("Error! %c is not a valid digit in base 16\n", ErrorChar);
				}
			}

			if (exponent == 0) { SumToPrint = DecimalValue; } //the int is now converted to decimal thru exponent 
			else if (exponent == 1) { SumToPrint = SumToPrint + (DecimalValue * 16); }
			else if (exponent >= 2) {
				ToThePower = 16;
				for (HowManyTimes = 1; HowManyTimes < exponent; ++HowManyTimes) {
					ToThePower = ToThePower * 16;
				}
				SumToPrint = SumToPrint + (ToThePower * DecimalValue);
			}
			++exponent;
			scanf("%c", &HexKeyStroke);    //"throwing out" the first character since it has been processed, detecting second character

	}

	if (ErrorFlag == 0) {   //the conversion takes place regardless of error, but is only printed if there is no error.
		printf("%d", SumToPrint);
	}

	return 0;
}