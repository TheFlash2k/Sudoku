#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> // For Colors only.
#include <conio.h>

#define pause(); cout<<endl;system("pause");
#define clear(); system("cls");

using namespace std;

const int colorGreen = 10;
const int colorCyan  = 11;
const int colorRed   = 12;
const int colorPurple= 13;
const int colorYellow= 14;
const int colorWhite = 15;
const int colorGrey  = 8;
const int colorDblue = 9;

char arraySudokuUnsolved[9][9];
char arraySudokuSolved[9][9];

bool checkTableFilesExist();
void intro();
void rules();
void stageForfeit();
void setColor(int);
void boardSudokuSolved(string);
void boardSudokuUnsolved(string);
void boardInput(unsigned short int,unsigned short int);
void end(int);

int main() {
	
	unsigned short int generateTable;
	unsigned short int maxEmptySpaces;
	string fileNamePuzzle;
	string fileNameSolved;
	char choice;
	
	checkTableFilesExist();
	if(!checkTableFilesExist()){
		setColor(colorRed);
		cout << "One or more table files that are necessary for this game to run don't exist." << endl;
		cout << "In order to get those files, visit the github: " << endl << endl;
		cout << "\t\thttps://github.com/TheFlash2k/Sudoku/" << endl << endl;
		setColor(colorGreen);
		pause();
		exit(0);
	}
	
	intro();

	setColor(colorDblue);
	cout << "> 1 - Rules." << endl;
	setColor(colorGrey);
	cout << "> 2 - Play the game." << endl;
	setColor(colorYellow);
	cout << "> Q - Exit the game." << endl;
	setColor(colorPurple);
	cout << "\n\nEnter Choice: ";
	choice=getche();
	_sleep(50);
	if(choice == '1') {
		rules();
	} else if (choice == '2') {
		cout << endl;
	} else if (choice == 'Q' || choice == 'q') {
		clear();
		setColor(colorCyan);
		cout << "It was good to have you here. Hope to see you soon.";
		_sleep(1500);
		exit(0);
	}
	else if (choice != '1' || choice!= '2' || choice!='q' || choice!='Q') {
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
	
	while (generateTable > 10 || generateTable <= 0) {
		clear();
		cout << "Sorry, but due to lack of resources we can only generate\nupto 10 different Sudoku puzzles and" << endl;
		cout << "we cannot generate a table for 0 or less than 0. So," << endl << endl;
		cout << "Please input a number that is between 1 and 10 so we can generate\na table for you to solve." << endl;
		cin >> generateTable;
	}

	if (generateTable == 1) {
		fileNamePuzzle="SudokuPuzzle1.txt";
		fileNameSolved="SudokuPuzzle1 - Solved.txt";
		maxEmptySpaces = 43;
	}else if (generateTable == 2) {
		fileNamePuzzle="SudokuPuzzle2.txt";
		fileNameSolved="SudokuPuzzle2 - Solved.txt";
		maxEmptySpaces = 40;
	}else if (generateTable == 3) {
		fileNamePuzzle="SudokuPuzzle3.txt";
		fileNameSolved="SudokuPuzzle3 - Solved.txt";
		maxEmptySpaces = 41;
	}else if (generateTable == 4) {
		fileNamePuzzle="SudokuPuzzle4.txt";
		fileNameSolved="SudokuPuzzle4 - Solved.txt";
		maxEmptySpaces = 41;
	}else if (generateTable == 5) {
		fileNamePuzzle="SudokuPuzzle5.txt";
		fileNameSolved="SudokuPuzzle5 - Solved.txt";
		maxEmptySpaces = 41;
	}else if (generateTable == 6) {
		fileNamePuzzle="SudokuPuzzle6.txt";
		fileNameSolved="SudokuPuzzle6 - Solved.txt";
		maxEmptySpaces = 36;
	}else if (generateTable == 7) {
		fileNamePuzzle="SudokuPuzzle7.txt";
		fileNameSolved="SudokuPuzzle7 - Solved.txt";
		maxEmptySpaces = 42;
	}else if (generateTable == 8) {
		fileNamePuzzle="SudokuPuzzle8.txt";
		fileNameSolved="SudokuPuzzle8 - Solved.txt";
		maxEmptySpaces = 40;
	}else if (generateTable == 9) {
		fileNamePuzzle="SudokuPuzzle9.txt";
		fileNameSolved="SudokuPuzzle9 - Solved.txt";
		maxEmptySpaces = 42;
	}else if (generateTable == 10) {
		fileNamePuzzle="SudokuPuzzle10.txt";
		fileNameSolved="SudokuPuzzle10 - Solved.txt";
		maxEmptySpaces = 38;
	}
	
	boardSudokuUnsolved(fileNamePuzzle);
	boardSudokuSolved(fileNameSolved);
	boardInput(generateTable,maxEmptySpaces);
	end(generateTable);
	
	//Ending Portion.
	cout << endl;
	cout << "Thank You for playing this game. Hope you loved it!" << endl;
	_sleep(1500);
	exit(0);
}

bool checkTableFilesExist() {
	int fileCheckCount=0;
	string fileNames[20] = {
		"SudokuPuzzle1.txt", "SudokuPuzzle2.txt", "SudokuPuzzle3.txt", "SudokuPuzzle4.txt",
		"SudokuPuzzle5.txt", "SudokuPuzzle6.txt", "SudokuPuzzle7.txt", "SudokuPuzzle8.txt",
		"SudokuPuzzle9.txt", "SudokuPuzzle10.txt", "SudokuPuzzle1 - Solved.txt", "SudokuPuzzle2 - Solved.txt",
		"SudokuPuzzle3 - Solved.txt", "SudokuPuzzle4 - Solved.txt", "SudokuPuzzle5 - Solved.txt", "SudokuPuzzle6 - Solved.txt",
		"SudokuPuzzle7 - Solved.txt", "SudokuPuzzle8 - Solved.txt", "SudokuPuzzle9 - Solved.txt", "SudokuPuzzle10 - Solved.txt"
	};
	for(int i=0; i<20; i++) {
		ifstream file(fileNames[i]);
		if(!file) {
			fileCheckCount++;
		}
	}
	if(fileCheckCount==0) {
		return true;		
	} else {
		return false;
	}
}

void intro() {

	clear();
	setColor(colorRed);
	cout << endl << endl << endl;

	cout << "\t\t\t**************************************" << endl;
	cout << "\t\t\t**************************************" << endl;
	cout << "\t\t\t*		                     *" << endl;
	cout << "\t\t\t*       ";
	setColor(colorYellow);
	cout << "Developed by TheFlash2k      ";
	setColor(colorRed);
	cout << "*" << endl;
	cout << "\t\t\t*			     	     *" << endl;
	cout << "\t\t\t**************************************" << endl;
	cout << "\t\t\t**************************************" << endl;
	cout << endl << endl;
	setColor(colorWhite);
}

void rules() {

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

	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			boardSolved >> arraySudokuSolved[i][j];
		}
	}
	boardSolved.close();
}

