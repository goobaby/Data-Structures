#include <iostream>
    #include "TreeNode.hpp"
    #include "BinSearchTree.hpp"

    int main( int argc, char *argv[] ) {
    // create a tree and then print the values of its nodes
    // from the smallest to the largest.
 
    BinSearchTree *tree = new BinSearchTree();
    BinSearchTree *tree2 = new BinSearchTree();
    int v;
    /*
    while( std::cin >> v ) {
        tree->insert( v );
    }
    */
    tree->insert(432);
    tree->insert(991);
    tree->insert(332);
    tree->insert(522);
    tree->insert(631);
    tree->insert(209);

    tree2->insert(432);
    tree2->insert(991);
    tree2->insert(332);
    tree2->insert(522);
    tree2->insert(631);
    tree2->insert(209);

    std::cout << "in order dump: \n";
    tree->inorderDump();
    std::cout << std::endl;

    bool a = tree->find(2);
    std::cout << "find: " << a << std::endl;

    bool b = tree->iterFind(9);
    std::cout << "iterFind: " << b << std::endl;

    int c = tree->size();
    std::cout << "size done recursively: " << c << std::endl;


    int e = tree->maxDepth();
    std::cout << "maxDepth: " << e << std::endl;

    return 0;
    while( std::cin >> v ) {
        tree->insert( v );
    }
       if( tree->iterFind(20))
        std::cout << "The item is in the tree!" << std::endl;
    else
        std::cout << "The item is not in the tree." << std::endl;
    std::cout << tree->maxDepth() << std::endl;
    tree->inorderDump();
    tree->levelOrderDump();
    if(tree->remove(400) == true)
    {
        std::cout<<"removed"<<std::endl;
    }
    std::cout<<tree->kthSmallest(3)<<std::endl;
    tree->valuesAtLevel(2);
    tree->iterValuesAtLevel(3);
    if(tree->hasRootToLeafSum(1209) == true)
    {
        std::cout<<"Sum!"<<std::endl;
    }
    std::cout<<tree->iterMaxDepth()<<std::endl;
    if(tree->areIdentical(tree2))
    {
        std::cout<<"Same!"<<std::endl;
    }
    

    return 0;
}