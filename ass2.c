/************************************************
*YANIV LEVY                             
*T.Z.316464817                        
*Group 01 (Computer Science)            
*ass02                                  
*************************************************/



#include <stdio.h>



/*****
*Function Name: Draw
*Input: input
*Output: +, - , / , \ , |, X
*Function Operation: 
	The functions views the box as a matrix and prints the desired character from left to right
	as it goes across rows and columns
	
*******/


void draw() {
	//rows
	int i = 0;
	//columns
	int j = 0;
	int input = 0;
	// "k" will be used to calculate the distance from the rightmost wall "|" and the "/" character in the box
	int k = 0;
	printf("Enter a number: ");
	scanf("%i", &input);
	// the dimension of the box, 2x + 1, declared only after "input" is defined
	int dimension = (input * 2) + 1;

	 /*
	 when input is 0, we want to only print "X"
	 */

	if (input == 0) {
		printf("X\n");
	}



	if (input > 0) { 
			//counting rows and columns
		for (i = 1; i <= dimension; i++, ++k) {
			for (j = 1; j <= dimension; j++)
			{
				
				/* brief review of the conditions:
	 			 - for row 1 and (dimension), print "-"
				 - in corners, print "+"
				 - when i = j, print "\"
				 - when j = (dimension - desired distance), print "/". variable k is used in the calculation
				 - print "X" in the middle
				*/
					
				if (i == 1 && j == 1) { printf("+"); }
				if (j != i && i == 1 && j < dimension) { printf("-"); }
				if (i == 1 && j == dimension) { printf("+\n"); }
				if (i != 1 && i != dimension && j == 1) { printf("|"); }
				if (j != (dimension - k) && j != 1 && j != dimension && i != 1 && i != dimension && i != j && 1 < i < dimension && 1 < j < dimension){
					printf(" ");
				}
				if (i != ((dimension + 1) / 2) && j != ((dimension + 1) / 2) && i != 1 && i != dimension && i == j) { printf("\\"); }
				if (i != 1 && i != dimension && j == dimension) { printf("|\n"); }
				if (i != ((dimension + 1) / 2) && j != ((dimension + 1) / 2) && i != 1 && j != dimension && ((i + j) == (dimension + 1)) && i != dimension && j != dimension && j == (dimension - k)){
					printf("/"); }
				if (i == j && (i + j) == (dimension + 1)) { printf("X"); }
				if (i == dimension && j == 1) { printf("+"); }
				if (i != j && i == dimension && j != 1 && j < dimension) { printf("-"); }
				if (i == dimension && j == dimension) { printf("+\n"); }
			}
		}
	}

}


/*****
*Function Name: isEvenLength
*Input: KeyStroke
*Output: clicker
*Function Operation: 
	The function counts the number of keystrokes detected before "enter"
	as the user types. It does so by using a "clicker".
*******/

void isEvenLength() {

	char KeyStroke;
	int clicker = 1;
	printf("Enter text: ");
	
	//counting the first one outside of the loop the space from the menu's scanf doesn't interfere
	 
	scanf(" %c", &KeyStroke);
	clicker++;

	//every keystroke is a "click" on the clicker
	
	while (KeyStroke != '\n') {     
		scanf("%c", &KeyStroke);
		clicker++;
	}
	
	//bitwise operation because rightmost digit of odd length is 1
	if ((clicker & 1) == 0) { printf("Your text's length is even\n"); }
	else { printf("Your text's length is odd\n"); }

}

/*****
*Function Name: identifyText
*Input: FirstLetter, SecondLetter, NextLetter
*Output: InvalidSwitch, IncreaseSwitch, DecreaseSwitch, ConstantSwitch
*Function Operation: 

		This code was written to detect three individual characters one by one and assess the relationship
		between the first one and the second one. If the relationship is invalid, increasing, decreasing, or constant,
		then a "switch" is flipped.
		Once the relationship is assessed, then the first character is "thrown out", the second character before the first,
		the third character becomes the second, a new third character is scanned, and the process is repeated,
		until the third character is "enter". After the cycle is complete, the program examines which switches
		ended up being true or false as result of the comparisons, and it will print the desired text.
		
		Spaces before the input will be ignored. Spaces in the middle of the text will trigger "invalid."
		
*******/


