#include <iostream>
#include <string>

using namespace std;

template <typename T>
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

int main() {

	LinkedList<string>* myList = new LinkedList<string>();
	myList->add("str1");
	myList->add("str2");
	cout << "LEN: " << myList->getLength() << endl;
	myList->add("str3");
	myList->add("str4");
	myList->list();

	delete myList;
	myList = nullptr;

	return  0;
}