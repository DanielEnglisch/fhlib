#include "lib-fhh2017.h"
#include <string>

using namespace std;

int main() {

	LinkedList<string>* myList = new LinkedList<string>();
	myList->add("str1");
	myList->add("str2");
	myList->add("str3");
	myList->add("str4");
	myList->list();

	delete myList;
	myList = nullptr;

	return  0;
}