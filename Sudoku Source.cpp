//Included Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>

// Defining Custom Macros
#define green(); system("color 0a");
#define red(); system("color 0c");
#define purple(); system("color 0d");
#define white(); system("color 4f");
#define yellow(); system("color 0e");
#define pause(); cout<<endl;system("pause");
#define clear(); system("cls");
#define quit(); exit(0);
#define line(); cout<<endl;

using namespace std;

char arraySudokuUnsolved[9][9];
char arraySudokuSolved[9][9];

void intro();
void rules();
void stageForfeit();
void boardSudokuSolved(string);
void boardSudokuUnsolved(string,unsigned short int);
void boardInput(unsigned short int,unsigned short int);
void end(int);

int main() {
	
	unsigned short int generateTable;
	unsigned short int maxEmptySpaces;
	string fileNamePuzzle;
	string fileNameSolved;
	char choice;

	intro();

	cout << "Enter 1 for Rules and 2 to play the game:";
	choice=getche();
	_sleep(5);
	if(choice == '1'){
		rules();
	}else if (choice == '2'){
		line();
	}else if (choice != '1' || choice!= '2'){
		clear();
		red();
		cout << "It's the beginning of the game and you're already providing wrong inputs?" line();
		cout << "Good luck in the game. Anyways, re-enter the number. either 1 or 2. No in-between." line() line();
		cout << "The program will now restart.";
		line() pause();
		main();
	}
	clear();
	red();
	cout << "Input a number to generate a Sudoku Table(between 1 and 10):";
	cin >> generateTable;
	
	while (generateTable > 10 || generateTable<=0){
		clear();
		cout << "Sorry, but due to lack of resources we can only generate\nupto 10 different Sudoku puzzles and" line();
		cout << "we cannot generate a table for 0 or less than 0. So," line() line();
		cout << "Please input a number that is between 1 and 10 so we can generate\na table for you to solve." line();
		cin >> generateTable;
	}

	if (generateTable == 1){
		fileNamePuzzle="SudokuPuzzle1.txt";
		fileNameSolved="SudokuPuzzle1 - Solved.txt";
		maxEmptySpaces = 43;
	}else if (generateTable == 2){
		fileNamePuzzle="SudokuPuzzle2.txt";
		fileNameSolved="SudokuPuzzle2 - Solved.txt";
		maxEmptySpaces = 40;
	}else if (generateTable == 3){
		fileNamePuzzle="SudokuPuzzle3.txt";
		fileNameSolved="SudokuPuzzle3 - Solved.txt";
		maxEmptySpaces = 41;
	}else if (generateTable == 4){
		fileNamePuzzle="SudokuPuzzle4.txt";
		fileNameSolved="SudokuPuzzle4 - Solved.txt";
		maxEmptySpaces = 41;
	}else if (generateTable == 5){
		fileNamePuzzle="SudokuPuzzle5.txt";
		fileNameSolved="SudokuPuzzle5 - Solved.txt";
		maxEmptySpaces = 41;
	}else if (generateTable == 6){
		fileNamePuzzle="SudokuPuzzle6.txt";
		fileNameSolved="SudokuPuzzle6 - Solved.txt";
		maxEmptySpaces = 36;
	}else if (generateTable == 7){
		fileNamePuzzle="SudokuPuzzle7.txt";
		fileNameSolved="SudokuPuzzle7 - Solved.txt";
		maxEmptySpaces = 42;
	}else if (generateTable == 8){
		fileNamePuzzle="SudokuPuzzle8.txt";
		fileNameSolved="SudokuPuzzle8 - Solved.txt";
		maxEmptySpaces = 40;
	}else if (generateTable == 9){
		fileNamePuzzle="SudokuPuzzle9.txt";
		fileNameSolved="SudokuPuzzle9 - Solved.txt";
		maxEmptySpaces = 42;
	}else if (generateTable == 10){
		fileNamePuzzle="SudokuPuzzle10.txt";
		fileNameSolved="SudokuPuzzle10 - Solved.txt";
		maxEmptySpaces = 38;
	}
	
	boardSudokuUnsolved(fileNamePuzzle, generateTable);
	boardSudokuSolved(fileNameSolved);
	boardInput(generateTable,maxEmptySpaces);
	end(generateTable);
	
	//Ending Portion.
	line();
	cout << "Thank You for playing this game. Hope you loved it!" line();
	getch();
	pause();
	quit();
}

void intro(){

	clear();
	line();
	green();

	cout << "\t\t\t\tWelcome to Sudoku.\n\t\t\t\tDeveloped by:" line() line();
	cout << "\t\tAli Taqi Wajid.   \t|\t\t 190792" line();
	cout << "\t\tUsama Bin Muneer. \t|\t\t 190824" line();
	cout << "\t\tAliza Naveed.     \t|\t\t 190778" line();
	cout << "\t\tAmal Abrar.       \t|\t\t 190787" line() line();
}

