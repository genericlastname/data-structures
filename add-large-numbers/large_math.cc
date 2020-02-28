#include <string>
#include "large_math.h"
using namespace std;

// ============================================================================
// Return true if the string is a valid, >14 digit number.
// ============================================================================
bool validate_number(string s) {
    if (s.length() >= 14)
        return false;

    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i]))
            return false;
    }

    return true;
}

// ============================================================================
// Reverse a string in place.
// ============================================================================
void reverse_str(string& s) {
    int n = s.length();

    for (int i = 0; i < n/2; i++) {
        char temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
}

// ============================================================================
// Add two number strings together.
// ============================================================================
string add_two(string s1, string s2) {
    int max = (s1.length() < s2.length()) ? s1.length() : s2.length();
    string str = "";

    reverse_str(s1);
    reverse_str(s2);

    int carry = 0;
    for (int i = 0; i < max; i++) {
        int sum = (s1[i] - '0') + (s2[i] - '0') + carry;
        str.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    if (s1.length() < s2.length()) {
        for (int i = s1.length(); i < s2.length(); i++) {
            int sum = (s2[i] - '0') + carry;
            str.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
    }
    else {
        for (int i = s2.length(); i < s1.length(); i++) {
            int sum = (s1[i] - '0') + carry;
            str.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
    }

    if (carry)
        str.push_back(carry + '0');

    reverse_str(str);

    return str;
}
