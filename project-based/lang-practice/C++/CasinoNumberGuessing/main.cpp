#include <iostream>
#include <ctime>
#include <string>
using namespace std;

struct BalanceAndChoice {
	int YN;
	int betAmount;
};


class Player {
public:
	string name;
	int balance = 0;

	void deposit(int amount) {
		balance += amount;
		printf("You balance is now: %d\n\n", balance);
	}

	void checkBalance() {
		printf("%d", balance);
	}

	void win() {
		balance *= 10;
		printf("Well Done! You win this round, how will you fair in the next?\n");
	}

	void loss() {
		balance = 0;
		printf("Oh no! Looks like you weren't so lucky here. Good luck next time!\n");
	}

	void winner() {
		balance *= 100;
		printf("Oh wow. Didn't actually expect you to win.\nCongratulations!!\n");
	}
	
};

class System {
public:
	string playerName;
	void help() {
		cout << "\nThe rules are as follows " + playerName  + ": \nYou smack down your betting money or use the credit you have in your balance.\nThere are 10 levels in the NUMBER TOWER, each level harder than the previous one.\n Make it to the top without failing once and you walk away richer than anyone to ever exist.\nAt any level you can also cash out whatever you have left.\nHowever, should you fail at any level, you drop all the way back to the bottom with nothing!\nCheck your balance by pressing 'b' or pull up these instructions by pressing 'h', ready ? \n";
	}
	void start(Player player) {

		for (int i = 1; i <= 10; i++) {
			if (i > 1 && 10 > i) {
				char response;
				cout << "Continue? (y/n)"; cin >> response;
				if (response == 'y') {
					int guess;
					int max = (2 * i) + 1;
					srand(time(NULL));
					int towerNumber = rand() % (max);
					printf("\nI\'m thinking of a number between 1 and %d", max);
					cout << "\nWhat is my number? "; cin >> guess;
					if (guess == towerNumber) {
						player.win();
					}
					else {
						player.loss();
						exit(0);
					}
				}
				else if (response == 'n') {
					printf("\nGot out while you could, smart.\n You made it to level% d!!\n", i);
					exit(0);
				}
			}
			else if (i == 10) {
				cout << "FINAL ROUND!!\n";
				int guess;
				int max = (2 * i) + 1;
				srand(time(NULL));
				int towerNumber = rand() % (max);
				printf("\nI\'m thinking of a number between 1 and %d", max);
				cout << "\nWhat is my number? "; cin >> guess;
				if (guess == towerNumber) {
					player.winner();
				}
				else {
					player.loss();
					exit(0);
				}
			}else {
				int guess;
				int max = (2 * i) + 1;
				srand(time(NULL));
				int towerNumber = rand() % (max);
				printf("\nI\'m thinking of a number between 1 and %d", max);
				cout << "\nWhat is my number? "; cin >> guess;
				if (guess == towerNumber) {
					player.win();
				}
				else {
					player.loss();
					exit(0);
				}
			}
			
		}
	}
	BalanceAndChoice startUP() {
		char choice;
		cout << "NUMBER TOWER\n\n";
		do {
			cout << "START? (y/n) "; cin >> choice;
			if (choice == 'y' || choice == 'n') {
				break;
			}
			else {
				cout << "Invalid input. Please enter 'y' or 'n'" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (true);

		if (choice == 'y') {
			BalanceAndChoice result;
			int bet;
			cout << "How much would you like to bet you can beat the TOWER?! "; cin >> bet;
			result.YN = 0;
			result.betAmount = bet;
			return result;
		}
		else if (choice == 'n') {
			cout << "Alright then...\n";
			BalanceAndChoice result;
			result.YN = 1;
			result.betAmount = 0;
			return result;
		}
		else {
			printf("what.");
		}

	}
};


int main() {
	System system;
	Player player;

	BalanceAndChoice result = system.startUP();
	
	
	
	
	if (result.YN == 0) {
		player.deposit(result.betAmount);
		string name;

		cout << "What is your name? "; cin >> name;
		system.playerName = name;
		
		system.help();
		
		system.start(player);
	}
	else if(result.YN == 1) {
		exit(0);
	}
	else {
		exit(1);
	}
	
}