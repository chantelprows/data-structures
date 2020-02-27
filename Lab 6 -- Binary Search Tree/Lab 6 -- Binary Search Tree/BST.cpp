#include "BST.h"

BST::BST() {
	root = NULL;
}

BST::~BST() {
	clear();
}

NodeInterface * BST::getRootNode() const {
	return root;
}

bool BST::add(int data) {
	if (root == NULL) {
		root = new Node(data);
		return true;
	}
	else if (insert(root, data)) {
		return true;
	}
	else {
		return false;
	}
}

bool BST::insert(Node *& parent, int data) {
	if (parent == NULL) {
		parent = new Node(data);
		return true;
	}
	else if (parent->value < data) {
		return insert(parent->right, data);
	}
	else if (parent->value > data) {
		return insert(parent->left, data);
	}
	else {
		return false;
	}
}

bool BST::remove(int data) {
	if (removeRecursive(root, data)) {
		return true;
	}
	else {
		return false;
	}
}

bool BST::removeRecursive(Node *& parent, int data) {
	
	if (parent == NULL) {
		return false;
	}
	else if (data < parent->value) {
		return removeRecursive(parent->left, data);
	}
	else if (data > parent->value) {
		return removeRecursive(parent->right, data);
	}
	else {
		if (parent->left == NULL && parent->right == NULL) {
			delete parent;
			parent = NULL;
			return true;
		}
		else if (parent->left != NULL && parent->right == NULL) {
			Node * tmp = parent;
			parent = parent->left;
			delete tmp;
			return true;
		}
		else if (parent->left == NULL && parent->right != NULL) {
			Node * tmp = parent;
			parent = parent->right;
			delete tmp;
			return true;
		}
		else if (parent->right != NULL && parent->left != NULL) {
			parent->value = getHighest(parent->left);
			return removeRecursive(parent->left, parent->value);
		}
		else {
			return false;
		}
	}
}

int BST::getHighest(Node * parent) {

	if (parent->right == NULL) {
		return parent->value;
	}
	else {
		return getHighest(parent->right);
	}
}

void BST::clear() {
	clearRecursion(root);
	root = NULL;
}

void BST::clearRecursion(Node * parent) {
	if (parent != NULL) {
		clearRecursion(parent->left);
		clearRecursion(parent->right);
		delete parent;
	}
}
