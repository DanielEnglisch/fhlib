#pragma once
#include <iostream>

using namespace std;

template<class T>
class LinkedList {
private:
	struct Node {
		T data;
		Node* next;
	};
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
	void add(T i) {

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
	}

	void list() {
		Node* scanner = nullptr;
		scanner = top;
		int i = 0;
		while (scanner != nullptr) {
			cout << i << " Data:" << scanner->data << endl;
			i++;
			scanner = scanner->next;
		}
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
