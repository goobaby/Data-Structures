//
// Created by student on 9/21/21.
//

//#ifndef BINARY_SEARCH_TREE_TREENODE_HPP
//#define BINARY_SEARCH_TREE_TREENODE_HPP
//
//#endif //BINARY_SEARCH_TREE_TREENODE_HPP

#ifndef _TreeNode
#define _TreeNode

class TreeNode {
public:
    TreeNode(): left(nullptr), right(nullptr), data(0) {}
    TreeNode( int n ): left(nullptr), right(nullptr), data(n) {}

    TreeNode *leftSubtree() { return left; }
    TreeNode *rightSubtree() { return right; }

    void leftSubtree( TreeNode *left ) { this->left = left; }
    void rightSubtree(TreeNode *right) { this->right = right; }

    int& value() { return data; }

private:
    TreeNode *left, *right;
    int data;
};

#endif
