#include "lib-fhh2017.h"
#include <string>

using namespace std;
using StringLinkedList = LinkedList<string>;
using StringNode = StringLinkedList::Node;

int main() {

	StringLinkedList* myList = new StringLinkedList();
	myList->add("str1");
	const StringNode* nodePtr = myList->add("str2");
	myList->add("str3");
	myList->add("str4");
	myList->list();
	delete myList;
	myList = nullptr;

	return  0;
}