#include<iostream>
#include<string>

#include "systemInterface.hpp"

int main( int argc, char **argv ) {

    //1. c string string std::string

    long numSecondsSinceJan1st1970;

    if( argc != 2 ) {
        std::cerr << argv[0] << ":: usage: " << argv[0] << " aFileName\n";
        return 1;
    }
    if( ! timestamp( argv[1], & numSecondsSinceJan1st1970 ) ) {
        std::cerr << "Couldn't stat " << argv[1] << "!\n";
        return 1;
    }
    if( numSecondsSinceJan1st1970 == -1 ) {
        std::cerr << "File " << argv[1] << " does not exist!\n";
        return 1;
    }
    std::cout << "Timestamp of " << argv[1] << " is: " << numSecondsSinceJan1st1970
              << std::endl;

    // test executeCommand function.
    const std::string command = "g++ -c systemInterface.cpp -o systemInterface.o";
    std::cout << "Output of executeCommand follows:\n";
    executeCommand(command.c_str());
    return 0;
}
