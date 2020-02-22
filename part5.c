
	//*
	//This section was written similarly to Section 4, with the purpose of recieving input characters
	//and converting them one by one to the desired base. Invalid characters trigger a warning message.
	//
	//*

	char BaseKeyStroke; //The first input determines the base.
	char KeyStroke;
	int ErrorChar, ErrorFlag = 0;
	int exponent = 0;
	int SumToPrint, ToThePower, HowManyTimes; //same as Section 4

	printf("Enter a base (2-10)\n");
	scanf(" %c", &BaseKeyStroke);

	if (BaseKeyStroke < '2' || BaseKeyStroke > '9') { //For invalid base choices
		printf("Sorry, your base choice is invalid.\n");
	}

	else if (BaseKeyStroke == '2') {
		printf("Enter a reversed number in base %c\n", BaseKeyStroke);
		int Base2;                                //A new integer is declared for the given base number.
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke == '0' || KeyStroke == '1') { Base2 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = ("%c", KeyStroke);
					printf("Error! %c is not a valid digit in base 2\n", ErrorChar); //Error message for invalid chars.
				}

				if (exponent == 0) { SumToPrint = Base2; }    //Similar conversion as in Section 4.
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
		if (ErrorFlag == 0) {  //Error flag prevents sum from being printed.
			printf("%d", SumToPrint);


		}

	}



	else if (BaseKeyStroke == '3') {
		int Base3;
		printf("Enter a reversed number in base %c\n", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '2') { Base3 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = ("%c", KeyStroke);
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
			printf("%d", SumToPrint);


		}
	}


	else if (BaseKeyStroke == '4') {
		int Base4;
		printf("Enter a reversed number in base %c\n", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '3') { Base4 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = ("%c", KeyStroke);
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
			printf("%d", SumToPrint);


		}
	}


	else if (BaseKeyStroke == '5') {
		int Base5;
		printf("Enter a reversed number in base %c\n", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '4') { Base5 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = ("%c", KeyStroke);
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
			printf("%d", SumToPrint);


		}
	}



	else if (BaseKeyStroke == '6') {
		int Base6;
		printf("Enter a reversed number in base %c\n", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '5') { Base6 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = ("%c", KeyStroke);
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
			printf("%d", SumToPrint);


		}
	}


	else if (BaseKeyStroke == '7') {
		int Base7;
		printf("Enter a reversed number in base %c\n", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '6') { Base7 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = ("%c", KeyStroke);
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
			printf("%d", SumToPrint);


		}
	}



	else if (BaseKeyStroke == '8') {
		int Base8;
		printf("Enter a reversed number in base %c\n", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '7') { Base8 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = ("%c", KeyStroke);
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
			printf("%d", SumToPrint);


		}
	}



	else if (BaseKeyStroke == '9') {
		int Base9;
		printf("Enter a reversed number in base %c\n", BaseKeyStroke);
		scanf(" %c", &KeyStroke);
		while (KeyStroke != '\n') {
			if (KeyStroke != '\n') {
				if (KeyStroke >= '0' && KeyStroke <= '8') { Base9 = KeyStroke - '0'; }
				else {
					ErrorFlag = 1;
					ErrorChar = ("%c", KeyStroke);
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
			printf("%d", SumToPrint);


		}
	}






