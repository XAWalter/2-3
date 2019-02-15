#include <iostream>

#include "Tree.h"

using namespace std;

Tree::Tree() {
	top = NULL;
}

void Tree::insert(const string &nName) {
	insert(top, nName);
}

void Tree::insert(Node* node, const string &nName) {
	if (node == NULL) {
		Node* nTree = new Node;
		nTree->small = nName;
		top = nTree;
		top->size = 1;
	}
	else if (node->left == NULL && node->right == NULL) {
		if (node->size <= 1) {
			if (nName < node->small) {
				node->large = node->small;
				node->small = nName;
			}
			else {
				node->large = nName;
			}
			node->size++;
		}
		else {
			split(node, nName);
		}
	}
	else {
		if (node->size <= 1) {
			if (nName < node->small) {
				insert(node->left, nName);
			}
			else {
				insert(node->right, nName);
			}
		}
		else {
			if (nName < node->small) {
				insert(node->left, nName);
			}
			else if (nName > node->large) {
				insert(node->right, nName);
			}
			else {
				insert(node->middle, nName);
			}
		}
	}
}

void Tree::split(Node* node, const string &nName) {
	string smallest;
	string median;
	string biggest;

	if (nName <= node->small) {
		smallest = nName;
		median = node->small;
		biggest = node->large;
	}
	else if (nName > node->large) {
		smallest = node->small;
		median = node->large;
		biggest = nName;
	}
	else {
		smallest = node->small;
		median = nName;
		biggest = node->large;
	}

	if (node->parent == NULL) {
		Node* nTop = new Node;
		

		Node* tmp = new Node;

		nTop->small = median;
		tmp->small = nName;
		
		if (nName <= node->small) {
			nTop->left = tmp;
			nTop->right = node;

			node->small = node->large;
			node->large = "";

			if (node->left != NULL) {
				tmp->left = node->left;
				node->left->parent = tmp;
			}
			node->left = node->middle;
			node->middle = NULL;

		}
		else {
			nTop->right = tmp;
			nTop->left = node;

			node->large = "";

			if (node->right != NULL) {
				tmp->right = node->right;
				node->right->parent = tmp;
			}
			node->right = node->middle;
			node->middle = NULL;

		}

		tmp->parent = nTop;
		node->parent = nTop;

		node->size = 1;
		nTop->size = 1;
		tmp->size = 1;
		top = nTop;
	}
	else {
		if (node->parent->size <= 1) {
			Node* tmp = new Node;
			if (median < node->parent->small) {
				node->parent->large = node->parent->small;
				node->parent->small = median;
				tmp->small = biggest;
				node->large = "";
				node->parent->middle = tmp;
				tmp->parent = node->parent;
			}
			else {
				node->parent->large = median;
				tmp->small = node->small;
				node->small = biggest;
				node->large = "";
				node->parent->middle = tmp;
				tmp->parent = node->parent;
			}
			node->parent->size++;
			node->size = 1;
			tmp->size = 1;
		}
		else {
			Node* tmp = new Node;
			split(node->parent, median);
			if (node->large > node->parent->small) {
				tmp->small = smallest;
				tmp->size = 1;
				
				node->parent->left = tmp;
				tmp->parent = node->parent;

				node->small = node->large;
				node->large = "";
			}
			else {
				tmp->small = biggest;
				tmp->size = 1;
				
				node->parent->right = tmp;
				tmp->parent = node->parent;

				node->large = "";
			}
		}
	}
}