#include "TreeNode.hpp"
#include "BinSearchTree.hpp"
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector> 
#include <queue>
#include <vector>
#include <set>
#include <iterator>


TreeNode *BinSearchTree::local_insert( TreeNode *root, int v ) 
{
    if( root == nullptr )
        return new TreeNode( v );
    if( root->value() < v )
        root->rightSubtree( local_insert( root->rightSubtree(), v ) );
    else
        root->leftSubtree( local_insert( root->leftSubtree(), v ) );
    return root;
}

void BinSearchTree::insert(int v) 
{
    if( ! find( v ) )
        root = local_insert( root, v );
}

bool BinSearchTree::find( int v) 
{
    return recFind(root , v);

}

bool BinSearchTree::recFind(TreeNode *root, int v) 
{
    if(root == nullptr)
        return false;
    if(root->value() == v)
        return true;
    if(root->value() > v)
        return recFind( root->leftSubtree() , v);
    return recFind(root->rightSubtree() , v);
}

bool BinSearchTree::iterFind(int v) 
{
    TreeNode* cur = root;
    while( cur != nullptr){
        if( cur -> value() == v)
            return true;
        else if( cur -> value() > v )
            cur = cur -> leftSubtree();
        else
            cur = cur -> rightSubtree();
    }
    return false;
}

int BinSearchTree::size() 
{
    return recSize(root);
}

int BinSearchTree::recSize(TreeNode *root) 
{
    if(root == nullptr)
        return 0;
    return 1 + recSize(root->leftSubtree()) + recSize(root->rightSubtree());
}

void BinSearchTree::inorderDump() 
{
    recInorderDump(root);

}

void BinSearchTree::recInorderDump(TreeNode *root) 
{
    if(root == nullptr)
        return;
    recInorderDump(root->leftSubtree());
    std::cout << root->value() << std::endl;
    recInorderDump(root->rightSubtree());

}

int BinSearchTree::maxDepth() 
{
    return recMaxDepth(root);
}

int BinSearchTree::recMaxDepth(TreeNode *root) 
{
    if (root == nullptr)
        return 0;
    return std::max(recMaxDepth(root->leftSubtree()) , recMaxDepth(root->rightSubtree())) + 1;

    //This Code below is basically max, Why is it kept you may ask?
    //I really enjoy how I did it only to realize I could have used Max
    /*
    int leftMAXDepth = recMaxDepth(root->leftSubtree());
    int rightMAXDepth = recMaxDepth(root->rightSubtree());

    if (leftMAXDepth > rightMAXDepth)
        return leftMAXDepth + 1;
    else
        return rightMAXDepth + 1;
    */
}

void BinSearchTree::levelOrderDump() //prints the values in the tree, one per line, using a level-order traversal.
{
    local_levelOrderDump(root);

}

void BinSearchTree::local_levelOrderDump(TreeNode *root) 
{
    if(root == nullptr)
        return;
    std::queue<TreeNode*> levelQueue;
    levelQueue.push(root);
    while(!levelQueue.empty())
    {
        TreeNode *front = levelQueue.front();
        std::cout << front->value() << std::endl;
        levelQueue.pop();
        if(front->leftSubtree() != nullptr)
            levelQueue.push(front->leftSubtree());
        if(front->rightSubtree() != nullptr)
            levelQueue.push(front->rightSubtree());
    }

}


bool BinSearchTree::remove( int v )//removes the node containing the value v from the tree, if it exists. 
//It returns true if the value was in the tree and false otherwise.
{   
    if(!find(v)) //if it doesnt exist no need to remove, essentially it was already removed
    {
        return true;
    }
    if(!recFind(HELPERremove(root, v), v)) //if we can't find v in removed Node then it must've been removed
    {
        return true;
    }
    return false; //we didnt remove it and it exists still.
}


