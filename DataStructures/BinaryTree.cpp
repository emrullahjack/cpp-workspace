#include <iostream>

using namespace std;

// A binary tree node has data, a pointer to left child
// and a pointer to right child
struct Node {
	int data;
	struct Node *left, *right;
	Node (int data) {
		this->data = data;
		left = right = NULL;
	}
};

// Given a binary tree, print it's nodes according to
// the "bottom-up" post order traversal
void printPostorder(struct Node* node) {
	if (node == NULL)
		return;
	
	// first recur on the left subtree
	printPostorder(node->left);
	
	// then recur on right subtree
	printPostorder(node->right);
	
	// deal with the node
	cout << node->data << " ";
}

// Given a binary tree, print its nodes in inorder
void printInorder(struct Node* node) {
	if (node == NULL)
		return;
				
	// recur on the left subtree
	printInorder(node->left);
	
	// deal with the node 
	cout << node->data << " ";
	
	// recur on the right subtree
	printInorder(node->right);
}

// Given a binary tree, print its nodes in preorder
void printPreorder(struct Node* node) {
	if (node == NULL)
		return;
	
	cout << node->data << " ";
	printPreorder(node->left);
	printPreorder(node->right);
}

// Driver program
int main() {
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	
	cout << "\nPreorder traversal of binary tree is \n"; 
	printPreorder(root);
	cout << "\n";
	
	cout << "\nInorder traversal of binary tree is \n"; 
	printInorder(root);  
	cout << "\n";
  
	cout << "\nPostorder traversal of binary tree is \n"; 
	printPostorder(root);
	cout << "\n";
}
