#include <stdio.h>
int main() {
	//*
	//This code recieves an input number, converts it to binary using a mathematical algorithm,
	//and assesses how many 1s or 0s are in the result by counting with "bitcounter" how many times the conversion algorithm
	//yields a 1 or a 0. (1 is a used bit, 0 is unused)
	//The same exact process is used for negative numbers, but "bitcounter" is redefined at 32,
	//the number is converted to a positive, and bitcounter is subtracted from every time a "1" is counted,
	//because in two's complement (negatives) the binary values are inverse.
	//*


	int Number; //The number to convert
	int Base2;  //The 1 or 0 that will result from the conversion algorithm
	int bitcounter = 0;
	printf("Enter a number:\n");
	scanf(" %d", &Number);
	int NumberForPrint = Number; //Since we will run operations on the input, this preserves the input value for the output msg.

	if (Number >= 0) { //for positive numbers

		while (Number > 0) {
			Base2 = (Number % 2);
			if (Base2 == 1) { ++bitcounter; } //bitcounter counts every time a bit is activated
			Number = (Number / 2);

		}   //if printed, this conversion would print the binary in reverse, but we're not printing, so it doesn't matter
	}

	else if (Number < 0) {
		bitcounter = 32;
		Number = -1 * Number;
		while (Number > 0) {   //same process as above, except --bitcounter because of the negative number
			Base2 = (Number % 2);
			if (Base2 == 1) { --bitcounter; }
			Number = (Number / 2);

		}

	}

	printf("\nThe bit count of %d is %d.\n", NumberForPrint, bitcounter);


	return 0;
}