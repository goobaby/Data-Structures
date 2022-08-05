
#ifndef _Graph_hpp
#define _Graph_hpp

#include<iostream>
#include<cstring>

#include "MakeTree.hpp"

class Graph {
public:
    Graph( std::string name ) {_fileToMake = name; _tree = new MakeTree(); }
    void print(); //prints every node of the BST and its values
    void parseDepGraph(); //Calls Tokenizer and puts Nodes in BST and creates pointers to the depenancys
    void runMake(); //runs make of ONLY the root of BST
    bool isCyclic();//looks at all of BST and see if any are cyclic
    void runMake(GraphNode *); //This is public because if I ever need an argument for "make" I can call this in main and say to run clean or other nodes.
    //However that is not implentated so it kept here to future-proof

private:
    bool isCyclic(GraphNode *); //HELPER
    

private:
    std::string _fileToMake, _targetToMake; //UNUSED _targetToMake
    GraphNode *firstTarget; //UNUSED
    MakeTree *_tree;  // MakeTree implements a binary-search tree similar to BinSearchTree
    bool upToDate = false;
};

#endif
