
#ifndef GENERAL_TREE_H
#define GENERAL_TREE_H
#include <stdio.h>
#include<vector>
#include<exception>

/****************************************************
 * name: Mayara Brandao Dusheyko
 * ID: 915 730 756
 * email: mbrandao@sfsu.edu
 * Compile: xcode
 * Description: Header file to Geral tree
 ******************************************************/

//Exception class
class  NoParentException: public std::exception {
public:
    virtual const char* what() const throw() {
        return "Parent not found Exception.";
    }
};


//Node Class
class GTNode {
public:
    //default constructor
    GTNode() { /* empty body constructor */}
    
    //data
    char data;
    
    //children
    std::vector<GTNode*> children;
    
  
    
};

//Tree Class
class GTree {
public:
    //default constructor
    GTree();
    
    //copy constructor
    GTree(const GTree& other);
    
    //destructor
    ~GTree();
    
    //assignment operator
    GTree& operator=(const GTree& other);
    
    //add a node to the tree
    GTNode* insert(char value, GTNode* parent); 
    
    //method to print the tree
    void print() const;
   
    
private:
    GTNode* root;
    
    /** Helper methods **/
    
    void printFrom(GTNode* root) const;
    
    void copyOther(const GTree& other);

    void copyFrom(GTNode* start, GTNode* parent);
    
    void clear();
    
    void clearFrom(GTNode* start);
    
};


#endif /* GENERAL_TREE_H */
