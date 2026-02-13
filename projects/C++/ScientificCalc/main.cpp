#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

class Functions {
public:
	int sum(int a, int b) {
		return a + b;
	}
	int difference(int a, int b) {
		return sum(a, -b);
	}
	int product(int a, int b) {
		return a * b;
	}
	int quotient(int a, int b) {
		return product(a, 1/b);
	}
	int exponent(int a, int b) {
		int res = 1;
		for(int i=0;i<b;i++){
			res *= a;
		}
	}

};

class ErrHandler {
public:
	void syntaxErr() {

	}
	void mathErr() {

	}

};

int main(int argc, char *argv[]) {

} 

