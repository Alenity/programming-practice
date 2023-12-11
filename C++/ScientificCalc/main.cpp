#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

class Calc {
public:
	int sum(int a, int b) {
		return a + b;
	}
	int difference(int a, int b) {
		return a - b;
	}
	int product(int a, int b) {
		return a * b;
	}
	int quotient(int a, int b) {
		return a / b;
	}

};

class ErrHandler {
public:
	void syntaxErr() {

	}
	void mathErr() {

	}

};

int main() {

}

