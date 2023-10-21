#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int decideWinner(char user, char computer) {
	if (user == computer) {
		cout << "It's a tie!\n";
		
		return 2;
	} 
	else if ((user == 'r' && computer == 'p') || (user == 's' && computer == 'r') || (user == 'p' && computer == 's')) {
		cout << "Computer wins this round!\n";
		
		return 1;
	} 
	else if ((user == 'r' && computer == 's') || (user == 's' && computer == 'p') || (user == 'p' && computer == 'r')) {
		cout << "You win!! :)\n";
		
		return 0;
	}
	else {
		cout << "That's not an option! XD\n";
	
		return 1;
	}
}

int main() {
	char uChoice;
	static const char choices[] = { 'r', 'p', 's' };
	cout << "ROCK PAPER SCISSORS\n";
	cout << "(r) Rock\n(p) Paper\n(s) Scissors\n";
	cout << "Pick your move: ";
	cin >> uChoice;
	srand(time(NULL));
	char cChoice = choices[rand() % 3];
	int result = decideWinner(uChoice, cChoice);
	if (result == 2) {
		main();
	}
	else {
		char ans;
		cout << "Play again?	(y/n): ";
		cin >> ans;
		if (ans == 'y') {
			main();
		}
		else if (ans == 'n') {
			exit(0);
		}
		else {
			exit(1);
		}
	}
}