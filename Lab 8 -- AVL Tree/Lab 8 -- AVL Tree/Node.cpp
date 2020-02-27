#include "Node.h"

Node::Node(int data) {
	value = data;
	left == NULL;
	right == NULL;
	rightHeight = 0;
	leftHeight = 0;
}

int Node::getData() const {
	return value;
}

Node * Node::getLeftChild() const {
	return left;
}

Node * Node::getRightChild() const {
	return right;
}

int Node::getHeight() {
	if (leftHeight > rightHeight) {
		return leftHeight + 1;
	}
	else {
		return rightHeight + 1;
	}
}