TreeNode *BinSearchTree::HELPERremove(TreeNode *root, int v)
{
    //3 Cases
    //Case one is if it is a leaf ie no children
    //Case Two is if it has two children
    //Case Three if it has one child
    
    //First we find where v is
    if(root == nullptr) //reached end
    {
        return root;
    }
    if(v > root->value()) //if v is greater we know it is the right descendant 
    {
        root->rightSubtree( HELPERremove(root->rightSubtree(), v) ); 
    }
    else if( v < root->value()) //if v is lesser we knew it in the left descendant
    {
        root->leftSubtree(HELPERremove(root->leftSubtree(), v));
    }
    else //WE found it!!!
    {
        if((root->leftSubtree() == nullptr) and (root->rightSubtree() == nullptr))
        {
            root = nullptr;
        }
        else if(root->leftSubtree() != nullptr) //finding predecessor
        {
            TreeNode *temp = root;
            temp = root->leftSubtree();
            while(temp->rightSubtree() != nullptr)
            {
                temp = temp->rightSubtree();
            }
            root->value() = temp->value();

            root->leftSubtree(HELPERremove(root->leftSubtree(), root->value()));
        }
        else //finding successor
        {
            TreeNode *temp = root;
            temp = root->rightSubtree();
            while(temp->leftSubtree() != nullptr)
            {
                temp = temp->leftSubtree();
            }
            root->value() = temp->value();

            root->rightSubtree(HELPERremove(root->rightSubtree(), root->value()));
        }
    }
    
    return root; //Return root without v!
}


int BinSearchTree::kthSmallest( int k )//returns the k-th smallest value in the tree.
{
    if(size() >= k)
    {
        int counter = 0, small = 0;
        HELPERkthSmallest(root, k, counter, small);
        return small;
       
    }
    return 0;

}

void BinSearchTree::HELPERkthSmallest(TreeNode *root, int k, int& counter, int& small)
{
    if(root->leftSubtree() != nullptr)
    {
        HELPERkthSmallest(root->leftSubtree(), k, counter, small);
    }
    counter++;
    if(counter == k)
    {
        small = root->value();
        return;
    }
    if(root->rightSubtree() != nullptr)
    {
        HELPERkthSmallest(root->rightSubtree(), k, counter, small);
    }
}

void BinSearchTree::valuesAtLevel( int k )//prints a list of values at level k in the tree, in increasing order of values. 
//The level of the root node is 1.
{
    HELPERvaluesAtLevel(root, k);
    return;
}
void BinSearchTree::HELPERvaluesAtLevel(TreeNode *root, int k)
{
    if(root == nullptr)
    {
        return;
    }
    if(k == 1)
    {
        std::cout<< root->value() << std::endl;
    }
    HELPERvaluesAtLevel(root->leftSubtree(), k-1);
    HELPERvaluesAtLevel(root->rightSubtree(), k-1);

}


void BinSearchTree::iterValuesAtLevel( int k ) //same as valuesAtLevel except this one is to be implemented iteratively.
{
    std::vector<std::vector<int>> levels = iterlevelOrderVector(root);
    std::vector<int> level = levels.at(k-1);
    for(auto i: level)
    {
        std::cout << i << std::endl;
    }
}
std::vector<std::vector<int>> BinSearchTree::iterlevelOrderVector(TreeNode *root) //This Friend Function Orginizes the BST into a vector of vector
//using a FCFS queue method like levelOrderDump.
{
    //[[300], [150, 350]]
    std::vector<std::vector<int>> finalVector;
    if(root  == nullptr)
    {
        return finalVector;
    }
    std::queue<TreeNode*> levelOrderQueue;
    levelOrderQueue.push(root);
    while(!levelOrderQueue.empty())
    {
        int k = levelOrderQueue.size();
        std::vector<int> temp;
        for(int i=0; i<k; i++)
        {
            TreeNode* front = levelOrderQueue.front();
            levelOrderQueue.pop();
            temp.push_back(front->value());
            if(front->leftSubtree())
            {
                levelOrderQueue.push(front->leftSubtree());
            }
            if(front->rightSubtree())
            {
                levelOrderQueue.push(front->rightSubtree());
            }
        }
        finalVector.push_back(temp);
    }
    return finalVector;
}



