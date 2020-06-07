#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <queue>
#include "avl.h"
 
using namespace std; 

// An AVL tree node 
class Node 
{ 
	public: 
	string key; 
	int count = 0;
	Node *left; 
	Node *right; 
	int height; 
}; 

// A utility function to get maximum 
// of two integers 
int max(int a, int b); 

// A utility function to get the 
// height of the tree 
int height(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

// A utility function to get maximum 
// of two integers 
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

/* Helper function that allocates a 
new node with the given key and 
NULL left and right pointers. */
Node* newNode(string key) 
{ 
	Node* node = new Node(); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; // new node is initially 
	node->count = 1;				// added at leaf 
	return(node); 
} 

// A utility function to right 
// rotate subtree rooted with y 
// See the diagram given above. 
Node *rightRotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 

	// Return new root 
	return x; 
} 

// A utility function to left 
// rotate subtree rooted with x 
// See the diagram given above. 
Node *leftRotate(Node *x) 
{ 
	Node *y = x->right; 
	Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left),	 
					height(x->right)) + 1; 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 

	// Return new root 
	return y; 
} 

// Get Balance factor of node N 
int getBalance(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

// Recursive function to insert a key 
// in the subtree rooted with node and 
// returns the new root of the subtree. 
Node* insert(Node* node, string key) 
{ 
	/* 1. Perform the normal BST insertion */
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else {
		node->count++;
		return node; 
	}
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


Node* insert2(Node* node, string key) 
{ 
	/* 1. Perform the normal BST insertion */
	if (node == NULL){ 
		Node* p = newNode(key);
		cout << key << " inserted, new count = " << p->count << endl;
		return p;
	}
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else {
		node->count++;
		cout << key << " inserted, new count = " << node->count << endl;
		return node; 
	}
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

bool search(string value, Node* n){
	if (!n){
		cout << value << " not found\n";
		return false;
	}
	else{
	    if(value == n->key){
		cout << value << " found, count = " << n->count << endl;
		return true;
	    }
	    if(value < n->key){
		return search(value,n->left);
	    }
	    else{
		return search(value,n->right);
	    }
}
}


bool search3(string value, Node* n){
	if (!n){
	
		return false;
	}
	else{
	    if(value == n->key){
		
		return true;
	    }
	    if(value < n->key){
		return search(value,n->left);
	    }
	    else{
		return search(value,n->right);
	    }
}
}


void rangeSearchHelper(Node* r, string a, string b, vector<string>& v) {
	
	if(r == nullptr){
		v.push_back(" ");
	}
	else if(a >= r->key && (search3(r->key,r) == true)){
		rangeSearchHelper(r->right,a,b,v);
	}
	else if(a <= r->key && b >= r->key && (search3(r->key,r) == true)){
		rangeSearchHelper(r->left,a,b,v);
		cout << r->key<<endl;
		rangeSearchHelper(r->right,a,b,v);
	}
		
	
	else if(b < r->key && (search3(r->key,r) == true)){
		rangeSearchHelper(r->left,a,b,v);
	}


}

void rangeSearch(Node* r, string a, string b){
	vector<string>w;
	rangeSearchHelper(r,a,b,w);

}

int FirstSpace(string b, string x){
for(size_t i = 0; i < b.length(); i++) {
    if (b.substr(i, x.length()) == x){
         return i;
}
}
}

int main(int argc, char** argv){
Node* root = NULL;

fstream file;
string word, filename;
//filename = "PA3_dataset.txt";
//filename = "/autograder/submission/PA3_dataset.txt";
filename = "small.txt";
file.open(filename.c_str());
while (file >>word){

insert2(root, word); 
bool i = search(word,root);
}

bool x = search("day",root);
/*
///////////////////////////////////////////////
string str = argv[1];
queue<string>q;

stringstream ss(str);
while (ss.good()){
    string substr;
    getline(ss, substr, ',');
    q.push(substr);
}

while (!q.empty()){
string s = q.front();

//////////////////////////////////////////////////////////
if (s.find("insert") != std::string::npos){
string w = " ";
int indexOfSpace = 0;
for (size_t i = 0; i < s.length(); i++) {
        if (s.substr(i, w.length()) == w) {
            indexOfSpace = i;
        }
}

string key = s.substr(indexOfSpace+1, s.length()-1);
Node* a = insert2(root, key);
}

////////////////////////////////////////////////////////////
else if (s.find("range") != std::string::npos){
string extracted;
if(s[0] == 32){
    extracted = s.erase(0,14);
}
else if(s[0] == 114){
     extracted = s.erase(0,13);
}


string w = " ";
int indexOfFirstSpace = 0;
int indexOfLastSpace = 0;
for (size_t i = 0; i < extracted.length(); i++) {
        if (extracted.substr(i, w.length()) == w) {
            indexOfLastSpace = i;
        }
}

indexOfFirstSpace = FirstSpace(extracted, w);

string a = extracted.substr(0, indexOfFirstSpace);
string b = extracted.substr(indexOfLastSpace+1, extracted.length());

cout << "broaching" <<endl;
rangeSearch(root,a,b);


}

/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
else if(s.find("search") != std::string::npos){
string w = " ";
int indexOfSpace = 0;
for (size_t i = 0; i < s.length(); i++) {
        if (s.substr(i, w.length()) == w) {
            indexOfSpace = i;
        }
}
string key = s.substr(indexOfSpace+1, s.length()-1);
bool x = search(key,root);
}

////////////////////////////////////////////////////////////////////////

q.pop();



}
*/
return 0;
}
