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
        }
    }

    cout << size << endl;
    for (int i = 0; i < size; i++) {
        cont = false;

        while (!cont) {
            cout << endl << "Input #" << (i+1) << " -> ";
            getline(cin, input);

            if (validate_number(input)) {
                int n = stoi(input);
                nums[i] = n;
                cont = true;
            }
        }
    }

    return 0;
}
