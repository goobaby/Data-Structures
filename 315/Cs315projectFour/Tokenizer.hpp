//
// Created by Ali A. Kooshesh on 10/11/21.
// Edited by Amit Deb on 10/12/21
//

#ifndef ROMANCALCULATORSTARTER_TOKENIZER_HPP
#define ROMANCALCULATORSTARTER_TOKENIZER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Token.hpp"

/*
    This Class opens a file and contructs a token either being a roman, variable, or operator 
*/

class Tokenizer {
public:
    Tokenizer(std::string nameOfInputFileToTokenize);
    Token *getToken();

private:
    std::string nameOfInputFile;
    std::fstream inputStream;
    bool isRoman(char x);
    bool isOperator(char x);
    bool isVariable(char x);
};


#endif //ROMANCALCULATORSTARTER_TOKENIZER_HPP
