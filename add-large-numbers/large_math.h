#ifndef __LARGE_MATH_H__
#define __LARGE_MATH_H__

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void draw_divider(int length);

bool validate_number(string s);

void reverse_str(string& s);

string add_two(string s1, string s2);

string add_all(string* nums, int size);

string* multiply_two(string s1, string s2);

void prettyprint_add(string* nums, int size);

void prettyprint_multiply(string* nums, int size);

#endif
