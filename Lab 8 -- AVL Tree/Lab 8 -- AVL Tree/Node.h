#pragma once
#include "NodeInterface.h"
#include <stddef.h>

class Node : public NodeInterface {

	friend class AVL;

public:

	Node(int data);
	~Node() {}

	int getData() const;

	Node * getLeftChild() const;

	Node * getRightChild() const;

	int getHeight();

private:

	int value;
	int rightHeight;
	int leftHeight;
	Node * left;
	Node * right;

};
