#include<iostream>
#include<string>

#include "MakeTree.hpp"

void MakeTree::insert( GraphNode *nNode )
{
    if(find(nNode->getName()) == nullptr)
    {
        if(_root == nullptr)
        {
            _root = insert(_root, nNode);
        }
        else
        {
            insert(_root, nNode);
        }
        return;
    }
    return;
}

TreeNode* MakeTree::insert(TreeNode *tNode, GraphNode *nNode)
{
    
    if( tNode == nullptr )
    {
        return new TreeNode(nNode);
    }
    if( tNode->graphNode()->getName() < nNode->getName() )
    {
        tNode->right( insert( tNode->right(), nNode ) );
    }
    else
    {
        
        tNode->left( insert( tNode->left(), nNode ) );
    }
    return tNode;
}

GraphNode* MakeTree::find(std::string name)
{
    TreeNode* cur = getRoot();
    while( cur != nullptr)
    {
        if ( cur->graphNode()->getName() == name )
            return cur->graphNode();
        else if( cur->graphNode()->getName() > name )
            cur = cur->left();
        else
            cur = cur->right();
    }
    return nullptr;
}

void MakeTree::print(TreeNode *root)
{
    if(root == nullptr)
        return;
    print( root->left() );
    std::cout << root->graphNode()->getName() << std::endl;
    print ( root->right() );
}