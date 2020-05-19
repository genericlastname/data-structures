#include <iostream>
#include "poly.h"
using namespace std;

Node* create_node(int x, int y) {
	Node* n = new Node;
	n->coeff = x;
	n->exp = y;
	n->next = nullptr;
	return n;
}

// Polynomial add(Polynomial p1, Polynomial p2) { 
// 	Polynomial result = new Node;

// 	while (p1->next && p2->next) {
// 		if (p1->exp > p2->exp) {
// 			result->exp = p1->exp;
// 			result->coeff = p1->exp;
// 			p1 = p1->next;
// 		}
// 		else if (p1->exp < p2->exp) {
// 			result->exp = p2->exp;
// 			result->coeff = p2->coeff;
// 			p2 = p2->next;
// 		}
// 		else {
// 			result->exp = p1->exp;
// 			result->coeff = p1->coeff + p2->coeff;
// 			p1 = p1->next;
// 			p2 = p2->next;
// 		}
// 		result->next = new Node;
// 		result = result->next;
// 		result->next = nullptr;
// 	}

// 	while (p1->next || p2->next) {
// 		if (p1->next) {
// 			result->exp = p1->exp;
// 			result->coeff = p1->coeff;
// 			p1 = p1->next;
// 		}
		
// 		if (p2->next) {
// 			result->exp = p2->exp;
// 			result->coeff = p2->coeff;
// 			p2 = p2->next;
// 		}

// 		result->next = new Node;
// 		result = result->next;
// 		result->next = nullptr;
// 	}

// 	return result;
// }

void add(Polynomial poly1, Polynomial poly2, Polynomial poly) { 
	while(poly1->next && poly2->next) { 
        if(poly1->exp > poly2->exp) { 
            poly->exp = poly1->exp; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
        else if(poly1->exp < poly2->exp) { 
            poly->exp = poly2->exp; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
        else { 
            poly->exp = poly1->exp; 
            poly->coeff = poly1->coeff+poly2->coeff; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
          
        // Dynamically create new node 
        poly->next = new Node; 
        poly = poly->next; 
        poly->next = nullptr; 
    } 

	while(poly1->next || poly2->next) { 
        if(poly1->next) { 
            poly->exp = poly1->exp; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 

        if(poly2->next) { 
            poly->exp = poly2->exp; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
		poly->next = new Node;
        poly = poly->next; 
        poly->next = nullptr; 
    } 
} 

void show(Polynomial p) {
	while (p != nullptr) {
		cout << abs(p->coeff);
		if (p->exp > 1)
			cout << "x^" << p->exp;
		else if (p->exp == 1)
			cout << "x";

		if (p->next != nullptr) {
			if (p->next->coeff > 0)
				cout << " + ";
			else if (p->next->coeff < 0)
				cout << " - ";

		}
		p = p->next;
	}
	cout << endl;
}
