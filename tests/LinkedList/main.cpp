#include <iostream>

#include "linkedlist.h"

int main() {

    linkedList *l = new linkedList;
    linkedList l2 {100};

    std::cout << "Linked List Test" << std::endl;

    l->prependNode(3);
    l->prependNode(2);
    l->appendNode(4);

    if (l->findNode(2)) std::cout << "found\n";

    l->printList();
    l2.printList();

    delete l;
    return 0;
}