void identifyText() {
		char FirstLetter, SecondLetter, NextLetter;
		//switches initialized at "false"
		int InvalidSwitch = 0, IncreaseSwitch = 0, DecreaseSwitch = 0, ConstantSwitch = 0;
		printf("Enter text: ");
		//input for first two characters.
		scanf(" %c %c", &FirstLetter, &SecondLetter);
		while (NextLetter != '\n') {
			//input for third character inside loop to enable potentially infinite number of characters
			scanf("%c", &NextLetter);
			//checking if text is valid
			if ((FirstLetter < 'a' || FirstLetter > 'z') || (SecondLetter < 'a' || SecondLetter> 'z')) { InvalidSwitch = 1; }
			else if (FirstLetter < SecondLetter) { IncreaseSwitch = 1, ConstantSwitch = 0; }
			//If Increase and Decrease both True, text is Mixed
			else if (FirstLetter > SecondLetter) { DecreaseSwitch = 1, ConstantSwitch = 0; }
			//if increasing or decreasing, Constant becomes false
			else if (FirstLetter == SecondLetter) { ConstantSwitch = 1; }
			//swapping the characters
			FirstLetter = SecondLetter;
			SecondLetter = NextLetter;
		}

		/*
		these conditions assess the flags and print the output
		*/
		
		if (InvalidSwitch == 1) { printf("your text is invalid\n"); }
		else if (InvalidSwitch == 0 && IncreaseSwitch == 1 && DecreaseSwitch == 0 && (ConstantSwitch == 0 || ConstantSwitch == 1)){
			printf("your text is increasing\n"); }
		else if (InvalidSwitch == 0 && IncreaseSwitch == 0 && DecreaseSwitch == 1 && (ConstantSwitch == 0 || ConstantSwitch == 1)){
			printf("your text is decreasing\n"); }
		else if (InvalidSwitch == 0 && IncreaseSwitch == 0 && DecreaseSwitch == 0 && ConstantSwitch == 1){
			printf("your text is constant\n"); }
		else if (InvalidSwitch == 0 && IncreaseSwitch == 1 && DecreaseSwitch == 1){
			printf("your text is mixed\n"); }


}


/*****
*Function Name: hexToDec
*Input: HexKeyStroke
*Output: SumToPrint
*Function Operation: 
	It will receive the input characters one by one, redefine them as integers,
	and convert them individually into their base 16 counterpart
	by multiplying them to the power of their index and adding each index together.
	For 16 ^ 0 and 16 ^ 1, an "if" condition is used,
	and for all other 16^x a "for" loop defined by "exponent" is used to calculate the exponent.
	This was done in order to avoid multiplication by zero.
	Invalid text triggers an error message and prevents the program from printing out the sum.	
*******/

