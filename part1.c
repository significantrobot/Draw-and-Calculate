///HAVE ONE TOO LONG

	int i = 0; //rows
	int j = 0; //columns
	int input = 0;
	int k = 0; // this will be used to calculate the distance from the rightmost wall and the "/" character in the box
	printf("Enter a number: ");
	scanf("%i", &input);

	int dimension = (input * 2) + 1; // the dimension of the box, 2x + 1, declared only after "input" is defined.

	  //*
	  //when input is 0, we want to only print "X"
	  //*

	if (input == 0) {
		printf("X\n");
	}

	//*
	//otherwise:
	//this operation is designed to enable the computer to view the box as a matrix and print the desired character from left to right
	//as it goes across rows and columns:   row1/column1, row1/column2.....row2/column1....row(dimension)/column(dimension)
	//short review of the conditions:
	// - for row 1 and (dimension), print "-"
	// - in corners, print "+"
	// - when i = j, print "\"
	// - when j = (dimension - desired distance), print "/". variable k is used in the calculation
	// - print "X" in the middle
	//*

	if (input > 0) {                                //0 is defined above
		for (i = 1; i <= dimension; i++, ++k) {     //counting rows
			for (j = 1; j <= dimension; j++)        //counting columns
			{
				if (i == 1 && j == 1) { printf("+"); }
				if (j != i && i == 1 && j < dimension) { printf("-"); }
				if (i == 1 && j == dimension) { printf("+\n"); }
				if (i != 1 && i != dimension && j == 1) { printf("|"); }
				if (j != (dimension - k) && j != 1 && j != dimension && i != 1 && i != dimension && i != j && 1 < i < dimension && 1 < j < dimension) { printf(" "); }
				if (i != ((dimension + 1) / 2) && j != ((dimension + 1) / 2) && i != 1 && i != dimension && i == j) { printf("\\"); }
				if (i != 1 && i != dimension && j == dimension) { printf("|\n"); }
				if (i != ((dimension + 1) / 2) && j != ((dimension + 1) / 2) && i != 1 && j != dimension && ((i + j) == (dimension + 1)) && i != dimension && j != dimension && j == (dimension - k)) { printf("/"); }
				if (i == j && (i + j) == (dimension + 1)) { printf("X"); }
				if (i == dimension && j == 1) { printf("+"); }
				if (i != j && i == dimension && j != 1 && j < dimension) { printf("-"); }
				if (i == dimension && j == dimension) { printf("+\n"); }
			}
		}
	}
