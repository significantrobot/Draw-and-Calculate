#include <stdio.h>
int main() {

	//*
	//This code was written to detect three individual characters one by one and assess the relationship
	//between the first one and the second one. If the relationship is invalid, increasing, decreasing, or constant, then a "switch"
	//is flipped (if increasing or decreasing, then "constant switch" is zeroed because it ceases to be true.)
	//Once the relationship is assessed, then the first character is "thrown out", the second character before the first,
	//the third character becomes the second, a new third character is scanned, and the process is repeated,
	//until the third character is "enter". After the cycle is complete, the program examines which switches
	//ended up being true or false as result of the comparisons, and it will print the desired text.
	//
	//Spaces before the input will be ignored. Spaces in the middle of the text will trigger "invalid."
	//*


	char FirstLetter, SecondLetter, NextLetter;
	int InvalidSwitch = 0, IncreaseSwitch = 0, DecreaseSwitch = 0, ConstantSwitch = 0; //switches initialized at "false"
	printf("Enter text: ");
	scanf(" %c%c", &FirstLetter, &SecondLetter); //input for first two characters.
	while (NextLetter != '\n') {
	scanf("%c", &NextLetter);    //input for third character inside loop to enable potentially infinite number of characters
	if ((FirstLetter < 'a' || FirstLetter > 'z') || (SecondLetter < 'a' || SecondLetter> 'z')) { InvalidSwitch = 1; } //checking if text is valid
	else if (FirstLetter < SecondLetter) { IncreaseSwitch = 1, ConstantSwitch = 0; }
	else if (FirstLetter > SecondLetter) { DecreaseSwitch = 1, ConstantSwitch = 0; } //If Increase and Decrease both True, text is Mixed
	else if (FirstLetter == SecondLetter) { ConstantSwitch = 1; } //if increasing or decreasing, constant becomes false
	FirstLetter = SecondLetter;
	SecondLetter = NextLetter; //swapping the characters
	}


	if (InvalidSwitch == 1) { printf("Your text is invalid"); } //these conditions assess the flags and print the output
	else if (InvalidSwitch == 0 && IncreaseSwitch == 1 && DecreaseSwitch == 0 && (ConstantSwitch == 0 || ConstantSwitch == 1)) { printf("Your text is increasing"); }
	else if (InvalidSwitch == 0 && IncreaseSwitch == 0 && DecreaseSwitch == 1 && (ConstantSwitch == 0 || ConstantSwitch == 1)) { printf("Your text is decreasing"); }
	else if (InvalidSwitch == 0 && IncreaseSwitch == 0 && DecreaseSwitch == 0 && ConstantSwitch == 1) { printf("Your text is constant"); }
	else if (InvalidSwitch == 0 && IncreaseSwitch == 1 && DecreaseSwitch == 1){ printf("Your text is mixed"); }

	return 0;
}
