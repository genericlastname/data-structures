#include "infix.h"
using namespace std;

int main() {
	bool running = true;
	string exp;

	while (running) {
		exp.clear();
		while (!valid_string(exp)) {
			cout << "Enter a valid infix expression: ";
			getline(cin, exp);

			if (exp == "q" || exp == "quit")
				return 0;
		}

		cout << "\nInfix: " << exp << "\nPostfix: " << infixToPostfix(exp);
		cout << endl << endl;
	}

	return 0;
}
