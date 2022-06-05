//assignment3.cpp
/*CSCI1520
 *
 *Assignment: 3
 */
#include<cstdlib>
#include <iostream>


int main()
{
	int n, g, secret, i = 1, j, x=1, l = 1, r = 100;
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
	int k = 1;
	bool v = true;
	
	

	std::cout << "How many players (2-4)? ";
	std::cin >> n;



	while (n < 2 || n>4) {
		std::cout << "Must be 2-4 players! Try again." << "\nHow many players (2-4)? ";
		std::cin >> n;
	}
	std::cout << "How many games? ";
	std::cin >> g;

	while (g <= n) {
		std::cout << "At least " << n + 1 << " games! Try again." << "\nHow many games? ";
		std::cin >> g;
	}

	srand(2 * n * g);
	secret = rand() % 100 + 1;

	





	for (i; i <= g;i++) {

		if (i <= n) { j = i; }
		else if (i > n) { j = (i - 1) % n + 1; }
		std::cout << "Game #" << i<< ":";
		v = true;

		while (v == true) {
			std::cout << "\nPlayer " << j << "'s guess (" << l << "-" << r << "): ";
			std::cin >> x;

			while (x<l || x>r) {

				std::cout << "Guess must be " << l << "-" << r << "! Try again.";
				std::cout << "\nPlayer " << j << "'s guess (" << l << "-" << r << "): ";
				std::cin >> x;
			}

			if (x < secret && x >= l && x <= r) {
				std::cout << "Guess is LO.";
				l = x + 1;

			}
			else if (x > secret && x >= l && x <= r) {
				std::cout << "Guess is HI.";;
				r = x - 1;

			}
			else if (x = secret && x >= l && x <= r) {
				std::cout << "Boom! Player " << j << " loses.\n";
				l = 1, r = 100;
				
				if (j == 1) {
					num1++;
				}
				else if (j == 2) {
					num2++;
				}
				else if (j == 3) {
					num3++;
				}
				else if (j == 4) {
					num4++;
				}
				k = 0;
				
				secret = rand() % 100 + 1;
				v = false;
				
			}




			for (k;v==true ; k++) {
				std::cout << "\nPlayer " << (j + k-1) % n+1 << "'s guess (" << l << "-" << r << "): ";
				std::cin >> x;

				while (x<l || x>r) {
					std::cout << "Guess must be " << l << "-" << r << "! Try again.";
					std::cout << "\nPlayer " << (j + k - 1) % n + 1 << "'s guess (" << l << "-" << r << "): ";
					std::cin >> x;
				}

				if (x < secret && x >= l && x <= r) {
					std::cout << "Guess is LO.";
					l = x + 1;
					
				}
				else if (x > secret && x >= l && x <= r) {
					std::cout << "Guess is HI.";;
					r = x - 1;
					
				}
				else if (x = secret && x >= l && x <= r) {
					std::cout << "Boom! Player " << (j + k - 1) % n + 1 << " loses.\n";
					l = 1, r = 100;
					
					if ((j + k - 1) % n + 1 == 1) {
						num1++;
					}
					else if ((j + k - 1) % n + 1 == 2) {
						num2++;
					}
					else if ((j + k - 1) % n + 1 == 3) {
						num3++;
					}
					else if ((j + k - 1) % n + 1 == 4) {
						num4++;
					}
					v = false;
				
					secret = rand() % 100 + 1;
					k = 0;
				}

			}

		}




	}

	if (n == 4) {
		std::cout << "Player 1 loses " << num1 << " time(s).\n";
		std::cout << "Player 2 loses " << num2 << " time(s).\n";
		std::cout << "Player 3 loses " << num3 << " time(s).\n";
		std::cout << "Player 4 loses " << num4 << " time(s).\n";
	}
	if (n == 3) {
		std::cout << "Player 1 loses " << num1 << " time(s).\n";
		std::cout << "Player 2 loses " << num2 << " time(s).\n";
		std::cout << "Player 3 loses " << num3 << " time(s).\n";
	}
	if (n == 2) {
		std::cout << "Player 1 loses " << num1 << " time(s).\n";
		std::cout << "Player 2 loses " << num2 << " time(s).\n";
	}


	


	}
