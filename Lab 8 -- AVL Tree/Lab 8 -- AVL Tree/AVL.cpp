#include"AVL.h"

AVL::AVL() {
	root = NULL;
}

AVL::~AVL() {
	clear();
}

NodeInterface * AVL::getRootNode() const {
	return root;
}

bool AVL::add(int data) {
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

bool AVL::insert(Node *& parent, int data) {
	if (parent == NULL) {
		parent = new Node(data);
		return true;
	}
	else if (parent->value < data) {
		bool result = insert(parent->right, data);
		if (result == true) {
			parent->rightHeight = updateRightHeight(parent);
			if (!isBalanced(parent)) {
				int condition = findCondition(parent);
				rotate(parent, condition);
			}
		}
		return result;
	}
	else if (parent->value > data) {
		bool result = insert(parent->left, data);
		if (result == true) {
			parent->leftHeight = updateLeftHeight(parent);
			if (!isBalanced(parent)) {
				int condition = findCondition(parent);
				rotate(parent, condition);
			}
		}
		return result;
	}
	else {
		return false;
	}
}

int AVL::updateRightHeight(Node *& parent) {
	if (parent->right == NULL) {
		return 0;
	}
	int h = max(parent->right->leftHeight, parent->right->rightHeight);
	return h + 1;
}

int AVL::updateLeftHeight(Node *& parent) {
	if (parent->left == NULL) {
		return 0;
	}
	int h = max(parent->left->leftHeight, parent->left->rightHeight);
	return h + 1;
}

int AVL::max(int left, int right) {
	if (left < right) {
		return right;
	}
	else {
		return left;
	}
}

bool AVL::isBalanced(Node *& parent) {
	if (abs(parent->rightHeight - parent->leftHeight) > 1) {
		return false;
	}
	return true;
}

int AVL::findCondition(Node *& parent) {
	if (parent->leftHeight >= parent->rightHeight) {
		if (parent->left->leftHeight >= parent->left->rightHeight) {
			return 0;
		}
		else {
			return 1;
		}
	}
	if (parent->leftHeight <= parent->rightHeight) {
		if (parent->right->leftHeight > parent->right->rightHeight) {
			return 2;
		}
		else {
			return 3;
		}
	}
}

void AVL::rotate(Node *& parent, int condition) {
	switch (condition) {
	case 0:   // left-left
		rotateRight(parent);
		break;

	case 1:   //left-right
		rotateLeft(parent->left);
		rotateRight(parent);
		break;

	case 2:   //right-left
		rotateRight(parent->right);
		rotateLeft(parent);
		break;

	case 3:   //right-right
		rotateLeft(parent);
		break;
	}
}

void AVL::rotateLeft(Node *& parent) {
	Node * oldroot = parent;
	Node * newroot = parent->right;
	parent = newroot;
	oldroot->right = newroot->left;
	newroot->left = oldroot;

	oldroot->rightHeight = updateRightHeight(oldroot);
	newroot->leftHeight = updateLeftHeight(newroot);
}

void AVL::rotateRight(Node *& parent) {
	Node * oldroot = parent;
	Node * newroot = parent->left;
	parent = newroot;
	oldroot->left = newroot->right;
	newroot->right = oldroot;

	oldroot->leftHeight = updateLeftHeight(oldroot);
	newroot->rightHeight = updateRightHeight(newroot);
}

bool AVL::remove(int data) {
	if (removeRecursive(root, data)) {
		return true;
	}
	else {
		return false;
	}
}

bool AVL::removeRecursive(Node *& parent, int data) {

	if (parent == NULL) {
		return false;
	}
	else if (data < parent->value) {
		bool result;
		result = removeRecursive(parent->left, data);
		if (result == true) {
			parent->leftHeight = updateLeftHeight(parent);
			if (!isBalanced(parent)) {
				int condition = findCondition(parent);
				rotate(parent, condition);
			}
		}
		return result;
	}
	else if (data > parent->value) {
		bool result;
		result = removeRecursive(parent->right, data);
		if (result == true) {
			parent->rightHeight = updateRightHeight(parent);
			if (!isBalanced(parent)) {
				int condition = findCondition(parent);
				rotate(parent, condition);
			}
		}
		return result;
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
			parent->rightHeight = updateRightHeight(parent);
			return true;
		}
		else if (parent->left == NULL && parent->right != NULL) {
			Node * tmp = parent;
			parent = parent->right;
			delete tmp;
			parent->leftHeight = updateLeftHeight(parent);
			return true;
		}
		else if (parent->right != NULL && parent->left != NULL) {
			parent->value = getHighest(parent->left);
			bool result = removeRecursive(parent->left, parent->value);
			parent->leftHeight = updateLeftHeight(parent);
			if (!isBalanced(parent)) {
				int condition = findCondition(parent);
				rotate(parent, condition);
			}
			return result;
		}
		else {
			return false;
		}
	}
}

int AVL::getHighest(Node * parent) {

	if (parent->right == NULL) {
		return parent->value;
	}
	else {
		return getHighest(parent->right);
	}
}

void AVL::clear() {
	clearRecursion(root);
	root = NULL;
}

void AVL::clearRecursion(Node * parent) {
	if (parent != NULL) {
		clearRecursion(parent->left);
		clearRecursion(parent->right);
		delete parent;
	}
}



