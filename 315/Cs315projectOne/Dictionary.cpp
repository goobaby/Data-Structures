//
// Created by Ali A. Kooshesh on 2020-01-19.
//

#include <iostream>
#include <fstream>
#include "Dictionary.hpp"
#include<string>

Dictionary::Dictionary(std::string inputFileName) {
    // open inputFileName and store its contents, which is a collection of
    // words, one per line, in vector, "words".
    std::cout << "Creating an instance of Dictionary with input file: " << inputFileName << std::endl;

    //std::ifstream dictionaryStream;
    dictionaryStream.open(inputFileName, std::ios_base::in);
    std::string ward;
    while(dictionaryStream >> ward)
    {
        words.push_back(ward);
        used.push_back(false);
    }
}

Dictionary::~Dictionary() {
    // close the input stream if it was successfully opened.
    if(dictionaryStream.is_open())
        dictionaryStream.close();
}

int Dictionary::positionalDiff(std::string word1, std::string word2)
{
    int diffCounter = 0;
    int sizeWord = word1.size();
    for(int i = 0; i < sizeWord; i++)
    {
        if(word1.at(i) != word2.at(i))
            diffCounter++;
    }
    return diffCounter;
}

int Dictionary::idxOfSuccessorWordFrom(std::string word, int fromIdx)
{
    return HELPERidxOfSuccessorWordFrom(word, fromIdx, 69420);
}

int Dictionary::HELPERidxOfSuccessorWordFrom(std::string word, int fromIdx, int bestBor)
{
    if(fromIdx == words.size())
        return fromIdx;

    if(bestBor > positionalDiff(words.at(fromIdx), word))
        bestBor = positionalDiff(words.at(fromIdx), word);
    
    if(bestBor == 1)
        return fromIdx;

    fromIdx++;

    return HELPERidxOfSuccessorWordFrom(word, fromIdx, bestBor);
}

std::vector<std::string> Dictionary::neighborsOf(std::string input)
{
    std::vector<std::string> goodNeigh;
    for (int i = 0; i < words.size(); i++)
    {
        if(positionalDiff(input, words.at(i)) == 1)
        {
            goodNeigh.push_back(words.at(i));
        }
    }
    return goodNeigh;
}

void Dictionary::printDictionary()
{
    for(int i = 0; i < size(); i++)
    {
        std::cout << words.at(i) << std::endl;
    }
    return;
}

void Dictionary::printLadder()
{
    for(int i = 0; i < ladder.size(); i++)
    {
        //std::cout << std::get<0>(i) << std::endl;
    }
    return;
}

void Dictionary::resetPath()
{
    for(int i = 0; i < used.size(); i++)
    {
        used.at(i) = false;
    }
}

int Dictionary::size()
{
    return(words.size());
}

int Dictionary::member(std::string word)
{
    for(int i = 0; i < size(); i++)
    {
        if(words.at(i) == word)
        {
            return(i);
        }
    }
    return(-1);
}

std::vector<std::string> Dictionary::pathFromTo(std::string from, std::string to)
{ 
    std::vector<std::string> garbage;
    garbage.push_back(from);
    return HELPERpathFromTo(from, to, garbage);
}
std::vector<std::string> Dictionary::HELPERpathFromTo(std::string from, std::string to, std::vector<std::string> garbage)
{
    if (from == to)
    {
        //std::cout << "finished" << std::endl;
        return garbage;
    }else{
        //std::cout << from << ", " << to << " not finished" << std::endl;
    }

    std::vector<std::string> level;
    level = neighborsOf(from);
    for(int i = 0; i < level.size(); i++)
    {
        if(member(level.at(i)) == -1)
        {
            std::cout << level.at(i) << "asdas" << std::endl;
        }
        if(used.at(member(level.at(i))) == false)
        {
            std::vector<std::string> newGarbage(garbage);
            newGarbage.push_back(level.at(i));
            used.at(member(level.at(i))) = true;
            std::vector<std::string> results = HELPERpathFromTo(level.at(i), to, newGarbage);
            if(results.back() == to){
                //std::cout << "hellyeah\n";
                return results;
            }else{
                //std::cout << "recieved results:";
                for(auto result : results){
                    //std::cout << result << ",";
                }
                //std::cout << std::endl;
            }
        }
    }
    //used.at(member(level.at(i))) = false;
    return garbage;
}
    /*
    if(used.size() == 0)
    {
        std::cout << "No ladder for the pair " << from << "and " << to << "exists";
        std::vector<std::string> none;
        return none;
    }
    for(int i = 0; i < size(); )
    {
        idxOfSuccessorWordFrom(words.at(i), i)
    }
    std::cout << "A ladder for the pair " << from << "and " << to << "is: ";
    printLadder();
    resetPath();
    ====
    std::vector<std::string> garbage;

    for(int i = 0; i < words.size(); i++)
    {
        if(from == words.at(i))
        {
            ladder.push(std::make_tuple(from, i));
            used.at(i) = true;
        }
    }
    for(int j = 0; j < words.size(); j++)
    {
        int succ = idxOfSuccessorWordFrom(from, j);
        if(succ == size())
        {
            ladder.pop();
        }
        if(words.at(succ) == to)
        {
            ladder.push(std::make_tuple(to, succ));
            std::cout << "A ladder for the pair " << from << "and " << to << "is: ";
            printLadder();
            resetPath();
            return garbage;
        }
        if(used.at(succ) == false)
        {
            ladder.push(std::make_tuple(words.at(succ), succ));
            used.at(succ) = true;
        }
    }
    std::cout << "No ladder for the pair " << from << "and " << to << "exists";
    return garbage;
    */