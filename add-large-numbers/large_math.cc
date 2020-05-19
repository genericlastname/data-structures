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
	string result = "";

	if (s1.length() > s2.length())
		swap(s1, s2);

	reverse_str(s1);
	reverse_str(s2);

	int carry = 0;
	for (int i=0; i < s1.length(); i++) {
		int sum = ((s1[i]-'0') + (s2[i]-'0') + carry);
		result.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	for (int i = s1.length(); i < s2.length(); i++) {
		int sum = (s2[i]-'0' + carry);
		result.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry)
		result.push_back(carry+'0');

	reverse_str(result);
	return result;
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
string multiply_two(string s1, string s2) {
	// s2 is the longest
	if (s1.length() > s2.length())
		swap(s1, s2);
	int max_length = s2.length();

	string* products = new string[max_length];
	int count = 0;
	int carry = 0;

	reverse_str(s1);
	reverse_str(s2);

	for (int i = 0; i < s1.length(); i++) {
		// push back the right amount of zeros
		for (int x = 0; x < count; x++) {
			products[count].append("0");
		}

		for (int j = 0; j < s2.length(); j++) {
			int p = (s1[i]-'0') * (s2[j]-'0') + carry;
			products[count].push_back((p % 10)+'0');
			carry = p / 10;
		}
		count++;
	}

	for (int i = 0; i < max_length; i++) {
		reverse_str(products[i]);
	}
	products[count] = to_string(carry);

	return add_all(products, count);
}

// ============================================================================
// Multiply together all numbers in an array.
// ============================================================================
string multiply_all(string* nums, int size) {
	string product;

	for (int i = 1; i < size; i++) {
		product = multiply_two(product, nums[i]);
	}

	return product;
}

// ============================================================================
// Print out all numbers in nums and sum.
// ============================================================================
void prettyprint_add(string* nums, int size) {
	int end = size - 1;
	int width = 0;
	string sum = add_all(nums, size);

	width = sum.length() + 2;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (width - nums[i].length()); j++) {
			if (i == end && j == 0) {
				cout << "+";
			}
			else {
				cout << " ";
			}
		}
		cout << nums[i] << endl;
	}
	draw_divider(width);
	cout << "  " << sum << endl;
}

// ============================================================================
// Print out all numbers in nums and the product.
// ============================================================================
void prettyprint_multiply(string* nums, int size) {
	int end = size - 1;
	int width = 0;
	string product = multiply_all(nums, size);

	width = product.length() + 2;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (width - nums[i].length()); j++) {
			if (i == end && j == 0) {
				cout << "x";
			}
			else {
				cout << " ";
			}
		}
		cout << nums[i] << endl;
	}
	draw_divider(width);
	cout << "  " << product << endl;
}
