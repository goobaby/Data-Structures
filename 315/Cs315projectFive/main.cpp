#include<iostream>
#include<cstdlib>
#include <string>

#include "DepGraph.hpp"
#include "Tokenizer.hpp"

std::string convertToASCII(std::string letter) //DEBUG FUNCTION
{
    std::string ASCII = "";
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        ASCII += " ";
        ASCII += int(x);
        ASCII += ", ";
        //std::cout << int(x) << std::endl;
    }
    return ASCII;
}

int main(int argc, const char *argv[] ) 
{
    if( argc != 2 ) {
        std::cout << "usage: " << argv[0] << " name-of-a-makefile\n";
        exit(1);
    }
    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if (!inputStream.is_open()) {
        std::cout << "Unable to open " << argv[1] << ". Terminating...";
        exit(1);
    }
    inputStream.close();

    Graph *make = new Graph(argv[1]);
    make->parseDepGraph();

    //make->print();
    if( make->isCyclic() )  
    {
        std::cerr << "Input graph has cycles.\n";
        exit(1);
    }
    //std::cout << "Running....\n";
    make->runMake();
    return 0;
}
