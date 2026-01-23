#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int createUser(string username, string password) {
	ofstream NewFile;
	NewFile.open(username + ".txt");
	NewFile << username << endl << password;
	if (NewFile.is_open()) {
		NewFile.close();
		return 0;
	}
	else {
		cout << "Error creating user!";
		return 1;
	}
}

int deleteUser(string username, string password) {
	ifstream File;
	string psswrd;
	string user;
	File.open(username + ".txt");
	string filename = username + ".txt";
	getline(File, user);
	getline(File, psswrd);
	if (password == psswrd) {
		int result = remove(filename.c_str());
		if (result == 0) {
			cout << "Your account has been deleted successfully\n";
			return result;
		}
		else {
			cout << "Error deleting account!\n";
			cout << "Error: " + result << endl;
			return result;
		}
	}
}

int logIn(string username, string password) {
	string user;
	string psswrd;
	ifstream File(username + ".txt");
	if (File.is_open()) {
		getline(File, user);
		getline(File, psswrd);
		if (username == user && password == psswrd){
			cout << "Logged in!\n";
			File.close();
			return 0;
		}
		else {
			cout << "Wrong password!\n";
			File.close();
			return 1;
		}
	}
	else {
		cout << "User does not exist!\n";
		File.close();
		return 1;
	}

}

int main() {
	int choice, result;
	string username, password;
	ifstream File;
	cout << "1. Register\n2. Log In\n3. Delete Account\n"; cin >> choice;
	switch (choice) {
	case 1:
		cout << "Create username: "; cin >> username;
		File.open(username + ".txt");
		if (File.is_open()) {
			cout << "User already exists!\n";
			File.close();
			main();
		}
		else {
			cout << "Enter password: "; cin >> password;
			result = createUser(username, password);
			if (result == 1) {
				main();
			}
		}
		
	case 2:
		cout << "Enter username: "; cin >> username;
		cout << "Enter password: "; cin >> password;
		result = logIn(username, password);
		if (result == 1) {
			main();
		}
		break;
	case 3:
		cout << "Enter username of account to delete: "; cin >> username;
		File.open(username + ".txt");
		if (!File.is_open()) {
			cout << "User doesn't exist!\n";
			main();
		} else { 
			File.close();
			cout << "Enter password for " + username << endl; cin >> password;
			deleteUser(username, password); 
		}
		
		break;
	default:
		cout << "Invalid choice selection!\n";
		main();
	}
	
}