void hexToDec() {
	//hex value input
	char HexKeyStroke;
	int SumToPrint, DecimalValue;
	//used in "for" loop to calculate exponent
	int HowManyTimes, ToThePower;
	////the value to print in the error message, and the flag that triggers is
	int ErrorChar, ErrorFlag = 0;
	int exponent = 0;

	printf("Enter a reversed number in base 16: ");
	//detection of first input character
	scanf(" %c", &HexKeyStroke);
	while (HexKeyStroke != '\n') {
		
		/*
		converting char to int characters
		*/
		
		if (HexKeyStroke != '\n') {                            
			if (HexKeyStroke == 'a' || HexKeyStroke == 'A') { DecimalValue = 10; }
			else if (HexKeyStroke == 'b' || HexKeyStroke == 'B') { DecimalValue = 11; }
			else if (HexKeyStroke == 'c' || HexKeyStroke == 'C') { DecimalValue = 12; }
			else if (HexKeyStroke == 'd' || HexKeyStroke == 'D') { DecimalValue = 13; }
			else if (HexKeyStroke == 'e' || HexKeyStroke == 'E') { DecimalValue = 14; }
			else if (HexKeyStroke == 'f' || HexKeyStroke == 'F') { DecimalValue = 15; }
			else if (HexKeyStroke >= '0' && HexKeyStroke <= '9') { DecimalValue = (HexKeyStroke - '0'); }
			else if (HexKeyStroke >= 0 && HexKeyStroke <= 127) {    //any input other than 0-f will trigger the error msg
				ErrorFlag = 1;
				ErrorChar = HexKeyStroke;
				printf("Error! %c is not a valid digit in base 16\n", ErrorChar);
			}
		}

		/*
		the int is converted to decimal using exponent
		*/
		
		if (exponent == 0) { SumToPrint = DecimalValue; }
		else if (exponent == 1) { SumToPrint = SumToPrint + (DecimalValue * 16); }
		else if (exponent >= 2) {
			ToThePower = 16;
			for (HowManyTimes = 1; HowManyTimes < exponent; ++HowManyTimes) {
				ToThePower = ToThePower * 16;
			}
			SumToPrint = SumToPrint + (ToThePower * DecimalValue);
		}
		++exponent;
		//"throwing out" the first character since it has been processed, detecting second character
		scanf("%c", &HexKeyStroke);

	}

	//the conversion takes place regardless of error, but is only printed if there is no error.
	if (ErrorFlag == 0) {
		printf("%d\n", SumToPrint);
	}


}


/*****
*Function Name: baseToDec
*Input: BaseKeyStroke, KeyStroke
*Output: SumToPrint
*Function Operation: 
	It will receive the input characters one by one, redefine them as integers,
	and convert them individually into their base 16 counterpart
	by multiplying them to the power of their index and adding each index together.
	
	Essentially similar to hexToDec
*******/

