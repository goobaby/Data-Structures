
#ifndef _TreeNode_hpp
#define _TreeNode_hpp

#include<iostream>
#include<string>

#include "GraphNode.hpp" //possibly worng

//class GraphNode; //temp/maybe a placeholder/C extern/Two pass complier

class TreeNode {
public:
    TreeNode( GraphNode *nNode ): leftSubtree(nullptr), rightSubtree(nullptr), makeNode(nNode) {}

    TreeNode *left() { return leftSubtree; }              // getter
    void left( TreeNode *leftPtr ) { this->leftSubtree = leftPtr; }  // setter

    TreeNode *right() { return rightSubtree; }
    void right( TreeNode *rightPtr ) {this->rightSubtree = rightPtr; }

    void print() {makeNode->print();}   // print the value of this node
    GraphNode *graphNode() {return makeNode;};

private:
    GraphNode *makeNode;
    TreeNode *leftSubtree, *rightSubtree;
};

#endif
