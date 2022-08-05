//
// Created by student on 9/21/21.
//

#ifndef BINARY_SEARCH_TREE_BINSEARCHTREE_HPP
#define BINARY_SEARCH_TREE_BINSEARCHTREE_HPP


#include<stdlib.h>
#include "TreeNode.hpp"
#include <vector>

class BinSearchTree {
public:
   void insert( int v );
   bool find( int v );
   bool iterFind( int v );
   int size();
   int recSize(TreeNode *root);
   void inorderDump();
   int maxDepth();
    int  recMaxDepth(TreeNode *root);

   void levelOrderDump();   //DONE
   void local_levelOrderDump(TreeNode *root);

   bool remove( int v ); //DONE TODO TEST IN LAB

    
   int kthSmallest( int k );//DONE TODO TEST IN LAB


   void valuesAtLevel( int k );
   void iterValuesAtLevel( int k );

   int iterMaxDepth(); //DONE
   bool hasRootToLeafSum( int sum );

   bool areIdentical( BinSearchTree *bst );
   BinSearchTree *intersectWith( BinSearchTree *bst );
   BinSearchTree *unionWith( BinSearchTree *bst );
   BinSearchTree *differenceOf( BinSearchTree *bst );

   std::vector<std::vector<int>> iterlevelOrderVector(TreeNode *root);
   std::vector<std::vector<int>> RECUSIVElevelOrderVector(TreeNode* root);
   
   TreeNode *convertVectorToBST(std::vector<int>& nums);


private:
   TreeNode *local_insert( TreeNode *, int );
   // Whatever private members you added for this part
   TreeNode *root;

   bool recFind(TreeNode *root, int v);
   void recInorderDump(TreeNode *root);
   TreeNode *HELPERremove(TreeNode *root, int v);
   void HELPERkthSmallest(TreeNode *root, int k, int& counter, int& small);
   int HELPERiterMaxDepth(TreeNode *root);
   bool HELPERhasRootToLeafSum(TreeNode *root, int sum);


   bool HELPERareIdentical(TreeNode *first, TreeNode *second);
   void HELPERvaluesAtLevel(TreeNode *root, int k);

   //BinSearchTree *HELPERintersectWith(TreeNode* first, TreeNode* second, BinSearchTree* final);
   void HELPERrecLOV(TreeNode* root, int level, std::vector<int>& result);

   TreeNode *HELPERconvertVectorToBST(std::vector<int>& nums, int start, int end);
};

#endif //BINARY_SEARCH_TREE_BINSEARCHTREE_HPP