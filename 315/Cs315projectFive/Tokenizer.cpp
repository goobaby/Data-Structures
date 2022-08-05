//
// Created by Ali A. Kooshesh on 10/11/21.
// Edited by Amit Deb on 10/12/21
//

#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string nameOfMakeFileToTokenize): nameOfMakeFile{(nameOfMakeFileToTokenize)}
{
    //std::ifstream file(nameOfInputFileToTokenize);
    inputStream.open(nameOfMakeFile, std::ios::in);

}

Token *Tokenizer::getToken() 
{
    // This function, when called, reads and returns the next input token.
    if (!inputStream.is_open()) 
    {
        std::cout << "Unable to open " << nameOfMakeFile << ". Terminating...";
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
    while(inputStream.get(c) and c != '\t' and c != '\n' and c != ' ' and isspace(c)) {}

    Token *token = new Token();
    //Might be unnessary since we already check EOF above but written here just incase
    if(inputStream.eof())
    {
        token->eof(true);
        return token;
    }
    else if( c == ':')
    {
        //std::cout << "AHHHH" << std::endl;
        std::string string = "";
        string += c;
        token->fileName(string);
        if(inputStream.peek()== '\n')
        {
            //std::cout << c << " should be :" << std::endl;
            noDep = true;
        }
        return token;
    }
    else if( c=='\t' )
    {
        std::string string = "";
        string += c;
        token->fileName(string);
        gotTab = true;
        return token;
    }
    else if(noDep)
    {
        std::string string = "EOL";
        token->fileName(string);
        noDep = false;
        return token;
    }
    else if(gotTab)
    {
        std::string command = "";
        command = command + c;
        while(inputStream.get(c) and c != '\n')
        {
            command = command + c;
        }
        //std::cout<<command << std::endl; //TEST
        inputStream.unget();
        token->command(command);
        token->eoc(true);
        gotTab = false;
        return token;
    }
    if( gotEOL and gotTab == false and c == '\n' and inputStream.peek() != ':')
    {
        std::string newline = "EOL";
        //newline += c;
        token->eol(true);
        token->fileName(newline);
        gotEOL = false;
        return token;
    }
    else if (c != '\n' or c != '\t')//isalpha(c) or isOperator(c) or isdigit(c)
    {
  
        std::string fileName = "";
        if(c != ':' and !isspace(c))
            fileName = fileName + c;
        if(c == ' ')
        {
            //fileName = fileName + c;
            //token->fileName(fileName);
            //return token;
        }
        if(inputStream.peek() == '\n')
        {
            token->fileName(fileName);
            gotEOL = true;
            return token;
            //std::cout << "got z-------------------------------------------------------" << std::endl;
        }
        while(inputStream.get(c) and c != '\n')
        {  
            if(c=='\n') 
                std::cout << "Char:" << c << std::endl;
            if(c == ':')
            {
                inputStream.unget(); //Erase if colon not needed
                token->fileName(fileName);
                token->isTarget(true);
                return token;
            }
            if(isspace(c))
            {
                if(inputStream.peek() == '\n')
                {
                    //fileName = fileName + c;
                    token->fileName(fileName);
                    gotEOL = true;
                    return token;
                }
                //fileName = fileName + c;
                token->fileName(fileName);
                return token;
            }
            if(inputStream.peek() == '\n')
            {
                fileName = fileName + c;
                token->fileName(fileName);
                gotEOL = true;
                return token;
            } 
            fileName = fileName + c;
        }
        if(c == ' ')
        {
            //std::cout << "got space-------------------------------------------------------" << std::endl;
        }
        if( c == '\n')
        {
            // std::string newline = "EOL";
            //std::cout << fileName << "inner" << std::endl;
            // //newline += c;
            // token->eol(true);
            // token->fileName(newline);
            // return token;
        }
        if(!isspace(c))
        {
            std::cout << fileName << "ahhhh" << std::endl;
            inputStream.unget();
            token->fileName(fileName);
            return token;
        }
    }

    //Proceed to next line
    if( c == '\n')
    {
        //std::cout << "AHHHH" << std::endl;
        //std::string newline = "";
        //newline += c;
        //token->eol(true);
        //token->fileName(newline);
        return token;
    }
    std::cout << "SOMETHING WEIRD HAPPENED!!! " << int(c) << std::endl;
    exit(3); //Exits
    return nullptr; //Should never reach here because its never not a var, operator, or roman.

}
bool Tokenizer::isOperator(char x)
{
    if (x == '=' or x == '+' or x == '-' or x == '*' or x == '%' or x == '/' or x == '(' or x == ')')
    {
        return true;
    }
    return false;
}