void baseToDec() {

	//The first input determines the base.
	char BaseKeyStroke;
	char KeyStroke;
	int ErrorChar, ErrorFlag = 0;
	int exponent = 0;
	 //same as hexToDec
	int SumToPrint, ToThePower, HowManyTimes;
	
	printf("Enter a base (2-10): ");
	scanf(" %c", &BaseKeyStroke);

	//For invalid base choices
	if (BaseKeyStroke < '2' || BaseKeyStroke > '9') {
		printf("Error! Your base choice is invalid.\n");
	}

	//For Base 2:
	else if (BaseKeyStroke == '2') {
		printf("Enter a reversed number in base %c: ", BaseKeyStroke);
		//A new integer is declared for the given base number.
		int Base2;                                
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke == '0' || KeyStroke == '1') { Base2 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = KeyStroke;
					//Error message for invalid chars.
					printf("Error! %c is not a valid digit in base 2\n", ErrorChar); 
				}

				//Similar conversion as in hexToDec.
				if (exponent == 0) { SumToPrint = Base2; }
				else if (exponent == 1) { SumToPrint = SumToPrint + (Base2 * 2); }
				else if (exponent > 1) {
					ToThePower = 2;
					for (HowManyTimes = 1; HowManyTimes < exponent; ++HowManyTimes) {
						ToThePower = ToThePower * 2;
					}
					SumToPrint = SumToPrint + (ToThePower * Base2);
				}
				++exponent;
				scanf("%c", &KeyStroke);
			}
		}
		
		//Error flag prevents sum from being printed.
		if (ErrorFlag == 0) { 
			printf("%d\n", SumToPrint);


		}

	}


		/*
		The remaining conditions are identical, for bases 3-9
		*/

	//Base 3:
	else if (BaseKeyStroke == '3') {
		int Base3;
		printf("Enter a reversed number in base %c: ", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '2') { Base3 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = KeyStroke;
					printf("Error! %c is not a valid digit in base 3\n", ErrorChar);
				}

				if (exponent == 0) { SumToPrint = Base3; }
				else if (exponent == 1) { SumToPrint = SumToPrint + (Base3 * 3); }
				else if (exponent > 1) {
					ToThePower = 2;
					for (HowManyTimes = 1; HowManyTimes < exponent; ++HowManyTimes) {
						ToThePower = ToThePower * 3;
					}
					SumToPrint = SumToPrint + (ToThePower * Base3);
				}
				++exponent;
				scanf("%c", &KeyStroke);
			}
		}
		if (ErrorFlag == 0) {
			printf("%d\n", SumToPrint);


		}
	}

	//Base 4:
	else if (BaseKeyStroke == '4') {
		int Base4;
		printf("Enter a reversed number in base %c: ", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '3') { Base4 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = KeyStroke;
					printf("Error! %c is not a valid digit in base 4\n", ErrorChar);
				}

				if (exponent == 0) { SumToPrint = Base4; }
				else if (exponent == 1) { SumToPrint = SumToPrint + (Base4 * 4); }
				else if (exponent > 1) {
					ToThePower = 4;
					for (HowManyTimes = 1; HowManyTimes < exponent; ++HowManyTimes) {
						ToThePower = ToThePower * 4;
					}
					SumToPrint = SumToPrint + (ToThePower * Base4);
				}
				++exponent;
				scanf("%c", &KeyStroke);
			}
		}
		if (ErrorFlag == 0) {
			printf("%d\n", SumToPrint);


		}
	}

	//Base 5:
	else if (BaseKeyStroke == '5') {
		int Base5;
		printf("Enter a reversed number in base %c: ", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '4') { Base5 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = KeyStroke;
					printf("Error! %c is not a valid digit in base 5\n", ErrorChar);
				}

				if (exponent == 0) { SumToPrint = Base5; }
				else if (exponent == 1) { SumToPrint = SumToPrint + (Base5 * 5); }
				else if (exponent > 1) {
					ToThePower = 5;
					for (HowManyTimes = 1; HowManyTimes < exponent; ++HowManyTimes) {
						ToThePower = ToThePower * 5;
					}
					SumToPrint = SumToPrint + (ToThePower * Base5);
				}
				++exponent;
				scanf("%c", &KeyStroke);
			}
		}
		if (ErrorFlag == 0) {
			printf("%d\n", SumToPrint);


		}
	}


	//Base 6:
	else if (BaseKeyStroke == '6') {
		int Base6;
		printf("Enter a reversed number in base %c: ", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '5') { Base6 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = KeyStroke;
					printf("Error! %c is not a valid digit in base 6\n", ErrorChar);
				}

				if (exponent == 0) { SumToPrint = Base6; }
				else if (exponent == 1) { SumToPrint = SumToPrint + (Base6 * 6); }
				else if (exponent > 1) {
					ToThePower = 6;
					for (HowManyTimes = 1; HowManyTimes < exponent; ++HowManyTimes) {
						ToThePower = ToThePower * 6;
					}
					SumToPrint = SumToPrint + (ToThePower * Base6);
				}
				++exponent;
				scanf("%c", &KeyStroke);
			}
		}
		if (ErrorFlag == 0) {
			printf("%d\n", SumToPrint);


		}
	}

	//Base 7:
	else if (BaseKeyStroke == '7') {
		int Base7;
		printf("Enter a reversed number in base %c: ", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '6') { Base7 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = KeyStroke;
					printf("Error! %c is not a valid digit in base 7\n", ErrorChar);
				}

				if (exponent == 0) { SumToPrint = Base7; }
				else if (exponent == 1) { SumToPrint = SumToPrint + (Base7 * 7); }
				else if (exponent > 1) {
					ToThePower = 7;
					for (HowManyTimes = 1; HowManyTimes < exponent; ++HowManyTimes) {
						ToThePower = ToThePower * 7;
					}
					SumToPrint = SumToPrint + (ToThePower * Base7);
				}
				++exponent;
				scanf("%c", &KeyStroke);
			}
		}
		if (ErrorFlag == 0) {
			printf("%d\n", SumToPrint);


		}
	}


	//Base 8:
	else if (BaseKeyStroke == '8') {
		int Base8;
		printf("Enter a reversed number in base %c: ", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '7') { Base8 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = KeyStroke;
					printf("Error! %c is not a valid digit in base 8\n", ErrorChar);
				}

				if (exponent == 0) { SumToPrint = Base8; }
				else if (exponent == 1) { SumToPrint = SumToPrint + (Base8 * 8); }
				else if (exponent > 1) {
					ToThePower = 8;
					for (HowManyTimes = 1; HowManyTimes < exponent; ++HowManyTimes) {
						ToThePower = ToThePower * 8;
					}
					SumToPrint = SumToPrint + (ToThePower * Base8);
				}
				++exponent;
				scanf("%c", &KeyStroke);
			}
		}
		if (ErrorFlag == 0) {
			printf("%d\n", SumToPrint);


		}
	}


	//Base 9:
	else if (BaseKeyStroke == '9') {
		int Base9;
		printf("Enter a reversed number in base %c: ", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '8') { Base9 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = KeyStroke;
					printf("Error! %c is not a valid digit in base 9\n", ErrorChar);
				}

				if (exponent == 0) { SumToPrint = Base9; }
				else if (exponent == 1) { SumToPrint = SumToPrint + (Base9 * 9); }
				else if (exponent > 1) {
					ToThePower = 9;
					for (HowManyTimes = 1; HowManyTimes < exponent; ++HowManyTimes) {
						ToThePower = ToThePower * 9;
					}
					SumToPrint = SumToPrint + (ToThePower * Base9);
				}
				++exponent;
				scanf("%c", &KeyStroke);
			}
		}
		if (ErrorFlag == 0) {
			printf("%d\n", SumToPrint);


		}
	}

}



