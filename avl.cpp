#include "avl.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

AVL::AVL() : root(0){}

AVL::~AVL() {
    clear(root);
    this->root = nullptr;
}

// recursive helper for destructor
void AVL::clear(Node *n) {
    if (n) {
	   clear(n->left);
	   clear(n->right);
	   delete n;
    }
}


int AVL::max(int a, int b){
	return(a > b)? a: b;
}

int AVL::height(Node* N){
	if(N == NULL){
		return 0;}
	return N->height;
}

AVL::Node* AVL::newNode(string key){
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;

	return(node);
}

AVL::Node* AVL::rightRotate(Node* y){
	
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),height(y->right)) + 1;
	x->height = max(height(x->left),height(x->right)) + 1;

	// Return new root
	return x;
}

AVL::Node* AVL::leftRotate(Node* x){
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;

	// Return new root
	return y;
}

int AVL::getBalance(Node *N){
		if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}



AVL::Node* AVL::insertHelper(Node* node, string key)
{	/* 1. Perform the normal BST insertion */
	if (!node) {
		return(newNode(key));
	}
	if (key < node->key) 
		node->left = insertHelper(node->left, key); 
	else if (key > node->key) 
		node->right = insertHelper(node->right, key); 
	else // Equal keys are not allowed in BST 
		return node; 
	cout << "3432" << endl;
	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	/* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
	int balance = getBalance(node); 

	// If this node becomes unbalanced, then 
	// there are 4 cases 

	// Left Left Case 
	if (balance > 2 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -2 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 2 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -2 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
}

void AVL::print(){
	preOrder(root);
}

void AVL::preOrder(Node *n){
	if(n){
		cout << n -> key <<" ";
		preOrder(n->left); 
		preOrder(n->right); 
	} 
} 
