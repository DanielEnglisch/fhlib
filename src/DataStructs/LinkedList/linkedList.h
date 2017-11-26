/*H**********************************************************************
* FILENAME :        linkedList.h
*
* DESCRIPTION :
*       Linked List
*
* NOTES :
*
*
*
* AUTHOR :    Andreas Roither        START DATE :    26.11.17
*
* CHANGES :
*
*H*/

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>

struct node {
    int data;
    node *next;
};

class linkedList {
public:
    linkedList();
    linkedList(int data);
    ~linkedList();
    void prependNode(int data);
    void appendNode(int data);
    void deleteNode(int data);
    void printList();
    bool findNode(int data);
    void freelist();

private:
    node *head {NULL};
    node *tail {NULL};
};



#endif //LINKEDLIST_LINKEDLIST_H
