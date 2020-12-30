#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> // For Colors only.
#include <conio.h>

// Defining macros
#define pause(); cout<<endl;system("pause");
#define clear(); system("cls");

using namespace std;

// Declaring the number of rows and columns to be constant
const int ROWS = 9;
const int COLS = 9;

// Color Codes for stdout.
const int colorGreen = 10;
const int colorCyan = 11;
const int colorRed = 12;
const int colorPurple = 13;
const int colorYellow = 14;
const int colorWhite = 15;
const int colorGrey = 8;
const int colorDblue = 9;

// Arrays that will hold the solved and unsolved tables.
char arraySudokuUnsolved[ROWS][COLS];
char arraySudokuSolved[ROWS][COLS];

/* FUNCTION PROTOTYPES */
bool checkTableFilesExist();// Checks whether table files exist or not.
void intro(); // Prints the intro screen
void rules(); // Prints the rules of the game.
void stageForfeit(); // Exits the game by printing a message.
void setColor(int); // Sets the color of the console.
void boardSudokuSolved(string); // Reads solved table from a file whose name is provided as an argument and stores in an array
void boardSudokuUnsolved(string); // Reads unsolved table from a file whose name is provided as an argument and stores in an array
void boardInput(int, int); // The main function that has the the implemented algorithm. Checks all inputs and verifies it.
void end(int); // Prints the end screen once the table has been completely solved.
void setDefault(string&, string&, int&); // Sets a default table so that if no tables are found, the program would still run.
// Parameters are passed as reference so that the filename for both solved and unsolved and maxemptyspaces are set without returning any value.

