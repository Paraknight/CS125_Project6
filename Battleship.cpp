/* CS 125 - Intro to Computer Science II
 * File Name: CS125_Project6.cpp
 * Project 6 - Due 4/24/2019
 * Instructor: Dr. Dan Grissom
 *
 * Name 1: Brandon Watanabe
 * Name 2: Mina Andjelkovic
 * Description: Making Battleship in Java using 2D arrays, array lists, and maps in C++.
 */
using namespace std;
#include <iostream>
#include <vector>
#include <map>

void printGrid();
void printBoard();

vector<int> guesses;
vector<string> rowCol;
​
map<string, int> history;
​
string grid[7][7];
string board[7][7];
​
int main() {
	cout << "Brandon Watanabe & Mina Andjelkovic" << endl;
	cout << "Project 6" << endl << endl;
​
	int srtRw;
	int srtCo;
	int row;
	int col;
	int guess = 0;
	string extend;
	int alive = 0;
	int guessed = 0;
	bool yeet = true;
	bool oof = true;
	string coor = to_string(row) + ", " + to_string(col);

	cout << "---------------  Welcome to Battleship!  ---------------" << endl;
​
	for (int i = 0; i < 7; i++) {
		for(int j = 0; j < 7; j++) {
			grid[i][j] = board[i][j] = "\t-";
​
		}
	}
	printGrid();

	do {
		cout << "Please enter coordinates for ship of length 2:" << endl;
		cout << "Starting Row (0-6):" << endl;
		cin >> srtRw;
		cout << "Starting Column (0-6)" << endl;
		cin >> srtCo;
		grid[srtRw][srtCo] = "\tS";
		cout << "From the starting point, extend down or right? (d/r):";
		cin >> extend;
​
		if (extend == "d") {
			grid[srtRw+1][srtCo] = "\tS";
			cout << "r\\c\t0\t1\t2\t3\t4\t5\t6" << endl;
			for(int i = 0; i < 7; i++) {
				cout << i;
				for (int j = 0; j < 7; j++) {
					cout << grid[i][j];
				}
				cout << endl;
			}
			yeet = false;
		}

		else {
			grid[srtRw][srtCo+1] = "\tS";
			cout << "r\\c\t0\t1\t2\t3\t4\t5\t6" << endl;
			for(int i = 0; i < 7; i++) {
				cout << i;
				for (int j = 0; j < 7; j++) {
					cout << grid[i][j];
				}
				cout << endl;
			}
			yeet = false;
		}
	} while (yeet);
​

	do {
		cout << "Please enter coordinates for ship of length 3:" << endl;
		cout << "Starting Row (0-6):" << endl;
		cin >> srtRw;
		cout << "Starting Column (0-6)" << endl;
		cin >> srtCo;
		grid[srtRw][srtCo] = "\tS";
		cout << "From the starting point, extend down or right? (d/r):" << endl;
		cin >> extend;
​
		if (extend == "d") {
			grid[srtRw+1][srtCo] = "\tS";
			grid[srtRw+2][srtCo] = "\tS";
			printGrid();
			yeet = false;
		}

		else {
			grid[srtRw][srtCo+1] = "\tS";
			grid[srtRw][srtCo+2] = "\tS";
			printGrid();
			yeet = false;
		}
	} while (yeet);
​
	do {
		cout << "Please enter coordinates for ship of length 4:" << endl;
		cout << "Starting Row (0-6):" << endl;
		cin >> srtRw;
		cout << "Starting Column (0-6)" << endl;
		cin >> srtCo;
		grid[srtRw][srtCo] = "\tS";
		cout << "From the starting point, extend down or right? (d/r):" << endl;
		cin >> extend;
​
		if (extend == "d") {
			grid[srtRw+1][srtCo] = "\tS";
			grid[srtRw+2][srtCo] = "\tS";
			grid[srtRw+3][srtCo] = "\tS";
			printGrid();
			yeet = false;
		}

		else {
			grid[srtRw][srtCo+1] = "\tS";
			grid[srtRw][srtCo+2] = "\tS";
			grid[srtRw][srtCo+3] = "\tS";
			printGrid();
			yeet = false;
		}
	} while (yeet);

​
	for (int i = 0; i < 12; i++){
		if (i == 10){
			cout << "---------------  Begin!  ---------------" << endl;
		}
		else {
			cout << endl;
		}
	}

	for (int i = 0; i < 7; i++) {
		for(int j = 0; j < 7; j++) {
			board[i][j] = "\t-";
		}
	}
	printBoard();
​
	cout << "------------------------------------------------------------------" << endl;
​
	do {
		guess++;
		cout << "Guess number " << guess << "..." << endl;
		cout << "Guess a row (0-6):" << endl;
		cin >> row;
		cout << "Guess a column (0-6):" << endl;
		cin >> col;

		if (grid[row][col] == "\tS" && history.find(coor) == history.end()) {
			board[row][col] = "\tX";
			cout << "HIT!" << endl;
			cout << endl;

			alive++;
			printBoard();
		}
​
		else if (history.find(coor) != history.end()) {

			guessed++;
			cout << "r\\c=" + to_string(row) + "\\" + to_string(col) + " has already been guessed " + to_string(guessed) + " time" << endl;
		}
​
		else {
			board[row][col] = "\tm";
			cout << "MISS!" << endl;
			cout << endl;
			printBoard();
		}
​
		guesses.push_back(guess);

		rowCol.push_back(coor);
​
		history.insert({coor, guess});
​
		if (alive > 8)
			oof = false;
​
	} while (oof);
​
	cout << "Congratulations, you've sunk all the battleships!" << endl;
	cout << "You made a total of " << guess << " guesses, listed as follows:" << endl;
	cout << "Guess   | Row   Col"<< endl;
	cout << "-------------------------" << endl;
​
	return 0;
}
void printGrid() {

	cout << "r\\c\t0\t1\t2\t3\t4\t5\t6" << endl;

	for (int i = 0; i < 7; i++) {
		cout << i;
		for(int j = 0; j < 7; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}
​
void printBoard(){

	cout << "r\\c\t0\t1\t2\t3\t4\t5\t6" << endl;
	for (int i = 0; i < 7; i++) {
		cout << i;
		for(int j = 0; j < 7; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}
