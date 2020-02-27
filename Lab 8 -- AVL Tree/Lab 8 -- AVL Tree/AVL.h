#pragma once
#include "AVLInterface.h"
#include "Node.h"
#include <stddef.h>
#include <stdlib.h> 

using namespace std;

class AVL : public AVLInterface {

public:
	AVL();
	~AVL();

	NodeInterface * getRootNode() const;

	bool add(int data);

	bool remove(int data);

	void clear();

private:
	Node * root;
	int getHighest(Node * parent);
	void clearRecursion(Node * parent);
	bool removeRecursive(Node *& parent, int data);
	bool insert(Node *& parent, int data);
	int updateRightHeight(Node *& parent);
	int updateLeftHeight(Node *& parent);
	int max(int left, int right);
	bool isBalanced(Node *& parent);
	int findCondition(Node *& parent);
	void rotate(Node *& parent, int condition);
	void rotateLeft(Node *& parent);
	void rotateRight(Node *& parent);
};

