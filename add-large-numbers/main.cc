#define ADD 0
#define MULT 1

#include <iostream>
#include "large_math.h"
using namespace std;

int main() {
    string* nums;
    string input;
    bool cont;
	bool running = true;
    int size;
	int mode;

	while (running) {
		cont = false;
		cout << endl << "1. Addition\n2. Multiplication" << endl;
		while (!cont) {
			cout << endl << "Make your selection: ";
			getline(cin, input);
			if (input == "1") { 
				mode = ADD;
				cont = true;
			}
			else if (input == "2") {
				mode = MULT;
				cont = true;
			}
			else
				cout << "Invalid selection" << endl;
		}

		cont = false;
		while (!cont) {
			cout << endl << "How many numbers -> ";
			getline(cin, input);

			if (validate_number(input)) {
				size = stoi(input);

				if (size >= 2 && size <= 11) {
					nums = new string[size];
					cont = true;
				}
				else {
					cout << "Input should be from 2 to 11" << endl;
				}
			}
			else {
				cout << "Input should be a number" << endl;
			}
		}

		for (int i = 0; i < size; i++) {
			cont = false;
			while (!cont) {
				cout << endl << "Input #" << (i+1) << " -> ";
				getline(cin, input);

				if (validate_number(input)) {
					nums[i] = input;
					cont = true;
				}
				else {
					cout << "Make sure the input is a number no more than 14 digits long" << endl;
				}
			}
		}

		cout << endl;
		if (mode == ADD)
			prettyprint_add(nums, size);
		else
			prettyprint_multiply(nums, size);

		cont = false;
		while (!cont) {
			string input;
			cout << endl << "Would you like to try another problem? (y/n) ";
			getline(cin, input);
			if (input == "y")
				cont = true;
			else if (input == "n") {
				cont = true;
				running = false;
			}
		}
	}

    return 0;
}
