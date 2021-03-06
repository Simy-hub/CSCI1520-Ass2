//assig5.cpp
/*CSCI1520
 *Assignment: 5
 */

#include <iostream>
#include <iomanip>   
using namespace std;

const int SIZE = 8;

void display_board(char board[SIZE][SIZE], int& Zebr, int& attack, int& free);
void update_board(int &row,int &col,bool flag, char board[SIZE][SIZE], int& Zebr, int& attack, int& free);
bool check_moves(int col, int row, char board[SIZE][SIZE], int& Zebr, int& attack, int& free);
void trans(char inpute_letter, int inpute_number, int& row, int& col);

int main() {
	char board[SIZE][SIZE];
	int Zebr = 0, attack = 0, free = SIZE * SIZE;
	
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			board[i][j] = '.';

	display_board(board, Zebr, attack, free);
	while (free > 0) {
		int row = 0,col=0;
		bool flag = false;
		update_board(row, col, flag,board,Zebr,attack,free);
		check_moves(col, row, board, Zebr, attack, free);
		display_board(board, Zebr, attack, free);
	}
}

void trans(char inpute_letter, int inpute_number, int& row, int& col) {
	row = inpute_number;
	col = (int)(inpute_letter - 65);
}

void update_board(int& row, int& col,bool flag,char board[SIZE][SIZE],int &Zebr,int &attack,int &free) {
	char column_name = 'A';
	char inpute_letter;
	int inpute_number ;
	

	cout << "Put a zebrarider (col row): ";
	cin >> inpute_letter >> inpute_number;
	trans(inpute_letter, inpute_number, row, col);

	while (inpute_letter < column_name || inpute_letter >= column_name + SIZE || inpute_letter>90 || inpute_number < 0 || inpute_number >= SIZE) {
		cout << "Invalid. Try again!" << endl;
		cout << "Put a zebrarider (col row): ";
		cin >> inpute_letter >> inpute_number;
		trans(inpute_letter, inpute_number, row, col);
	}
	flag = check_moves(col, row, board, Zebr, attack, free);

	while (inpute_letter < column_name || inpute_letter >= column_name + SIZE ||inpute_letter>90|| inpute_number < 0 || inpute_number >=SIZE || flag == false) {
		cout << "Invalid. Try again!" << endl;
		cout << "Put a zebrarider (col row): ";
		cin >> inpute_letter >> inpute_number;
		trans(inpute_letter, inpute_number, row, col);

		flag=check_moves(col, row, board, Zebr, attack, free);
	}
	
	
	trans(inpute_letter, inpute_number, row, col);
}


void display_board(char board[][SIZE], int& Zebr, int& attack, int& free) {
	char column_name = 'A';

	cout << "   " << column_name;
	for (int i = 1; i < SIZE; i++) {
		column_name++;
		cout << " " << column_name;
	}
	cout << endl;
	for (int j = 0; j < SIZE; j++) {
		cout <<setw(2)<< j;
		for (int k = 0; k < SIZE; k++) {
			if (board[j][k] == '.')
				cout << " .";
			if (board[j][k] == 'Z')
				cout << " Z";
			if (board[j][k] == '=')
				cout << " =";

		}
		cout << endl;
	}
	cout << "Zebrariders: " << Zebr << endl;
	cout << "Attacked squares: " << attack << endl;
	cout << "Free squares: " << free<<endl;



}


bool check_moves(int col, int row, char board[SIZE][SIZE], int& Zebr, int& attack, int& free) {
	int updated_row = row, updated_col = col;
	int updated_Zebr = Zebr, updated_attack = attack, updated_free = free;
	char initial_board[SIZE][SIZE];
	for (int i = 0;i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			initial_board[i][j] = board[i][j];

	
	if (board[row][col] == 'Z') {
		return false;
	
	}
	else if (board[row][col] == '=') {
		updated_Zebr++;
		updated_attack--;
		board[row][col] = 'Z';
	}
	else if (board[row][col] == '.') {
		updated_Zebr++;
		updated_free --;
		board[row][col] = 'Z';
	}

	while (updated_row - 3 >= 0 && updated_col + 2 < SIZE) {
		updated_row -= 3;
		updated_col += 2;

		if (board[updated_row][updated_col] == '.') {
			board[updated_row][updated_col] = '=';
			updated_free--;
			updated_attack++;
		}
	}
	updated_row = row;
	updated_col = col;

	while (updated_row - 3 >= 0 && updated_col - 2 >= 0) {
		updated_row -= 3;
		updated_col -= 2;

		if (board[updated_row][updated_col] == '.') {
			board[updated_row][updated_col] = '=';
			updated_free--;
			updated_attack++;
		}
	}
	updated_row = row;
	updated_col = col;

	while (updated_row + 3 < SIZE && updated_col + 2 < SIZE) {
		updated_row += 3;
		updated_col += 2;

		if (board[updated_row][updated_col] == '.') {
			board[updated_row][updated_col] = '=';
			updated_free--;
			updated_attack++;
		}
	}
	updated_row = row;
	updated_col = col;

	while (updated_row + 3 < SIZE && updated_col - 2 >= 0) {
		updated_row += 3;
		updated_col -= 2;

		if (board[updated_row][updated_col] == '.') {
			board[updated_row][updated_col] = '=';
			updated_free--;
			updated_attack++;
		}
	}
	updated_row = row;
	updated_col = col;

	while (updated_row + 2 < SIZE && updated_col + 3 < SIZE) {
		updated_row += 2;
		updated_col += 3;

		if (board[updated_row][updated_col] == '.') {
			board[updated_row][updated_col] = '=';
			updated_free--;
			updated_attack++;
		}
	}
	updated_row = row;
	updated_col = col;

	while (updated_row + 2 < SIZE && updated_col - 3 >= 0) {
		updated_row += 2;
		updated_col -= 3;

		if (board[updated_row][updated_col] == '.') {
			board[updated_row][updated_col] = '=';
			updated_free--;
			updated_attack++;
		}
	}
	updated_row = row;
	updated_col = col;

	while (updated_row - 2 >= 0 && updated_col - 3 >= 0) {
		updated_row -= 2;
		updated_col -= 3;

		if (board[updated_row][updated_col] == '.') {
			board[updated_row][updated_col] = '=';
			updated_free--;
			updated_attack++;
		}
	}
	updated_row = row;
	updated_col = col;

	while (updated_row - 2 >= 0 && updated_col + 3 < SIZE) {
		updated_row -= 2;
		updated_col += 3;

		if (board[updated_row][updated_col] == '.') {
			board[updated_row][updated_col] = '=';
			updated_free--;
			updated_attack++;
		}
	}
	updated_row = row;
	updated_col = col;

	if (updated_free == free) {
		updated_row = row, updated_col = col;
		updated_Zebr = Zebr, updated_attack = attack, updated_free = free;
		board = initial_board;
		return false;
	}
		

	else{
		free = updated_free;
		attack = updated_attack;
		Zebr=updated_Zebr;
		return true;

	}
}
