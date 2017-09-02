#include <iostream>
#include <string>

using namespace std;

class LinkedList {
private:
	struct Node {
		int data;
		Node* next;
	};
	Node* top = nullptr;
	void deleteNode(Node*& n) {
		if (n->next != nullptr) {
			deleteNode(n->next);
		}
		

			delete n;
			n = nullptr;
		
	}
public:
	void add(int i) {

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

	LinkedList() {
		cout << "Constructor" << endl;
	}

	~LinkedList() {
		cout << "Decontructor" << endl;
		deleteNode(top);
	}
	

};

int main() {

	LinkedList* myList = new LinkedList();
	myList->add(1);
	myList->add(2);
	myList->add(3);
	myList->add(4);
	myList->list();
	delete myList;

	return  0;
}