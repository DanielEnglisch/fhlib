#pragma once
#include <iostream>

using namespace std;

template<class T>
class LinkedList {
public:
	struct Node {
		T data;
		Node* next;
	};
private:
	Node* top = nullptr;
	int length = 0;
	void deleteNode(Node*& n) {
		if (n->next != nullptr) {
			deleteNode(n->next);
		}
		delete n;
		n = nullptr;
	}
public:
	const Node* add(T i) {
		
		Node* newNode = new Node();
		newNode->data = i;
		newNode->next = nullptr;

		if (top == nullptr) {
			top = newNode;
		}
		else {
			newNode->next = top;
			top = newNode;
		}
		length++;
		return newNode;
	}

	const int getLength() {
		return length;
	}

	LinkedList() {
		cout << "Constructor" << endl;
	}

	~LinkedList() {
		cout << "Decontructor" << endl;
		deleteNode(top);
	}

};
