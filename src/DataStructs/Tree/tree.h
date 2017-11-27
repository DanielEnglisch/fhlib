/*H**********************************************************************
* FILENAME :        tree.h
*
* DESCRIPTION :
*       tree
*
* NOTES :
*
* AUTHOR :    andir       START DATE :    27.11.2017
*
* CHANGES :
*
*H*/
#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <stdio.h>

struct node {
    int key_value;
    node *left;
    node *right;
};

class tree {
public:
    tree();
    ~tree();

    void insert(int key);
    node *search(int key);
    void destroy_tree();

private:
    node *root;

    void destroy_tree(node *leaf);
    void insert(int key, node *leaf);
    node *search(int key, node *leaf);
};


#endif //TREE_TREE_H
