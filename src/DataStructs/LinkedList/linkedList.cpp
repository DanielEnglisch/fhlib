/*CPP**********************************************************************
* FILENAME :        linkedList.cpp
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
*CPP*/

#include "linkedlist.h"

node* createNode(int value) {
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    return temp;
}

linkedList::linkedList() : head{NULL}, tail{NULL} {
}

linkedList::linkedList(int data) : head {createNode(data)}{
}

linkedList::~linkedList() {
    node *cur;

    while (head != NULL) {
        cur = head->next;
        delete head;
        head = cur;
    }
}

void linkedList::prependNode(int data) {
    node *temp = createNode(data);
    temp->next = head;
    head = temp;
}

void linkedList::appendNode(int data) {
    node *pre = new node;
    node *cur = new node;
    node *newnode = createNode(data);
    cur = head;

    while (cur != NULL)
    {
        pre = cur;
        cur = cur->next;
    }

    pre->next = newnode;
}

void linkedList::deleteNode(int data) {
    node *pre = new node;
    node *cur = new node;
    cur = head;

    while (cur != NULL && cur->data != data)
    {
        pre = cur;
        cur = cur->next;
    }

    if (cur != NULL) {
        pre->next = cur->next;
        free(cur);
    } else {
        std::cout<<"Node not found";
    }
}

void linkedList::printList() {
    node *temp = new node;
    temp = head;

    while (temp != NULL)
    {
        std::cout<<temp->data<<'\n';
        temp = temp->next;
    }
}

bool linkedList::findNode(int data) {
    node *temp = new node;
    temp = head;

    while (temp != NULL)
    {
        if (temp->data == data) return true;
        temp = temp->next;
    }
    return false;
}

void linkedList::freelist() {
    node *cur;

    while (head != NULL) {
        cur = head->next;
        delete head;
        head = cur;
    }
}
