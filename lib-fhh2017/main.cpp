#include "lib-fhh2017.h"
#include <string>

using namespace std;
using StringLinkedList = LinkedList<string>;
using StringNode = StringLinkedList::Node;

struct Vec3 {
	int x, y, z;
	Vec3() {}
	Vec3(int x, int y, int z)
	: x(x), y(y), z(z)
	{

	}
};

int main() {

	StringLinkedList* myList = new StringLinkedList();
	myList->add("str1");
	const StringNode* nodePtr = myList->add("str2");
	myList->add("str3");
	myList->add("str3");
	myList->add("str4");
	delete myList;
	myList = nullptr;

	LinkedList<Vec3>* vectors = new LinkedList<Vec3>();
	Vec3 v1(1, 2, 3);
	Vec3 v2(4, 5, 6);

	vectors->add(v1);
	vectors->add(v2);

	return  0;
}