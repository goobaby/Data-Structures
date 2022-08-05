//
// Created by Ali A. Kooshesh on 2020-01-20.
//

#include<string>
#include<iostream>
#include<fstream>
#include"Dictionary.hpp"

std::vector<std::tuple<std::string, std::string>> readStartTargetWords(const std::string &inputFileName) {
    std::ifstream ladderStream;
    ladderStream.open(inputFileName, std::ios_base::in);
    if( ! ladderStream.is_open()) {
        std::cout << "Unable to open the input file ->" << inputFileName << "<- that contains pairs of words.\n";
        exit(2);
    }
    std::cout << "Successfully opened " << inputFileName << std::endl;
    std::vector<std::tuple<std::string, std::string>> startTargetVector;

    // while there are input lines, do:
    //     read the pair of words into variables, word1, word2
    //     startTargetVector.push_back(make_tuple(word1, word2));
    // end-while
    std::string firstWord, secondWord;
    while(ladderStream >> firstWord && ladderStream >> secondWord);
    {
        startTargetVector.push_back(std::make_tuple(firstWord, secondWord));
    }

    // Just so you see how this works, let's add two arbitrary words.
    std::string bell = "bell", ball = "ball";
    startTargetVector.push_back(std::make_tuple(bell, ball));
    return startTargetVector;
}

int main(int argc, char *argv[]) { // the main function.
    if( argc != 3 ) {
        std::cout << "usage: " << argv[0] << " inputFileNameThatContainsDictionary inputFileNameThatContainsPairsOfWords\n";
        exit(1);
    }

    std::ifstream dictionaryStream;
    dictionaryStream.open(argv[1], std::ios_base::in);
    if( ! dictionaryStream.is_open()) {
        std::cout << "Unable to open input file ->" << argv[1] << "<-\n";
        exit(2);
    }
    std::cout << "Successfully opened " << argv[1] << std::endl;
    // we just wanted to make sure that the input file exists. So, close it
    // and let the instance of Dictionary open and use it.
    dictionaryStream.close();

    Dictionary dictionary(argv[1]);
    auto arrayOfPairsToBuildLadders = readStartTargetWords(argv[2]);
    /*
    for(const auto & [startWord, targetWord]: arrayOfPairsToBuildLadders) {

        auto path = dictionary.pathFromTo("startWord", "targetWord");
        if(path.empty())
        {
            std::cout << "NO ladder for the pair  " << startWord << "and " << targetWord << " exists." << std::endl;
            return 0;
        }
        std::cout << "A ladder for the pair  " << startWord << "and " << targetWord << " is:" << std::endl;
        for( auto path: path )
        {
        std::cout << path << std::endl;
        std::cout << std::endl;
        }
    }
    */
    /*
    auto neighbors = dictionary.neighborsOf("fate");
    for( auto neighbor: neighbors )
    {
        std::cout << neighbor << std::endl;
    }
    */
    //std::cout << "hey hey" << std::endl;
    auto path = dictionary.pathFromTo("fate", "lake");
    for( auto path: path )
    {
        std::cout << path << std::endl;
    }
    
    return 0; 
}
