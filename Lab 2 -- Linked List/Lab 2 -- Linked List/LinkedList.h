#pragma once
#include "LinkedListInterface.h"
#include <stdexcept>
#include <sstream>

template<typename T>
class LinkedList : public LinkedListInterface <T> {

public:

	class Node {
	public:
		T data;
		Node *next;

		Node(T newData) {
			data = newData;
			next = NULL;
		}
	};

	LinkedList() {
		head = NULL;
		listSize = 0;
	}

	~LinkedList() {
		clear();
	}

	virtual void insertHead(T value) {
		if (listSize == 0) {
			head = new Node(value);
			listSize = listSize + 1;
			return;
		}

		if (find(value) == true) {
			return;
		}


		Node *node = new Node(value);
		node->next = head;
		head = node;
		listSize = listSize + 1;
	}

	virtual void insertTail(T value) {
		if (listSize == 0) {
			head = new Node(value);
			listSize = listSize + 1;
			return;
		}

		Node *tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}

		if (find(value) == true) {
			return;
		}

		tmp->next = new Node(value);
		listSize = listSize + 1;
	}

	virtual void insertAfter(T value, T insertionNode) {
		Node *prev = head;
		Node *node = new Node(value);
		while ((prev != NULL) && !(insertionNode == prev->data)) {
			prev = prev->next;
		}

		if (prev == NULL) {
			delete node;
			return;
		}

		if (find(value) == true) {
			delete node;
			return;
		}
		
		node->next = prev->next;
		prev->next = node;

		listSize = listSize + 1;
	}

	virtual void remove(T value) {

		if (head == NULL) {
			return;
		}

		if (value == head->data) { 
			Node *cur = head;
			head = head->next;
			delete cur;
		}


		else {  
			Node *prev = head;
			while ((prev->next != NULL) && !(value == prev->next->data)) {
				prev = prev->next;
			}

			if (prev->next == NULL) {
				return;
			}

			Node *cur = prev->next;
			prev->next = cur->next;
			delete cur;
		}

		listSize = listSize - 1;
	}

	virtual void clear() {
		while (head != NULL) {
			Node *node = head->next;
			delete head;
			head = node;
		}
		listSize = 0;
	}

	virtual T at(int index) {
		if (index >= listSize || index < 0) {
			throw std::out_of_range("at " + std::to_string(index) + " out_of_range");
		}

		Node *cur = head;
		for (int i = 0; i < index; i++) {
			cur = cur->next;
		}

		return cur->data;
	}

	virtual int size() {
		return listSize;
	}

	virtual string toString() {
		Node *current = head;
		string listString = "";

		while (current != NULL) {
			if (listString != "") {
				listString = listString + " ";
			}
			//listString = listString + std::to_string(current->data);
			stringstream out;
			out << current->data;
			listString = listString + out.str();
			current = current->next;
		}
		return listString;
	}

	bool find(T value) {
		Node* node = head;
		while (node != NULL) {
			if (node->data == value) {
				return true;
			}
			node = node->next;
		}
		return false;
	}

private:
	int listSize;
	Node *head;

};