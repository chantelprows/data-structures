#include "Node.h"


Node::Node(int data) {
	value = data;
	left = NULL;
	right = NULL;
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
