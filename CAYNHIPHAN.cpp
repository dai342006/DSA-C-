#include <iostream>
using namespace std;
struct Node{
 	int data;
 	Node *left, *right;
 	Node(int data = 0, Node*left=nullptr, Node*right=nullptr){
 		this->data = data;
 		this->left = left;
 		this->right = right;
	 }
 };
struct Mytree{
	Node* root;
	
	Mytree(Node* root=nullptr){
		this->root = root;
	}
	bool isEmpty(){
		return root=nullptr;
	}
};
 
void NLR(Node* root){
	if (root != nullptr){
		cout << root->data << ", ";
		NLR(root->left);
		NLR(root->right);
		
	}
}
void LNR(Node* root){
	if (root ){
		
		LNR(root->left);
		cout << root->data << ", ";
		LNR(root->right);
		
	}}
void LRN(Node* root){
	if (root != nullptr){
		LRN(root->left);
		LRN(root->right);
		cout << root->data << ", ";
	}
	
}

int main(){
	
	
	Node* node6 = new Node(6,nullptr,nullptr);
	Node* node7 = new Node(7,nullptr,nullptr);
	Node* node4 = new Node(4,node6,node7);
	
	Node* node3 = new Node(3,nullptr,nullptr);
	Node* node1 = new Node(1,node3,node4);
	
	Node* node5 = new Node(5,nullptr,nullptr);
	Node* node2 = new Node(2,nullptr,node5);
	Node* node0 = new Node(0,node1,node2);
	
		
	Mytree t = Mytree(node0);
	cout << "NLR: ";	
	NLR(t.root);
	cout << "\nLNR: ";
	LNR(t.root);
	cout << "\nLRN: ";
	LRN(t.root);
	

	return 0;
}
