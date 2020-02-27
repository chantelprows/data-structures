#pragma once
#include "NodeInterface.h"

class Node : public NodeInterface {

	friend class BST;

public:

	Node(int data);
	~Node() {}

	int getData() const;

	Node * getLeftChild() const;

	Node * getRightChild() const;

private:
	int value;
	Node * left;
	Node * right;
	
};