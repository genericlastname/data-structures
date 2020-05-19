#include <iostream>
#include "bintree.h"
using namespace std;

int main() {
	BinTree t = build_tree("abc.de");
	cout << "Preorder: { " << print_preorder(t) << " }" << endl;
	cout << "Postorder: { " << print_postorder(t) << " }" << endl;
	cout << "Inorder: { " << print_inorder(t) << " }" << endl;
}