int main() {

	int generateTable; // User enters a number to generate a table from pre-defined table list.
	int maxEmptySpaces = 0; // The number of empty spaces in a table. -> Setting default to be 0 or NULL because we might send it as refernce later on in setDefault function
	string fileNamePuzzle; // Stores the name of the file that has the unsolved table
	string fileNameSolved; // Stores the name of the file that has the solved table
	char choice; // The user choice on the basis of which menu works.
	bool tablesExist = checkTableFilesExist(); // Checks if the tables exists and store the resultant value in a boolean variable.

	if (!tablesExist) // If the tables don't exist, 
		setDefault(fileNamePuzzle, fileNameSolved, maxEmptySpaces);

	intro(); // Prints the intro.

	cout << "---- NOTE: User input is being taken in through _getche() function so there's no need to press enter. Just enter the value.\n\n";

	setColor(colorDblue); // Sets Dark Blue color
	cout << "> 1 - Rules." << endl;
	setColor(colorGrey); // Sets Grey Color
	cout << "> 2 - Play the game." << endl;
	setColor(colorYellow); // Sets Yellow Color
	cout << "> Q - Exit the game." << endl;
	setColor(colorPurple); // Set Purple Color
	cout << "\n\nEnter Choice: ";
	choice = _getche(); // Takes user's input.

	switch (choice) {
	case '1':
		rules(); // Prints the rules
		break;
	case '2':
		break;
	case 'Q':
	case 'q':
		clear();
		setColor(colorCyan);
		cout << "It was good to have you here. Hope to see you soon.";
		pause();
		return 0;
	default:
		clear();
		setColor(colorRed);
		cout << "It's the beginning of the game and you're already providing wrong inputs?" << endl;
		cout << "Good luck in the game. Anyways, re-enter the number. either 1 or 2. No in-between." << endl << endl;
		setColor(colorYellow);
		cout << "The program will now restart.";
		cout << endl;
		pause();
		main();
	}

	clear();
	setColor(colorRed);
	cout << "Input a number to generate a Sudoku Table(between 1 and 10): ";
	cin >> generateTable;

	while (generateTable > 10 || generateTable <= 0) { // Keeps on taking input until a value between 0 and 10 is entered.
		clear();
		cout << "Sorry, but due to lack of resources we can only generate\nupto 10 different Sudoku puzzles and" << endl;
		cout << "we cannot generate a table for 0 or less than 0. So," << endl << endl;
		cout << "Please input a number that is between 1 and 10 so we can generate\na table for you to solve." << endl;
		cin >> generateTable;
	}

	if (tablesExist) {
		if (generateTable == 10) {
			fileNamePuzzle = "SudokuPuzzle10.txt";
			fileNameSolved = "SudokuPuzzle10 - Solved.txt";
			maxEmptySpaces = 38;
		}
		else {
			fileNamePuzzle = "SudokuPuzzle";
			fileNamePuzzle += (char)generateTable + 48; // Typecasting the integer into a character.
			fileNameSolved = fileNamePuzzle;
			fileNamePuzzle += ".txt";
			fileNameSolved += " - Solved.txt";
		}
		// maxEmptySpaces refer to the number of '_' in the actual table. On the basis of this, the solving algorithm is implemented.
		if (generateTable == 1)
			maxEmptySpaces = 43;
		else if (generateTable == 2)
			maxEmptySpaces = 40;
		else if (generateTable == 3)
			maxEmptySpaces = 41;
		else if (generateTable == 4)
			maxEmptySpaces = 41;
		else if (generateTable == 5)
			maxEmptySpaces = 41;
		else if (generateTable == 6)
			maxEmptySpaces = 36;
		else if (generateTable == 7)
			maxEmptySpaces = 42;
		else if (generateTable == 8)
			maxEmptySpaces = 40;
		else if (generateTable == 9)
			maxEmptySpaces = 42;
	}

	boardSudokuUnsolved(fileNamePuzzle);
	boardSudokuSolved(fileNameSolved);
	boardInput(generateTable, maxEmptySpaces);
	end(generateTable);

	//Ending Portion.
	cout << endl;
	cout << "Thank You for playing this game. Hope you loved it!" << endl;
	return 0;
}
bool checkTableFilesExist() {
	const int TOTAL_FILE_COUNT = 20; // Total number of file. 10 unsolved + 10 solved
	int error = 0; // If any error occurs, the value changes from zero to another number.
	string fileNames[20] =
	{
		"SudokuPuzzle1.txt", "SudokuPuzzle2.txt", "SudokuPuzzle3.txt", "SudokuPuzzle4.txt",
		"SudokuPuzzle5.txt", "SudokuPuzzle6.txt", "SudokuPuzzle7.txt", "SudokuPuzzle8.txt",
		"SudokuPuzzle9.txt", "SudokuPuzzle10.txt", "SudokuPuzzle1 - Solved.txt", "SudokuPuzzle2 - Solved.txt",
		"SudokuPuzzle3 - Solved.txt", "SudokuPuzzle4 - Solved.txt", "SudokuPuzzle5 - Solved.txt", "SudokuPuzzle6 - Solved.txt",
		"SudokuPuzzle7 - Solved.txt", "SudokuPuzzle8 - Solved.txt", "SudokuPuzzle9 - Solved.txt", "SudokuPuzzle10 - Solved.txt"
	};
	for (int i = 0; i < TOTAL_FILE_COUNT; i++) {
		ifstream file(fileNames[i]); // Loads each file
		if (!file) // Check if a file is accessible.
			error++; // Adds if the file isn't accessible.
	}
	return error == 0; // Returns a boolean value that is returned error == 0;
}
void intro() {
	// Prints the intro
	clear();
	setColor(colorRed);
	cout << endl << endl << endl;
	cout << "\t\t\t\t=================================\n";
	setColor(colorYellow);
	cout << "\t\t\t\t| Developed by TheFlash2k\t|\n";
	setColor(colorRed);
	cout << "\t\t\t\t=================================\n";
	cout << endl << endl;
	setColor(colorWhite);
}
void rules() {
	// Prints all the rules
	clear();
	setColor(colorCyan);
	cout << "\t\t\t\t RULES:" << endl << endl << endl;
	setColor(colorRed);
	cout << "1. Each row, column, and nonet can contain each number (typically 1 to 9) exactly once." << endl << endl;;
	cout << "2. The sum of all numbers in any nonet, row, or column must match the small number printed in its corner." << endl;
	cout << "For traditional Sudoku puzzles featuring the numbers 1 to 9, this sum is equal to 45." << endl << endl << endl;
	clear();
	setColor(colorWhite);
	cout << "One more thing. If at any stage you fail or just give up, which you most probably will," << endl;
	cout << "I have added a forfeit feature. You just type q or Q at any stage and you will be taken out of your misery." << endl << endl;
	pause();
}
void stageForfeit() {
	clear();
	setColor(colorDblue);
	cout << "It seems like this game is not meant for you anyways." << endl;
	setColor(colorPurple);
	cout << "Anyways, it was good to have you here. Hope you come back when you've learnt how to play this game." << endl;
	pause();
	exit(0);
}
void boardSudokuSolved(string fileNameSolved) {

	ifstream boardSolved(fileNameSolved);
	// Reads the data from file and stores in the global array.
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			boardSolved >> arraySudokuSolved[i][j];
		}
	}
	boardSolved.close();
}
void boardSudokuUnsolved(string fileName) {

	ifstream board(fileName);
	// Reads the data from file and stores in the global array.
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board >> arraySudokuUnsolved[i][j];
		}
	}
	board.close();

}
void boardInput(int tableNumber, int maxEmptySpaces) {

	int  row;  // User input row number
	int  col;  // User input column number
	char temp; // Stores temporary input
	char store1; // stores first input
	char store2; // stores second input

	for (int z = 0; z < maxEmptySpaces;) {
		setColor(colorCyan);
		clear();
		cout << "\t\t\t\t Table Number: " << tableNumber;
		setColor(colorRed);
		cout << "\t\t\t\t\tRemaining Empty Spaces: ";
		setColor(colorYellow);
		cout << maxEmptySpaces - z << endl << endl; // Prints the total remaining spaces.
		if (maxEmptySpaces - z < 10)
			setColor(colorRed);
		cout << "\t\t\t Type in q or Q to forfeit at anytime. " << endl << endl;
		setColor(colorGreen);
		for (int i = 0; i < 9; i++) {
			if (i == 0) {
				for (int a = 0; a < 9; a++) {
					setColor(colorCyan);
					if (a == 0)
						cout << "\t\t\t  ";
					cout << a + 1 << "   ";
				}
				cout << endl;
				setColor(colorRed);
				cout << "\t\t\t-------------------------------------" << endl;
			}
			for (int j = 0; j < 9; j++) {
				if (j == 0) {
					setColor(colorCyan);
					cout << "\t\t      " << i + 1;
					setColor(colorRed);
					cout << " | ";
				}
				setColor(colorGreen);
				cout << arraySudokuUnsolved[i][j];
				setColor(colorRed);
				cout << " | ";
			}
			cout << endl;
			cout << "\t\t\t-------------------------------------" << endl;
		}
		cout << endl;
		setColor(colorDblue);
		cout << "Enter the row where you want to enter your desired number: (1-9): ";
		store1 = _getche();
		cout << endl;

		if (store1 == 'q' || store1 == 'Q')
			stageForfeit();

		while (store1 < '1' || store1 > '9') {
			setColor(colorRed);
			cout << "Invalid input. Please try again : ";
			store1 = _getche();
			cout << endl;
			if (store1 == 'q' || store1 == 'Q')
				stageForfeit();
		}

		setColor(colorGreen);
		cout << "Enter the column where you want to enter your desired number: (1-9): ";
		store2 = _getche();
		cout << endl;

		if (store2 == 'q' || store2 == 'Q')
			stageForfeit();

		while (store2 < '1' || store2 > '9') {
			setColor(colorRed);
			cout << "Invalid input. Please try again : ";
			store2 = _getche();
			cout << endl;
			if (store2 == 'q' || store2 == 'Q')
				stageForfeit();
		}

		// Type casting from char into int
		row = store1 - 48;
		col = store2 - 48;
		// subtracting 1 from each because indexing in arrays start from 0
		row = row - 1;
		col = col - 1;

		if (arraySudokuUnsolved[row][col] == '_') {
			setColor(colorPurple);
			cout << "Enter value you want to enter at (" << row + 1 << "," << col + 1 << "): ";
			temp = _getche();
			cout << endl;

			if (temp == 'q' || temp == 'Q')
				stageForfeit();
			else {
				while (temp != arraySudokuSolved[row][col]) {
					setColor(colorRed);
					cout << endl;
					cout << "This value isn't supposed to be here.. Try again and think harder: ";
					temp = _getche();

					if (temp == 'q' || temp == 'Q') {
						stageForfeit();
					}
				}

				arraySudokuUnsolved[row][col] = temp;
				z++;
			}
		}
		else if (arraySudokuUnsolved[row][col] != '_') {
			setColor(colorRed);
			cout << endl;
			cout << "\t\t\t\t" << arraySudokuUnsolved[row][col] << " already exists at (" << row + 1 << "," << col + 1 << ")." << endl;
			setColor(colorGreen);
			pause();
		}
	}
	pause();
}
void setDefault(string& fileUnSolved, string& fileSolved, int& emptySpaces) {
	fileUnSolved = "default.txt";
	fileSolved = "default-solved.txt";
	emptySpaces = 36;
	char unsolved[9][9] = // Has an entire unsolved table
	{
		{'9', '2', '1', '6', '5', '_', '_', '_', '8'},
		{'6', '4', '8', '1', '9', '_', '_', '_', '5'},
		{'3', '_', '7', '4', '8', '2', '9', '6', '_'},
		{'_', '7', '3', '_', '6', '_', '8', '_', '4'},
		{'8', '_', '_', '_', '7', '_', '5', '_', '_'},
		{'_', '9', '_', '_', '4', '8', '_', '7', '_'},
		{'4', '_', '6', '_', '2', '_', '3', '_', '7'},
		{'_', '_', '_', '_', '_', '6', '_', '8', '_'},
		{'7', '_', '9', '8', '3', '4', '6', '_', '2'}
	};

	char solved[9][9] = // Has an entire solved table
	{
		{'9', '2', '1', '6', '5', '3', '7', '4', '8'},
		{'6', '4', '8', '1', '9', '7', '2', '3', '5'},
		{'3', '5', '7', '4', '8', '2', '9', '6', '1'},
		{'1', '7', '3', '5', '6', '9', '8', '2', '4'},
		{'8', '6', '4', '2', '7', '1', '5', '9', '3'},
		{'5', '9', '2', '3', '4', '8', '1', '7', '6'},
		{'4', '8', '6', '9', '2', '5', '3', '1', '7'},
		{'2', '3', '5', '7', '1', '6', '4', '8', '9'},
		{'7', '1', '9', '8', '3', '4', '6', '5', '2'}
	};
	ofstream writer;
	// Writing the unsolved table to a file.
	writer.open(fileUnSolved);
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			writer << unsolved[i][j];
			if (j != COLS - 1) // Will add a space after the character except the last character
				writer << " ";
		}
		if (i != ROWS - 1) // Will a add a newline after every line except the last line
			writer << endl;
	}
	writer.close();
	// Writing the solved table to a file
	writer.open(fileSolved);
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			writer << solved[i][j] << " ";
			if (j != COLS - 1) // Will add a space after the character except the last character
				writer << " ";
		}
		if (i != ROWS - 1) // Will a add a newline after every line except the last line
			writer << endl;
	}
	writer.close();
}
void end(int tableNumber) {
	// Prints the ending credits.
	clear();
	setColor(colorYellow);
	cout << "\t\t\t\t Table Number: " << tableNumber << endl << endl;

	for (int i = 0; i < ROWS; i++) {

		if (i == 0) {
			setColor(colorRed);
			cout << "\t\t\t-------------------------------------" << endl;
		}

		for (int j = 0; j < COLS; j++) {
			setColor(colorRed);
			cout << "\t\t\t| ";
			setColor(colorGreen);
			cout << arraySudokuUnsolved[i][j];
			setColor(colorRed);
			cout << " | ";
		}
		cout << endl;
		cout << "\t\t\t-------------------------------------" << endl;
	}
	cout << endl << endl << endl;
	setColor(colorCyan);
	cout << "Congratulations! You have successfully solved this puzzle." << endl;
	cin.get();
}
void setColor(int color = colorWhite) {
	// If no color is specified, the color is set to white.
	HANDLE conHandler = GetStdHandle(STD_OUTPUT_HANDLE); // Gets a console handler from windows.h api
	SetConsoleTextAttribute(conHandler, color); // sets the console color.
}
