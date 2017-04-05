#include "GeneralTree.h"
#include <iostream>
#include <sstream>
using namespace std;

/****************************************************
 * name: Mayara Brandao Dusheyko
 * ID: 915 730 756
 * email: mbrandao@sfsu.edu
 * Compile: xcode
 * Description: Test for General Tree
 ******************************************************/


void parseRecursive(stringstream& ss, GTree& gt, GTNode* parent)
{
    char nextChar;
    while (true) {
        ss >> nextChar;
        if (ss.fail())
            return;
        
        if (nextChar == ')')
            return;
        
        if (nextChar == '(') {
            GTNode* newGTNode = gt.insert(' ', parent);
            parseRecursive(ss, gt, newGTNode);
        } else {
            gt.insert(nextChar, parent);
        }
    }
}

void parseExpression(const string& expr, GTree& gt)
{
    stringstream ss;
    ss << expr;
    
    parseRecursive(ss, gt, NULL);
}

int main()
{
    
    try {
        
        GTree gt;

        cout << "TEST 1: " << endl;
        // This should print:
        // (c(ab))
        GTNode* grandparent = gt.insert('.', NULL);
        GTNode* parent1 = gt.insert('c', grandparent);
        GTNode* parent2 = gt.insert('.', grandparent);
        GTNode* kid1 = gt.insert('a', parent2);
        GTNode* kid2 = gt.insert('b', parent2);
        cout << "gt:" << endl;
        gt.print();
        cout << endl;
        
        cout << "TEST 2: " << endl;
        // This should print:
        // (abab(cd)d(ef(g(h))))
        GTree gt2;
        parseExpression("(abab(cd)d(ef(g(h))))", gt2);
        cout << "gt2:" << endl;
        gt2.print();
        cout << endl;
        
        cout << "TEST 3:  gt3 = gt " << endl;
        // This should print:
        // (c(ab))
        GTree gt3 = gt;
        cout << "gt3: " << endl;
        gt3.print();
        cout << endl;
        
        cout << "TEST 4: gt4(gt2)  " << endl;
        // This should print:
        // (abab(cd)d(ef(g(h))))
        cout << "gt4: " << endl;
        GTree gt4(gt2);
        gt4.print();
        cout << endl;
        
        cout << "TEST 5: " << endl;
        GTree gt6;
        parseExpression("((abcd(cd)(cd)f(cd(cd(h)(abcd)ggg(hh))))(abcd(cd)(cd)d(ef(g(h)(abab)ggg(ab)))))", gt6);
        cout << "gt6" << endl;
        gt6.print();
        
        cout << "gt7(gt6): " << endl;
        GTree gt7(gt6);
        gt7.GTree::print();
        cout << endl;
        
        cout << "gt8 = gt7" << endl;
        GTree gt8 = gt7;
        gt8.GTree::print();
        cout << endl;
        
        cout << "TEST 6: gt8 = emptyTree:" << endl;
        GTree emptyTree;
        gt8 = emptyTree;
        gt8.print();
        cout << endl;

        cout << "TEST 7: gt3 = gt3" << endl;
        gt3 = gt3;
        gt3.print();
        cout << endl;
        
        cout << "TEST 8: emptyTree = emptyTree" << endl;
        emptyTree = emptyTree;
        emptyTree.print();
        cout << endl;
        
        cout << "TEST 8: emptyTree = gt6" << endl;
        emptyTree = gt6;
        emptyTree.print();
        //gt6.GTree::print();
        cout << endl;
    
        cout << "TEST 9:  gt9 = gt3 = gt2;" <<endl;
        cout << "Before" << endl;
        GTree gt9;
        
        cout << "gt9: ";
        gt9.GTree::print();
        cout << endl;
        
        cout << "gt3: ";
        gt3.GTree::print();
        
        cout << "gt2: ";
        gt2.GTree::print();


        gt9 = gt3 = gt2;
        
        cout << "After:" << endl;
        cout << "gt9: ";
        gt9.GTree::print();
        
        cout << "gt3: ";
        gt3.GTree::print();
        
        cout << "gt2: ";
        gt2.GTree::print();
        cout << endl;

        
        cout << "TEST 10: (should throw an exception)" << endl;
        //This should Throw Exception @ aParent2
        GTree myTree;
        GTNode* aParent1 = myTree.insert('.', NULL);
        GTNode* aParent2 = myTree.insert('a', NULL);
    
    } catch (NoParentException npe) {
        cout << npe.what() << endl;
    }
    
    return 0;
}

