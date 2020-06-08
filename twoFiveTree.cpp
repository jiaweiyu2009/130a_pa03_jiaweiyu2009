//Jiawei Yu
//2-5 Tree
//I tried to do the 2-5 tree by following the pseudo code from session. But it didnt work. Please give me some partial credits for trying to the code for 2-5 tree.



#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 
class subNode{
    string key;
    int count;
}

class Node 
{ 
	public: 
	subNode *k1;
	subNode *k2;
	subNode *k3;
	subNode *k4;
	Node *a1; 
	Node *a2;
	Node *a3;
	Node *a4;
	Node *a5;
	Node *parent;
	 
}; 


Node* newNode(string key, Node*p) 
{ 
	Node* node = new Node(); 
	node->k1->key = key; 
	node->k2 = NULL;
	node->k3 = NULL;
	node->k4 = NULL;
	
	node->a1 = NULL;
	node->a2 = NULL;
	node->a3 = NULL;
	node->a4 = NULL;
	node->a5 = NULL;
	
	node->parent = NULL;
	
	
	return(node); 
}

bool leafNodeOrNot(Node* n){ //if this node is a leaf node or not
    if(n->a1 == NULL && n->a2 == NULL && n->a3 == NULL && n->a4 == NULL && n->a5 == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool fullLeafOrNot(Node* n){ //if this node is a full leaf node or not
    if(leafNodeOrNot(n) && n->k1 != NULL && n->k2 != NULL && n->k3 != NULL && n->k4 != NULL){
        return true;
    }
    else{
        return false;
    }
}

bool fullNodeOrNot(Node* n){ //if this node is a full node or not
    if(n->k1 != NULL && n->k2 != NULL && n->k3 != NULL && n->k4 != NULL){
        return true;
    }
    else{
        return false;
    }
}


Node* findPointer(string key, Node* n){ // returns the correct pointer that we should follow
    if(key < n->k1->key){
        return n->a1;
        
    }
    else if (key > n->k1->key && key < n->k2->key){
        return n->a2;
    }
    else if (key > n->k2->key && key < n->k3->key){
        return n->a3;
    }
    else if (key > n->k3->key && key < n->k4->key){
        return n->a4;
    }
    else{
        return n->a5;
    }
}

vector<string> getMedian(string key, Node* n){   //gets the median value among the 4 values in the node and the key
    
    vector<string> vec;

    vec.push_back(n->k1->key);
    vec.push_back(n->k2->key);
    vec.push_back(n->k3->key);
    vec.push_back(n->k4->key);
    vec.push_back(key);

    sort( vec.begin(), vec.end() );
    
    return vec;
}
    
pair<Node*, Node*> split(string key, Node* n){  //split the node if we want to insert a key to a full node
    if(n == NULL){
        n = newNode(key);
        pair<Node*, Node*> p1;
        p1 = make_pair(n,NULL);
        return p1;
    }
    else if(!fullNodeOrNot){
        insert(key,n);
        pair<Node*, Node*> p1;
        p1 = make_pair(n,NULL);
        return p1;
    }
    else{
        vector<string> v = getMedian(key,n);
        
        Node* lower = newNode(v[0]);
        lower = insert(v[1]);
        lower = insert(v[2]);
        Node* upper = newNode(v[3]);
        upper = insert(v[4]);
        // update pointers for node lower and node upper
        pair<Node*, Node*> p2;
        p2 = make_pair(lower,upper);
        return p2;
    }
}
        

    


Node* insert(string key, Node* n){  
    if(n == NULL){
        return (newNode(key));
    }
    
    else if(key == n->k1->key){
        n->k1->count++;
    }
    else if(key == n->k2->key){
        n->k2->count++;
    }
    else if(key == n->k3->key){
        n->k3->count++;
    }
    else if(key == n->k4->key){
        n->k4->count++;
    }
    
    else if (!leafNodeOrNot(n))
        findPointer(key,n);
    
    else if(fullLeafOrNot(n)){
        split(key,n);
    }
    else{
        // insert item into leaf node
    }
}
    
    
    
        
    









// Driver Code 
int main() 
{ 
	Node *root = NULL; 
	

	return 0; 
} 