int BinSearchTree::iterMaxDepth() //same as maxDepth from part B, except this one is to be implemented iteratively.
{
    return HELPERiterMaxDepth(root);
}
int BinSearchTree::HELPERiterMaxDepth(TreeNode *root) //uses a FCFS queue to see the maxium depth
{
    if(root == nullptr)
    {
        return 0;
    }
    std::queue<TreeNode*> maxDepthQueue;
    maxDepthQueue.push(root);
    int maxDepth = 0;
    while(!maxDepthQueue.empty()) //Possible I miss a value
    {
        int counter = maxDepthQueue.size();
        while(counter--)
        {
            TreeNode* front = maxDepthQueue.front();
            maxDepthQueue.pop();
            if(front->leftSubtree() != nullptr)
            {
                maxDepthQueue.push(front->leftSubtree());
            }
            if(front->rightSubtree() != nullptr)
            {
                maxDepthQueue.push(front->rightSubtree());
            }
            
        }
        maxDepth++;
    }

    return maxDepth;
}



bool BinSearchTree::hasRootToLeafSum( int sum )//returns true if there is a root-to-leaf path in the tree where the 
//sum of the values on that path is equal to the input argument, sum. Otherwise, it returns false. 
{
    return HELPERhasRootToLeafSum(root, sum);
}

bool BinSearchTree::HELPERhasRootToLeafSum(TreeNode *root, int sum)
{
    if(root == nullptr)
    {
        return false;
    }
    sum = sum - root->value(); // could be part of bool below but for my simple brain to understand I put it here
    if(sum == 0 and root->leftSubtree() == nullptr and root->rightSubtree() == nullptr) //once the sum is zero and we hit a leaf node, we've stiken gold!
    {
        return true;
    }
    return HELPERhasRootToLeafSum(root->leftSubtree(), sum) or HELPERhasRootToLeafSum(root->rightSubtree(), sum); //otherwise we go through each child and once any
    //have become true it returns true.
}



bool BinSearchTree::areIdentical( BinSearchTree *bst ) //returns true if the tree in bst is structurally identical 
//to that of the tree maintained by the callee. Otherwise, it returns false.
{
    return HELPERareIdentical(root, bst->root);

}

bool BinSearchTree::HELPERareIdentical(TreeNode *first, TreeNode *second)
{
    if(first == nullptr and second == nullptr) //Nissan Leaf Node
    {
        return true;
    }
    if(first == nullptr or second == nullptr) //if either are false return false, cant be equal
    {
        return false;
    }
    if(first->value() != second->value())
    {
        return false;
    }

    return HELPERareIdentical(first->leftSubtree(), second->leftSubtree()) and HELPERareIdentical(first->rightSubtree(), second->rightSubtree());
}



BinSearchTree *BinSearchTree::intersectWith( BinSearchTree *bst ) //computes and returns, in an instance of BinSearchTrree, 
//the set intersection of the tree in bst and the callee
{
    std::vector<std::vector<int>> tree1 = RECUSIVElevelOrderVector(root); //recursive call to make bst into vector
    std::vector<std::vector<int>> tree2 = RECUSIVElevelOrderVector(bst->root);
    std::vector<int> tree1Unbranched;
    std::vector<int> tree2Unbranched;
    for(std::vector<int> level1 : tree1)
    {
        for(int values : level1)
        {
            tree1Unbranched.push_back(values); //condenss vector into single vector [400,300,450]
        }
    }
    for(std::vector<int> level2 : tree2)
    {
        for(int values2 : level2)
        {
            tree2Unbranched.push_back(values2); //do same for second tree
        }
    }
    std::vector<int> finalTree;
    std::sort(tree1Unbranched.begin(), tree1Unbranched.end()); //sort both trees to use in std::set_union
    std::sort(tree2Unbranched.begin(), tree2Unbranched.end());

    std::set_intersection(tree1Unbranched.begin(), tree1Unbranched.end(), tree2Unbranched.begin(), tree2Unbranched.end(), std::back_inserter(finalTree));
    //fucntion takes in tree1 and tree2 and outputs to final tree


    BinSearchTree *interTree = new BinSearchTree();

    interTree->root = convertVectorToBST(finalTree); //covert the final tree back into a root which is done recursivly 

    return interTree;

}


