#include <iostream>
#include "poly.h"
using namespace std;

int main() {
	Polynomial test, rest, ans;
	test = create_node(3, 4);
	test->next = create_node(22, 2);
	test->next->next = create_node(-3, 0);
	rest = create_node(22, 4);
	rest->next = create_node(4, 1);
	ans = new Node;

	show(test);
	show(rest);
	add(test, rest, ans);
	cout << ans->exp << endl;
	show(ans);
}
