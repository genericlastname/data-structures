#include "bintree.h"

void insert(BinTree& root, char v) {
	if (!root) {
		root = new Node(v);
	}
	else {
		if (!root->left)
			root->left = new Node(v); 
		else if (root->left)
			insert(root->left, v);

		else if (!root->right)
			root->right = new Node(v);
		else if (root->right)
			insert(root->right, v);
	}
}

BinTree build_tree(const std::string s) {
	BinTree result = nullptr;
	// BinTree* subtree;

	for (const char& c : s) {
		if (c == '.') {
			
		}
		else {
			insert(result, c);
		}
	}

	return result;
}

std::string print_preorder(BinTree root) {
	std::string traversal;
	traversal += root->value;

	if (root->left)
		traversal += print_preorder(root->left);
	if (root->right)
		traversal += print_preorder(root->right);

	return traversal;
}

std::string print_postorder(BinTree root) {
	std::string traversal;

	if (root->left)
		traversal += print_postorder(root->left);
	if (root->right)
		traversal += print_postorder(root->right);

	traversal += root->value;

	return traversal;
}

std::string print_inorder(BinTree root) {
	std::string traversal;

	if (root->right)
		traversal += print_inorder(root->right);

	traversal += root->value;

	if (root->left)
		traversal += print_inorder(root->left);


	return traversal;
}
