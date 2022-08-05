
#ifndef _MakeTree_hpp
#define _MakeTree_hpp

#include<iostream>
#include<string>

#include "TreeNode.hpp"
//#include "GraphNode.hpp" //TEST DELETE AFTER

//BIN SEARCH TREE

class MakeTree {
public:
    MakeTree(): _root(nullptr) {} //TODO?
    void insert( GraphNode *nNode ); 
    GraphNode *find( std::string name );
    void print() { print(_root); };   // print the tree using in-order traversal
    TreeNode  *getRoot() { return _root; }

private:
    TreeNode *insert(TreeNode *tNode, GraphNode *nNode); 
    void print(TreeNode *root); 
    TreeNode *_root;
};

#endif
