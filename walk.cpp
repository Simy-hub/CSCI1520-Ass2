//assig6.cpp
/*CSCI1520
 *Assignment: 6
 */

#include <iostream>
#include<iomanip>
#include<string>
#include"ZebrasPath.h"

using namespace std;
int main() {
	int r, c;
	
	cout << "Zebra's starting position (row col): ";
	cin >> r>>c;
	while (r < 0 || r >= 8 || c< 0 || c >= 8 ) {
		cout << "Invalid. Try again!" << endl;
		cout << "Zebra's starting position (row col): ";
		cin >> r >> c;
	}
	
	ZebrasPath path(r, c);
	
	path.move(r, c);
	path.print();

	while (path.hasMoreMoves()) {
		cout << "Zebra's starting position (row col): ";
		cin >> r>>c;
		while ( !path.isValid(r, c)) {
			
			cout << "Invalid. Try again!" << endl;
			cout << "Zebra's starting position (row col): ";
			cin >> r >> c;
		}
		path.move(r, c);
		path.print();

	}
	if(!path.hasMoreMoves())
		cout <<"No more moves!";

}
