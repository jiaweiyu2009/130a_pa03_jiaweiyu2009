 #ifndef PROG1_H
#define PROG1_H

#include <iostream>
#include <vector>

using namespace std;

class AVL {

public:

	AVL();
	~AVL();
	bool search(string word) const;
	
	void insert(string key);
	
	void print();
	void rangeSearch(string a, string b)const;

	

//	void  rangeSearch(Node* r, string a, string b) const;


	struct Node{
		string key;
		int count;
		Node *left, *right, *parent;
		int height;

		//Node(string w="", int c=0, int h=0): key(w), count(c), height(h), left(0),right(0),parent(0){}

	};

	Node* root;

	void clear(Node *n);
	int max(int a, int b);
	int height(Node *N);
	Node* newNode(string key);
	Node* rightRotate(Node *y);
	Node* leftRotate(Node *x);
	int getBalance(Node *N);
	Node* insert(Node* node, string key);
	void preOrder(Node *n);
	Node*  insertHelper(Node *node,string key);
};

#endif