BinSearchTree *BinSearchTree::unionWith( BinSearchTree *bst )
{
    std::vector<std::vector<int>> tree1 = RECUSIVElevelOrderVector(root); //recursive call to make bst into vector
    std::vector<std::vector<int>> tree2 = RECUSIVElevelOrderVector(bst->root);
    std::vector<int> tree1Unbranched;
    std::vector<int> tree2Unbranched;
    for(std::vector<int> level1 : tree1)
    {
        for(int values : level1)
        {
            tree1Unbranched.push_back(values); //condenss vector into single vector [400,300,450]
        }
    }
    for(std::vector<int> level2 : tree2)
    {
        for(int values2 : level2)
        {
            tree2Unbranched.push_back(values2); //do same for second tree
        }
    }
    std::vector<int> finalTree;
    std::sort(tree1Unbranched.begin(), tree1Unbranched.end()); //sort both trees to use in std::set_union
    std::sort(tree2Unbranched.begin(), tree2Unbranched.end());

    std::set_union(tree1Unbranched.begin(), tree1Unbranched.end(), tree2Unbranched.begin(), tree2Unbranched.end(), std::back_inserter(finalTree));
    //fucntion takes in tree1 and tree2 and outputs to final tree


    BinSearchTree *unionTree = new BinSearchTree();

    unionTree->root = convertVectorToBST(finalTree); //covert the final tree back into a root which is done recursivly 

    return unionTree;
}
BinSearchTree *BinSearchTree::differenceOf( BinSearchTree *bst )//computes and returns, in an instance of BinSearchTrree, 
//the set difference of the tree in bst and that of the callee. 
//As you know, set difference is not a commutative operation. 
//So, what is returned is T(bst) - T(callee), where T(bst) and T(callee) refer to the trees of the bst and callee, respectively

//Written in the same fashion 
{
    std::vector<std::vector<int>> tree1 = RECUSIVElevelOrderVector(bst->root);
    std::vector<std::vector<int>> tree2 = RECUSIVElevelOrderVector(root);
    std::vector<int> tree1Unbranched;
    std::vector<int> tree2Unbranched;
    for(std::vector<int> level1 : tree1)
    {
        for(int values : level1)
        {
            tree1Unbranched.push_back(values);
        }
    }
    for(std::vector<int> level2 : tree2)
    {
        for(int values2 : level2)
        {
            tree2Unbranched.push_back(values2);
        }
    }
    std::vector<int> finalTree;
    std::sort(tree1Unbranched.begin(), tree1Unbranched.end());
    std::sort(tree2Unbranched.begin(), tree2Unbranched.end());
    
    std::set_difference(tree1Unbranched.begin(), tree1Unbranched.end(), tree2Unbranched.begin(), tree2Unbranched.end(), std::back_inserter(finalTree));


    BinSearchTree *diffTree = new BinSearchTree();

    diffTree->root = convertVectorToBST(finalTree);

    return diffTree;
}

    std::vector<std::vector<int>> BinSearchTree::RECUSIVElevelOrderVector(TreeNode* root) //same as iterlevelOrderVector but recursive
    {
        
        std::vector<std::vector<int>> levelOrderVector; 
        
        if(root == nullptr)
        {
            return levelOrderVector;
        }
        auto treeHeight = recMaxDepth(root);
          
        for (auto i=1; i <= treeHeight; i++)
        {
            std::vector<int> nodesAtLevel;
            HELPERrecLOV(root,i, nodesAtLevel);
            levelOrderVector.push_back(nodesAtLevel);
        }
        
        return levelOrderVector;
    }
    
    void BinSearchTree::HELPERrecLOV(TreeNode* root, int level, std::vector<int>& result)
    {
        if(root == nullptr)
        {
            return;
        }
        if(level == 1) 
        {
            result.push_back(root->value());
            return;
        }
        
            HELPERrecLOV(root->leftSubtree(), level-1, result);
            HELPERrecLOV(root->rightSubtree(), level-1, result);
                    
    }

    TreeNode *BinSearchTree::HELPERconvertVectorToBST(std::vector<int>& tree, int start, int end)//Used algo for AVL written in class
    {
        if(start == end) 
        {
            return nullptr;
        }
        int middle = (start+end)/2;
        TreeNode *root = new TreeNode(tree[middle]);
        root->leftSubtree(HELPERconvertVectorToBST(tree, start, middle));
        root->rightSubtree(HELPERconvertVectorToBST(tree, middle+1, end));
        return root;
    }
    
    TreeNode *BinSearchTree::convertVectorToBST(std::vector<int>& tree) 
    {
        return HELPERconvertVectorToBST(tree, 0, tree.size());
    }