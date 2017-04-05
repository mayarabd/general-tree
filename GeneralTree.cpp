#include "GeneralTree.h"
#include<iostream>
#include<vector>
#include<exception>
#include <sstream>
using namespace std;

/****************************************************
 * name: Mayara Brandao Dusheyko
 * Description: Implementation of a geral tree
 ******************************************************/


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                      HELPER METHODS
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//recursively prints a tree
void GTree::printFrom(GTNode* start) const {
    if (start == NULL) {
        return;
    }
    
    //check if node is a leaf and if so print its data
    if (start -> children.size() == 0) {
        cout << start -> data;
    //if it's not a leaf, print (
    } else {
        cout << "(";
        //traversal node's children.
        //if it is a leaf, print its data
        for (int i = 0; i < start -> children.size(); i++) {
            if (start -> children[i] -> children.size() == 0) {
                cout << start -> children[i] -> data;
                //if its not a leaf recurse with current node as starting point
            } else {
                printFrom(start -> children[i]);
            }
        }
        cout << ")";
    }
    
}


//Copy other tree into a new tree by calling copyFrom
void GTree::copyOther(const GTree& other) {
    
    GTree::copyFrom(other.root, this->root);
    
}

//recursively copy the nodes of a tree into another tree
void GTree::copyFrom(GTNode* start, GTNode* parent) {
    
    //checks if the tree being copied is empty
    if (start == NULL) {
        return;
    }
    
    //saves inserted node to be parent
    parent = insert(start -> data, parent);
    //iterate through all children
    for (int i = 0; i < start -> children.size(); i++) {
        GTree::copyFrom(start->children[i], parent);
    }
    
}

//calls recursive function clearFrom to clear tree
void GTree::clear() {
    
    GTree::clearFrom(root);
    root = NULL;
}

//recursive function to clear tree
void GTree::clearFrom(GTNode* start) {
    
    if (start == NULL) {
        return;
    }
    
    //if node has children, iterate children
    if (start -> children.size() > 0) {
        for (int i = 0; i < start -> children.size(); i++) {
            GTree::clearFrom(start -> children[i]);
        }
    }
    
    delete start;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  CONSTRUCTOR, COPY CONSTRUCTOR, DESTRUCTOR AND ASSIGNMENT OPERATOR
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


//default constructor
GTree::GTree(): root(NULL) {}

//copy constructor
GTree::GTree(const GTree& other): root(NULL) {
    GTree::copyOther(other);
}

//destructor
GTree::~GTree() {
    void clear();
}

//assignment operator
GTree& GTree::operator=(const GTree& other) {
    //checks if the trees are not the same
    if (this != &other) {
        clear();
        copyOther(other);
    }
    
    return *this;
    
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                              TREE METHODS
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//add a node to the tree
//throws NoParentException
//throws invalid_argument in case of wrong data type
GTNode* GTree::insert(char value, GTNode* parent) {
   
    //adding a new node to a NULL parent in a not empty tree
    //will throw exception
    if (parent == NULL && root != NULL) {
            throw NoParentException();
    }
    
    //creates a new node
    GTNode* newNode = new GTNode();
    newNode ->data = value;
    
    //adding first node to the tree
    if (parent == NULL && root == NULL) {
        root = newNode;
    //add new node to parent
    } else {
        parent->children.push_back(newNode);
    }
    return newNode;
    
}

//method to print a general tree
void GTree::print() const {
    if (root == NULL) {
            return;
    }
    //call helper method
    GTree::printFrom(root);
    cout << endl;
    
}
