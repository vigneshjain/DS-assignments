#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* newNode(int value){
	Node* node = new Node;
	node->data = value;
	node->left = node->right = NULL;
	return node;
}
void preOrder(Node* root){
	if(root == NULL) return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(Node* root){
	if(root == NULL) return;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}
void postOrder(Node* root){
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}
int main(){
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right  = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	cout << "the Pre-Order traversal is as follows: ";
	preOrder(root);
	cout << endl;
	cout << "the In-Order traversal is as follows: ";
	inOrder(root);
	cout << endl;
	cout<< "the Post-Order traversal is as follows: ";
	postOrder(root);
	cout << endl;
}
