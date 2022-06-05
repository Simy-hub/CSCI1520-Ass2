//assig4.cpp
/*CSCI1520
 *Assignment: 4
 */


#include <iostream>
using namespace std;

// Named constants for state of grid positions
const int EMPTY = 1;
const int O = 2;
const int S = 3;

// Function prototypes
int gridState(long long grid, int pos);
void printGrid(long long grid);
bool updateGrid(long long grid, char sym, int pos);

// NOTE: You can design extra functions to ease your development if you see fit

// Returns the state of position pos of grid (1 for empty, 2 for O; 3 for S)
int gridState(long long grid, int pos) {
    // Shift position pos to the units-digit
    for (int i = 0; i < 12 - pos; i++) {
        grid /= 10;
    }
    return grid % 10;
}

// Prints grid to the screen
void printGrid(long long grid) {
    int d, pos;
    for (pos = 1; pos <= 12; pos++) {
        d = gridState(grid, pos);
        if (d == O)
            cout << 'O';
        else if (d == S)
            cout << 'S';
        else
            cout << '.';
        if (pos % 4 == 0)
            cout << endl;
        else
            cout << ' ';
    }
}

// Updates the pos-th digit of grid to 2 (resp. 3) if sym is 'O' (resp. 'S').
// Corresponds to the player action of putting symbol sym in position pos of
// grid. Returns whether any new S-O-S sequence(s) has/have been formed. 
bool updateGrid(long long grid, char sym, int pos) {
    int row, col, r1, r2, c1, c2, r, c;
    int y1, x1, y2, x2, pos1, pos2;
    // TODO (Add a return statement to compile.)

    row = (pos - 1) / 4 + 1;
    col = (pos - 1) % 4 + 1;

    //Path1 (sym='O')
    if (sym == 'O') {
        //Step1: Find all ‘S’ around the ‘O’
        if (row - 1 > 0) r1 = row - 1; else r1 = 1;
        if (row + 1 < 4) r2 = row + 1; else r2 = 3;
        if (col - 1 > 0) c1 = col - 1; else c1 = 1;
        if (col + 1 < 5) c2 = col + 1; else c2 = 4;
        //Step2:Detect S-O-S around the position
        for (r = r1; r <= r2; r++) {
            for (c = c1; c <= c2; c++) {
                pos1 = (r - 1) * 4 + c;
                y1 = (pos1 - 1) / 4 + 1;
                x1 = (pos1 - 1) % 4 + 1;
                y2 = 2 * row - y1;
                x2 = 2 * col - x1;
                pos2 = (y2 - 1) * 4 + x2;

                if (gridState(grid, pos1) == 3 && gridState(grid, pos2) == 3 && y1 > 0 && y1 < 4 && y2>0 && y2 < 4 && x1>0 && x1 < 5 && x2>0 && x2 < 5) 
                    return(true);
            }
        }
        return false;
    }

    //Path1 (sym='S')
    if (sym == 'S') {
        //Step1: Find all ‘O’ around the ‘S’
        if (row - 1 > 0) r1 = row - 1; else r1 = 1;
        if (row + 1 < 4) r2 = row + 1; else r2 = 3;
        if (col - 1 > 0) c1 = col - 1; else c1 = 1;
        if (col + 1 < 5) c2 = col + 1; else c2 = 4;
        //Step2:Detect S-O-S around the position
        for (r = r1; r <= r2; r++) {
            for (c = c1; c <= c2; c++) {
                pos1 = (r - 1) * 4 + c;
                y1 = (pos1 - 1) / 4 + 1;
                x1 = (pos1 - 1) % 4 + 1;
                y2 = 2 * y1  - row;
                x2 = 2 * x1 - col;
                pos2 = (y2 - 1) * 4 + x2;

                if (gridState(grid, pos1) == 2 && gridState(grid, pos2) == 3 && y1 > 0 && y1 < 4 && y2>0 && y2 < 4 && x1>0 && x1 < 5 && x2>0 && x2 < 5)
                    return(true);
            }
        }
        return(false);
    }
}


int main() {
   

    int k = 0, pos;
    char sym;

    long long Update_value = 0;
    long long grid=111111111111;

    int t=0;
    for (k = 0; k < 12 && t==0; k++) {
        
        printGrid(grid);

        //Enter the appropriate 'sym' and 'pos'
        cout << "Player " << 1 + k % 2 << "'s move: ";
        cin >> sym >> pos;
        while ((sym !='O'&& sym !='S') || pos < 1 || pos>12 || gridState(grid, pos)!=1) {
            cout << "Invalid move.Try again!";
            cout << "\nPlayer" << 1 + k % 2 << "'s move: ";
            cin >> sym>>pos;
        }

            //New grid
        Update_value = pow(10, (12 - pos));
        if (sym == 'S') {
            Update_value *= 2;
            grid += Update_value;
                
        }

        else if (sym == 'O') {
            Update_value *= 1;
            grid += Update_value;
               
        }
        if (updateGrid(grid, sym, pos))
        {
            printGrid(grid);
            cout << "Player " << 1 + k % 2 << " wins!";
            return 0;
        }
        

    }
        printGrid(grid);
        cout << "Draw games!";
}
