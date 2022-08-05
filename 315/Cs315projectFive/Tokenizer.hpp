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
    This Class opens a file and contructs a token
*/

class Tokenizer {
public:
    Tokenizer(std::string nameOfMakeFileToTokenize);
    Token *getToken();

private:
    std::string nameOfMakeFile;
    std::fstream inputStream;
    bool isOperator(char x);
    bool gotTab = false;
    bool gotEOL = false;
    bool noDep = false;
    bool gotCommand;
};


#endif //ROMANCALCULATORSTARTER_TOKENIZER_HPP
