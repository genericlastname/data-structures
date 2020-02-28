#include "large_math.h"
using namespace std;

#define MAX_DIGITS 14
#define MAX_NUMS 11

// ============================================================================
// Draw a horizontal bar.
// ============================================================================
void draw_divider(int length) {
    for (int i = 0; i < length; i++) {
        cout << "-";
    }
    cout << endl;
}

// ============================================================================
// Return true if the string is a valid (according to specs) number.
// ============================================================================
bool validate_number(string s) {
    if (s.length() > MAX_DIGITS || s.empty())
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

// ============================================================================
// Add together all numbers in an array.
// ============================================================================
string add_all(string* nums, int size) {
    string sum = nums[0];

    for (int i = 1; i < size; i++) {
        sum = add_two(sum, nums[i]);
    }

    return sum;
}

// ============================================================================
// Multiply two number strings together and return the result.
// ============================================================================
string* multiply_two(string s1, string s2) {
    string shorter = (s1.length() < s2.length()) ? s1 : s2;
    string longer = (s1.length() > s2.length()) ? s1 : s2;
    string* products = new string[shorter.length()];

    for (int i = shorter.length() - 1; i >= 0; i--) {
        int carry = 0;
        string prod;

        for (int j = longer.length() -1; j >= 0; j--) {
            int n = (shorter[i] - '0') * (longer[j] - '0') + carry;
            prod.push_back((n % 10) + '0');
            carry = n / 10;
            // cout << prod << endl;
        }

        if (carry)
            prod.push_back(carry + '0');

        reverse_str(prod);

        products[i] = prod;
    }

    return products;
}

// ============================================================================
// Print out all numbers in nums and sum.
// ============================================================================
void prettyprint_add(string* nums, int size) {
    int width;

    // Find longest number string.
    for (int i = 0; i < size; i++) {
        if (nums[i].length() > size)
            width = nums[i].length() + 4;
    }

    for (int j = 0; j < size; j++) {
        if (j == (size - 1)) {
            cout << "+> ";
            cout << setw(width - 3) << right << nums[j] << endl;
        }
        else {
            cout << setw(width) << right << nums[j] << endl;
        }
    }

    draw_divider(width);
    cout << setw(width) << right << add_all(nums, size) << endl << endl;
}

// ============================================================================
// 
// ============================================================================
void prettyprint_multiply(string* nums, int size) {
    int place = (int)pow((double)10, (double)size - 1.0);
    int width;
    string first = nums[0];
    string last = nums[size-1];
    string* products;

    width = (first.length() > last.length()) ? first.length() + 4 : last.length() + 4;

    cout << setw(width) << right << last << endl;
    cout << "*> ";
    cout << setw(width - 3) << right << first << endl;
    draw_divider(width);

    products = multiply_two(first, last);
    for (int i = 0; i < size; i++) {
        int temp = stoi(products[i]);
        temp = temp * place;
        place = place / 10;
        products[i] = to_string(temp);
    }
    prettyprint_add(products, last.length());
}
