ReadMe General Tree
****************
Student: Mayara Brandao Dusheyko
****************


Files:  GeneralTree.h
	GeneralTree.cpp
	main.cpp

Compiled using xCode

Description: This program implements a general tree class, a node class, an exception class. The node class uses a vector to store children. The exception class is thrown in case of a node being inserted under a NULL parent in a not empty tree. The tree class has insert and print method as well as several helper methods that use recursion.
Users should be able to create a tree, add values to it, use assignment operator (e.g.: tree1 = tree2 ) as well as copy constructor (e.g.: GTree tree3(tree2)).
 	
	
***********************  SAMPLE RUN #1 :  *********************** 

TEST 1: 
gt:
(c(ab))

TEST 2: 
gt2:
(abab(cd)d(ef(g(h))))

TEST 3:  gt3 = gt 
gt3: 
(c(ab))

TEST 4: gt4(gt2)  
gt4: 
(abab(cd)d(ef(g(h))))

TEST 5: 
gt6
((abcd(cd)(cd)f(cd(cd(h)(abcd)ggg(hh))))(abcd(cd)(cd)d(ef(g(h)(abab)ggg(ab)))))
gt7(gt6): 
((abcd(cd)(cd)f(cd(cd(h)(abcd)ggg(hh))))(abcd(cd)(cd)d(ef(g(h)(abab)ggg(ab)))))

gt8 = gt7
((abcd(cd)(cd)f(cd(cd(h)(abcd)ggg(hh))))(abcd(cd)(cd)d(ef(g(h)(abab)ggg(ab)))))

TEST 6: gt8 = emptyTree:

TEST 7: gt3 = gt3
(c(ab))

TEST 8: emptyTree = emptyTree

TEST 8: emptyTree = gt6
((abcd(cd)(cd)f(cd(cd(h)(abcd)ggg(hh))))(abcd(cd)(cd)d(ef(g(h)(abab)ggg(ab)))))

TEST 9:  gt9 = gt3 = gt2;
Before
gt9: 
gt3: (c(ab))
gt2: (abab(cd)d(ef(g(h))))
After:
gt9: (abab(cd)d(ef(g(h))))
gt3: (abab(cd)d(ef(g(h))))
gt2: (abab(cd)d(ef(g(h))))

TEST 10: (should throw an exception)
Parent not found Exception.
Program ended with exit code: 0
