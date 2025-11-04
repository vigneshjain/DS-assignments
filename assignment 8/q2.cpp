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
Node* insertValue(Node* root, int val){
	if(root == NULL){
		return root;
	}
	if(val < root->data){
		root->left = insertValue(root->left, val);
		else
		root->right = (root->right, val);
	}
	return root;
}
Node* searchRecursive(Node* root, int key){
	if(root == NULL || root->data == key)
	return root;
	if(key<root->data
	searchRecursive(root->left, key);
	else
	searchRecursive(root->right, key);
	return root;
}
Node* searchIterative(Node*root, int key){
	while(root != NULL || root->data != key){
		if(key<root){
			root = root->left;
		}
		else{
			root = root->right;
		}
	}
	return root;
}
int findMax(Node*root){
	if(root==NULL){
		return root;
	}
	while(root->right != NULL){
		root = root->right;
	}
	return root;
}
int findMin(Node*root){
	if(root==NULL){
		return root;
	}
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}
Node* inorderSuccessor(Node* root, Node* target) {
    if (target->right != NULL)
        return findMin(target->right); // Case 1

    Node* successor = NULL;
    while (root != NULL) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (target->data > root->data)
            root = root->right;
        else
            break;
    }
    return successor;
}
Node* inorderPredecessor(Node* root, Node* target) {
    if (target->left != NULL)
        return findMax(target->left); // Case 1

    Node* predecessor = NULL;
    while (root != NULL) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else if (target->data < root->data)
            root = root->left;
        else
            break;
    }
    return predecessor;
}
int main() {
    Node* root = NULL;
    int values[] = {20, 8, 22, 4, 12, 10, 14};
    for (int v : values) root = insert(root, v);

    int key = 10;
    Node* searchNode = searchIterative(root, key);
    if (searchNode)
        cout << "Found " << key << " in BST\n";
    else
        cout << key << " not found\n";

    cout << "Minimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    Node* succ = inorderSuccessor(root, searchNode);
    if (succ)
        cout << "Inorder Successor of " << key << " is " << succ->data << endl;
    else
        cout << "No inorder successor for " << key << endl;

    Node* pred = inorderPredecessor(root, searchNode);
    if (pred)
        cout << "Inorder Predecessor of " << key << " is " << pred->data << endl;
    else
        cout << "No inorder predecessor for " << key << endl;

    return 0;
}
