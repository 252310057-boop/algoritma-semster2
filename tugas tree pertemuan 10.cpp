#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node* createNode(int value) {
	Node *newNode = new Node;
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void preorder (Node *root) {
	if (root == NULL)
		return;
		
	cout << root->data << " ";
	preorder (root->left);
	preorder (root->right);
}

void inorder (Node *root) {
	if (root == NULL)
		return;
		
	inorder(root->left);
	cout << root->data << " "; 
	inorder (root->right);
}
void postorder (Node *root) {
		if (root == NULL)
	return;
	
	postorder (root->left);
	postorder (root->right);
	cout << root->data << " ";
}

int main() {
	
	Node *root = createNode(7);

	root->left = createNode(14);
	root->right = createNode(83);
	
	root->left->left = createNode(91);
	root->left->right = createNode(102);
	
	root->left->right->left = createNode(31);
	root->left->right->right = createNode(87);
	
	root->left->right->left->left = createNode(93);
	
	root->left->right->left->left->left = createNode(24);
	root->left->right->left->left->right = createNode(76);
	
	root->right->left = createNode(192);
	root->right->right = createNode(932);
	
	root->right->right->right = createNode(153);
	
	root->right->right->right->left = createNode(772);
	root->right->right->right->right = createNode(812);
cout << "Traversal Preorder : ";
preorder (root);

cout << "\nAntraversal Inorder : ";
inorder (root);

cout << "\nTraversal Postorder : ";
postorder(root);

return 0;
}