/*****
*Function Name: bitCount
*Input: Number
*Output: bitcounter
*Function Operation: 
	It will receive the input number, convert it to binary
	using a mathematical algorithm, and asssesses how many 1s or 0s are in the result
	by using a "bitcounter."
	
*******/

void bitCount() {

	//The number to convert
	int Number;
	//The 1 or 0 that will result from the conversion algorithm
	int Base2;
	int bitcounter = 0;
	printf("Enter a number: ");
	scanf(" %d", &Number);
	//Since we will run operations on the input, this preserves the input value for the output msg.
	int NumberForPrint = Number;

	//for positive numbers
	if (Number >= 0) {

		while (Number > 0) {
			Base2 = (Number % 2);
			if (Base2 == 1) { ++bitcounter; }
			//bitcounter counts every time a bit is activated
			Number = (Number / 2);

		}
	}

	/*The same process is used for negative numbers, but "bitcounter" is redefined at 32,
	the number is converted to a positive, and bitcounter is subtracted from every time a "1" is counted,
	because in two's complement (negatives) the binary values are inverse.
	*/
	
	else if (Number < 0) {
		bitcounter = 32;
		Number = -1 * Number;
		while (Number > 0) {
			Base2 = (Number % 2);
			//same process as above, except --bitcounter because of the negative number
			if (Base2 == 1) { --bitcounter; }
			Number = (Number / 2);

		}

	}

	printf("The bit count of %d is %d\n", NumberForPrint, bitcounter);

}


/*****
*Function Name: main
*Input: choice
*Output: case 1 - 6
*Function Operation: Menu function
*******/

int main() {
	int choice;
	do {
		printf("Choose an option:\n1: Draw\n2: Even or Odd\n3: Text type\
                \n4: Hex to Dec\n5: Base to Dec\n6: Count bits\n0: Exit\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1: draw();
			break;
		case 2: isEvenLength();
			break;
		case 3: identifyText();
			break;
		case 4: hexToDec();
			break;
		case 5: baseToDec();
			break;
		case 6: bitCount();
		case 0: break;
		default: printf("Wrong option!\n");
		}
	} while (choice != 0);



	return 0;
}
