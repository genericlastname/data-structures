struct Node {
	int coeff;
	int exp;
	Node* next;
};
typedef Node* Polynomial;

Node* create_node(int x, int y);
void add(Polynomial poly1, Polynomial poly2, Polynomial poly);
void show(Polynomial p);