void rules(){

	clear();
	purple();
	cout << "\t\t\t\t RULES:" line() line() line();
	red();
	cout << "1. Each row, column, and nonet can contain each number (typically 1 to 9) exactly once." line() line();
	cout << "2. The sum of all numbers in any nonet, row, or column must match the small number printed in its corner." line();
	cout << "For traditional Sudoku puzzles featuring the numbers 1 to 9, this sum is equal to 45." line() line() line();
	pause();
	clear();
	white();
	cout << "One more thing. If at any stage you fail or just give up, which you most probably will," line();
	cout << "I have added a forfeit feature. You just type q or Q at any stage and you will be taken out of your misery." line() line();
	pause();
}

void stageForfeit(){
	clear();
	white();
	cout << "It seems like this game is not meant for you anyways." line();
	cout << "Anyways, it was good to have you here. Hope you come back when you've learnt how to play this game." line();
	pause();
	quit();
}

void boardSudokuSolved(string fileNameSolved){

	ifstream boardSolved(fileNameSolved);

	for (int i=0; i<9; i++){
		for (int j=0; j<9; j++){
			boardSolved >> arraySudokuSolved[i][j];
		}
	}
	boardSolved.close();
}

void boardSudokuUnsolved(string fileName, unsigned short int tableNumber){

	ifstream board(fileName);
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			board >> arraySudokuUnsolved[i][j];
		}
	}

	board.close();
	
}

void boardInput(unsigned short int tableNumber, unsigned short int maxEmptySpaces){
	
	unsigned short int row;
	unsigned short int col;
	char temp;
	char store1;
	char store2;

	for (int z=0; z<maxEmptySpaces;){
	green();
	clear();
	cout << "\t\t\t\t Table Number: "<< tableNumber << "\t\t\t\t\tRemaining Empty Spaces: "<< maxEmptySpaces-z line() line();
	cout << "\t\t\t Type in q or Q to forfeit at anytime. " line() line();
	for(int i=0; i<9; i++){
			if (i==0){
				cout << "\t\t\t-------------------------------------";	
				line();
			}
		for(int j=0; j<9; j++){
			if (j==0){
				cout << "\t\t\t| ";
			}
			cout << arraySudokuUnsolved[i][j] << " | ";
		}
		line();
		cout << "\t\t\t-------------------------------------";
		line();
	}
	line();
	cout << "Enter the row where you want to enter your desired number: (1-9): ";
	store1 = getch();
	cout << store1 line();
	
	if (store1=='q' || store1=='Q'){
		stageForfeit();
	}

	while (store1 < '1' || store1 > '9'){
		red();
		cout << "Invalid input. Please try again : ";
		store1=getch();
		cout << store1 line();
		if (store1=='q' || store1=='Q'){
			stageForfeit();
		}
	}

	green();
	cout << "Enter the column where you want to enter your desired number: (1-9): ";
	store2 = getch();
	cout << store2 line();
	
	if (store2=='q' || store2=='Q'){
		stageForfeit();
	}
	
	while (store2 < '1' || store2 > '9'){
		red();
		cout << "Invalid input. Please try again : ";
		store2 = getch();
		cout << store2 line();
		if (store2=='q' || store2=='Q'){
			stageForfeit();
		}
	}

	row= store1 - 48;
	col = store2 - 48;
	row=row-1;
	col=col-1;

	if (arraySudokuUnsolved[row][col]=='_'){
		green();
		cout << "Enter value you want to enter at ("<< row+1 << "," << col+1 << "): ";
		temp = getch();
		cout << temp line();
		if(temp=='q' || temp == 'Q'){
			stageForfeit();
		}else{
		while(temp != arraySudokuSolved[row][col]){
			red();
			line();
			cout << "This value isn't supposed to be here.. Try again and think harder: ";
			temp = getch();
			cout << temp;
			if(temp=='q' || temp == 'Q'){
			stageForfeit();
			}
		}
		arraySudokuUnsolved[row][col]=temp;
		z++;
		}
	}else if (arraySudokuUnsolved[row][col]!='_'){
		red();
		line();
		cout <<"\t\t" << arraySudokuUnsolved[row][col] << " already exists at (" << row+1 << "," << col+1 <<  ")." line();
		pause();
	}
	}
	pause();
}

void end(int tableNumber){
	clear();
	yellow();
	cout << "\t\t\t\t Table Number: "<< tableNumber line() line();
	for(int i=0; i<9; i++){
			if (i==0){
				cout << "\t\t\t-------------------------------------";	
				line();
			}
		for(int j=0; j<9; j++){
			if (j==0){
				cout << "\t\t\t| ";
			}
			cout << arraySudokuUnsolved[i][j] << " | ";
		}
		line();
		cout << "\t\t\t-------------------------------------";
		line();
	}
	line() line() line();
	purple();
	cout << "Congratulations! You have successfully solved this puzzle." line();
	getch();
	getch();
}
