// C/C++ function to search a given key in a given BST
struct node* search(struct node* root, int key) {
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->key == key)
		return root;
	
	if (root->key < key)
		return search(root->right, key);
	
	if (root->key > key)
		return search(root->left, key);
}