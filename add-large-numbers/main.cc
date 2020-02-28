#include <iostream>
#include "large_math.h"
using namespace std;

int main() {
    string* nums;
    string input;
    bool cont = false;
    int size;

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
                cout << "Input should be a number from 2 to 11" << endl;
            }
        }
        else {
            cout << "Input should be a number from 2 to 11" << endl;
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

    prettyprint_add(nums, size);

    return 0;
}
