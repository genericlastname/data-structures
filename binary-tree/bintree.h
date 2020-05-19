#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <string>

struct Node {
	Node* left;
	Node* right;
	char value;

	Node (char x) {
		value = x;
		left = nullptr;
		right = nullptr;
	}
};
typedef Node* BinTree;

void insert(BinTree& root, char v);
BinTree build_tree(const std::string s);

std::string print_preorder(BinTree root);
std::string print_postorder(BinTree root);
std::string print_inorder(BinTree root);

// int node_count(BinTree root);
// int tree_height(BinTree root);
bool is_BST(BinTree root);
bool is_full_BST(BinTree root);
bool is_complete_BST(BinTree root);

#endif
