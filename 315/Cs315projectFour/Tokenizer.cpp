//
// Created by Ali A. Kooshesh on 10/11/21.
// Edited by Amit Deb on 10/12/21
//

#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string nameOfInputFileToTokenize): nameOfInputFile{(nameOfInputFileToTokenize)}
{
    //std::ifstream file(nameOfInputFileToTokenize);
    inputStream.open(nameOfInputFile, std::ios::in);

}

Token *Tokenizer::getToken() 
{
    // This function, when called, reads and returns the next input token.
    if (!inputStream.is_open()) 
    {
        std::cout << "Unable to open " << nameOfInputFile << ". Terminating...";
        exit(1);
    }
    //If True Nothing is left in file we just make everything into
    if(inputStream.peek() == EOF)
    {
        Token *EOFtoken = new Token;
        EOFtoken->eof(true); 
        EOFtoken->eol(true);
        delete EOFtoken;
        return EOFtoken;
    }
    char c;
    while(inputStream.get(c) and c != '\n' and isspace(c)) {}
    Token *token = new Token(c);
    //Might be unnessary since we already check EOF above but written here just incase
    if(inputStream.eof())
    {
        token->eof(true);
        return token;
    }
    //Proceed to next line
    else if( c == '\n')
    {
        token->eol(true);
        return token;
    }
    //We find one Roman Nurmal we continually look at the next value if it is a roman we add it to a empty string.
    else if (isRoman(c))
    {   
        std::string romanNumeral = "";
        romanNumeral = romanNumeral + c;
        while (inputStream.get(c) and isRoman(c))
        {
            romanNumeral = romanNumeral + c;
        }
        inputStream.unget();
        token->romanNumber(romanNumeral);
        return token;
    }
    else if(isOperator(c))
    {
        token->otherSign(c);
        return token;
    }
    else if(isVariable(c))
    {
        token->otherSign(c);
        return token;
    }
    std::cout << "Recieved something thats not a lower-case variable, valid operator, or a roman digit: " << c  << " ...Exiting..."<<std::endl;
    exit(3); //Exits
    return nullptr; //Should never reach here because its never not a var, operator, or roman.

}
bool Tokenizer::isRoman(char x)
{
    if(x == 'I' or x == 'V' or x == 'X' or x == 'L' or x == 'C' or x == 'D' or x == 'M')
    {
        return true;
    }
    return false;
}

bool Tokenizer::isOperator(char x)
{
    if (x == '=' or x == '+' or x == '-' or x == '*' or x == '%' or x == '/' or x == '(' or x == ')')
    {
        return true;
    }
    return false;
}

bool Tokenizer::isVariable(char x)
{
    if(x >= 'a' and x <= 'z')
    {
        return true;
    }
    return false;
}