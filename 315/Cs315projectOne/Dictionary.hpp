//
// Created by Ali A. Kooshesh on 2020-01-19.
//

#ifndef GENERALBACKBONEPROGRAMS_DICTIONARY_HPP
#define GENERALBACKBONEPROGRAMS_DICTIONARY_HPP

#include<iostream>
#include<fstream>
#include<vector>
#include<tuple>
#include<stack>
#include<string>

class Dictionary {
public:
    Dictionary(std::string inputFileName);
    int size();  // number of words in the dictionary
    std::vector<std::string> pathFromTo(std::string from, std::string to);
    std::vector<std::string> HELPERpathFromTo(std::string from, std::string to, std::vector<std::string> garbage);
    // member returns the index of "word" in "words"
    // if "word" is not a member of the dictionary, it
    // returns size(). See comments for idxOfSuccessorWordFrom
    // to learn how you would use the index that this function returns.
    int member(std::string word);
    ~Dictionary();
    std::vector<std::string> neighborsOf(std::string someWord);
    
private:
    std::vector<std::string> words;
    std::vector<bool> used;
    std::stack< std::tuple<std::string, int> > ladder;
    std::string startWord, targetWord;
    std::ifstream dictionaryStream;  // use it to open the input file.

    // positionalDiff calculates and returns the number of positions
    // where its two arguments differ. For example, it will return
    // 2 if bell and bowl were passed to it (e and o; l and w).
    int positionalDiff(std::string word1, std::string word2);

    // This function finds a successor word for "word" in
    // dictionary starting at index "fromIdx". If there is
    // no successor for "word" starting at "fromIdx", the
    // function returns size(), the number of words in the dictionary.
    // usage:
    // int idx = idxOfSuccessorWordFrom("bell", 5);
    // if( idx == size() ) {
    //     there was not a successor word for "bell" starting with
    //     words[5]
    // } else {
    //     words[idx] is a successor for "bell".
    // }
    int idxOfSuccessorWordFrom(std::string word, int fromIdx);

    int HELPERidxOfSuccessorWordFrom(std::string word, int fromIdx, int bestBor);

    void resetPath(); // this function sets all elements of array "used" to false.
    void printDictionary();
    void printLadder();
};


#endif //GENERALBACKBONEPROGRAMS_DICTIONARY_HPP
