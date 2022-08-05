#include<iostream>
#include<fstream>
#include<vector>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"

void findFromHere(const std::vector<int> &values, int here, BinSearchTree *tree) {
    for(size_t i = here; i < values.size(); i++ )
        if( ! tree->find(values.at(i)) ) {
            std::cout << "Failed to find " << values.at(i) << std::endl;
            exit(1);
        }
}

int main( int argc, char *argv[] ) {

    std::cout << "Testing remove begins.\n";

    if( argc != 2 ) {
        std::cout << "usage: " << argv[0] << " nameOfInputFile\n";
        std::cout << "Testing find ends.\n";
        return 1;
    }

    BinSearchTree *tree = new BinSearchTree();

    std::fstream infile( argv[1] );
    if( ! infile.is_open() ) {
        std::cout << "Unable to open input-file: " << argv[1] << std::endl;
        std::cout << "Testing find ends (fails).\n";
        return 1;
    }

    std::vector<int> values;
    tree->remove(100);  // should be a no op
    
    int v;
    while( infile >> v ) {
        if( ! tree->find( v ) )  {
            tree->insert( v );
            values.push_back(v);
        }
    }

    infile.close();

    for(size_t i = 0; i < values.size(); i++)  {
//        std::cout << "Removing " << values.at(i) << std::endl;
        tree->remove(values.at(i));
        findFromHere(values, i+1, tree);
    }
    
    std::cout << "Testing remove ends.\n";

    return 0;			    
}
