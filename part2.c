	//*
	//the idea here is to count the number of keystrokes detected before "enter" as the user types, by use of a clicker.
	//*

	char keystrokes;
	int clicker = 1;
	printf("Enter text: \n");
	
	while (keystrokes != '\n') {     //every keystroke is a "click" on the clicker
		scanf("%c", &keystrokes);
		clicker++;
	}

	if ((clicker & 1) == 0) { printf("Your text's length is even"); } //bitwise operation because rightmost digit of odd length is 1
	else {printf("Your text's length is odd"); }
