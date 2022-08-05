//
// Created by Ali A. Kooshesh on 10/11/21.
//

#ifndef ROMANCALCULATORSTARTER_TOKENIZER_HPP
#define ROMANCALCULATORSTARTER_TOKENIZER_HPP

#include <string>
#include <iostream>

#include "Token.hpp"

class Tokenizer {
public:
    Tokenizer(std::string nameOfInputFileToTokenize);
    Token *getToken();

private:
    std::string nameOfInputFile;

};


#endif //ROMANCALCULATORSTARTER_TOKENIZER_HPP