void boardSudokuUnsolved(string fileName) {

	ifstream board(fileName);
	
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			board >> arraySudokuUnsolved[i][j];
		}
	}
	board.close();
	
}

void boardInput(unsigned short int tableNumber, unsigned short int maxEmptySpaces) {
	
	unsigned short int row;
	unsigned short int col;
	char temp;
	char store1;
	char store2;

	for (int z=0; z<maxEmptySpaces;) {
	setColor(colorCyan);
	clear();
	cout << "\t\t\t\t Table Number: "<< tableNumber;
	setColor(colorRed);
	cout << "\t\t\t\t\tRemaining Empty Spaces: ";
	setColor(colorYellow);
	cout << maxEmptySpaces-z << endl << endl;
	if(maxEmptySpaces-z < 10) {
		setColor(colorRed);
	}
	cout << "\t\t\t Type in q or Q to forfeit at anytime. " << endl << endl;
	setColor(colorGreen);
		for(int i=0; i<9; i++) {
			if (i==0) {
				for(int a=0; a<9; a++){
					setColor(colorCyan);
					if(a==0) {
					cout << "\t\t\t  ";
					}
					cout << a+1 << "   ";
				}
				cout << endl;
				setColor(colorRed);
				cout << "\t\t\t-------------------------------------" << endl;
			}
			for(int j=0; j<9; j++) {
				if (j==0){
					setColor(colorCyan);
					cout << "\t\t      " << i+1;
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
		store1 = getche();
		cout << endl;
		
		if (store1=='q' || store1=='Q') {
			stageForfeit();
		}

		while (store1 < '1' || store1 > '9') {
			setColor(colorRed);
			cout << "Invalid input. Please try again : ";
			store1=getche();
			cout << endl;
			if (store1=='q' || store1=='Q') {
				stageForfeit();
			}
		}

		setColor(colorGreen);
		cout << "Enter the column where you want to enter your desired number: (1-9): ";
		store2 = getche();
		cout << endl;

		if (store2=='q' || store2=='Q') {
			stageForfeit();
		}
	
		while (store2 < '1' || store2 > '9') {
			setColor(colorRed);
			cout << "Invalid input. Please try again : ";
			store2 = getche();
			cout << endl;
			if (store2=='q' || store2=='Q') {
				stageForfeit();
			}
		}

		row= store1 - 48;
		col = store2 - 48;
		row=row-1;
		col=col-1;

		if (arraySudokuUnsolved[row][col]=='_') {
			setColor(colorPurple);
			cout << "Enter value you want to enter at ("<< row+1 << "," << col+1 << "): ";
			temp = getche();
			cout << endl;
			
			if (temp=='q' || temp == 'Q') {
				stageForfeit();
			} else {
				while (temp != arraySudokuSolved[row][col]) {
					setColor(colorRed);
					cout << endl;
					cout << "This value isn't supposed to be here.. Try again and think harder: ";
					temp = getche();
				
					if(temp=='q' || temp == 'Q') {
						stageForfeit();
					}
				}
				
				arraySudokuUnsolved[row][col]=temp;
				z++;
			}
		} else if (arraySudokuUnsolved[row][col]!='_') {
			setColor(colorRed);
			cout << endl;
			cout <<"\t\t\t\t" << arraySudokuUnsolved[row][col] << " already exists at (" << row+1 << "," << col+1 <<  ")." << endl;
			setColor(colorGreen);
			pause();
		}
	}
	pause();
}

void end(int tableNumber) {
	clear();
	setColor(colorYellow);
	cout << "\t\t\t\t Table Number: "<< tableNumber << endl << endl;
	
	for(int i=0; i<9; i++) {
	
		if (i==0) {
			setColor(colorRed);
			cout << "\t\t\t-------------------------------------" << endl;
		}
		
		for(int j=0; j<9; j++) {
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
	getch();
	getch();
}

void setColor(int color = colorWhite) {
	HANDLE conHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(conHandler, color);
}
