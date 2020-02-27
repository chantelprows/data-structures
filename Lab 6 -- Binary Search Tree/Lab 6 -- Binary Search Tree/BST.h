#pragma once
#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface {

public:
	
	BST();
	~BST();

	NodeInterface * getRootNode() const;

	bool add(int data);

	bool remove(int data);

	void clear();

private:

	Node *root;
	int getHighest(Node * parent);
	void clearRecursion(Node * parent);
	bool removeRecursive(Node *& parent, int data);
	bool insert(Node *& parent, int data);

};