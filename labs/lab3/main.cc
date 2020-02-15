#include <iostream>
#include <string>
using namespace std;

string iterative_reverse1(string s) {
    string temp;

    for (int i = s.length(); i >= 0; i--) {
        temp += s[i];
    }

    return temp;
}

void iterative_reverse2(string& s) {
    string temp;

    for (int i = s.length(); i >= 0; i--) {
        temp += s[i];
    }

    s = temp;
}

string recursive_reverse1(string s) {
    if (s.length() == 0)  // end condtion to stop recursion
        return "";

    string last(1,s[s.length()-1]);  // create string with last character
    string reversed = recursive_reverse1(s.substr(0,s.length()-1));
    return last+reversed; // Make he last character first
}

void recursive_reverse2(string& s, int k) {
    static int i = 0;
 
    if (k == s.length())
        return;
 
    recursive_reverse2(s, k + 1);
 
    if (i <= k)
        swap(s[i++], s[k]);
}

int main() {
    string test = "abcdefg";

    // Test 1
    cout << test << " -> " << iterative_reverse1(test) << endl;

    // Test 2
    iterative_reverse2(test);
    cout << "After iterative_reverse2() " << test << endl;

    // Test 3
    test = "tuvwxyz";
    cout << test << " -> " << recursive_reverse1(test) << endl;

    // Test 4
    recursive_reverse2(test, 0);
    cout << "After recursive_reverse2() " << test << endl;



    return 0;
}
