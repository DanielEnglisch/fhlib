/*CPP********************************************************************
* FILENAME :        tree.cpp
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
*CPP*/

#include "tree.h"

/////////////
// public //
/////////////

tree::tree() : root{NULL} {
}

tree::~tree(){
    destroy_tree();
}

void tree::insert(int key) {
    if (root != NULL)
        insert(key, root);
    else {
        root = new node;
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

node *tree::search(int key) {
    return search(key, root);
}

void tree::destroy_tree() {
    destroy_tree(root);
}

/////////////
// private //
/////////////

void tree::destroy_tree(node *leaf) {
    if (leaf != NULL) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void tree::insert(int key, node *leaf) {
    // go left
    if (key < leaf->key_value) {
        if (leaf->left != NULL)
            insert(key, leaf->left);
        else {
            leaf->left = new node;
            leaf->left->key_value = key;
            leaf->left->left = NULL;    //Sets the left child of the child node to null
            leaf->left->right = NULL;   //Sets the right child of the child node to null
        }
    }// go right
    else if (key >= leaf->key_value) {
        if (leaf->right != NULL)
            insert(key, leaf->right);
        else {
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = NULL;  //Sets the left child of the child node to null
            leaf->right->right = NULL; //Sets the right child of the child node to null
        }
    }
}

node *tree::search(int key, node *leaf) {
    if (leaf != NULL) {
        if (key == leaf->key_value)
            return leaf;
        if (key < leaf->key_value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    } else return NULL;
}