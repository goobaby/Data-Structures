//
// Created by by Amit Deb on 10/18/21
//

#include "symbolTable.hpp"
#include "RomanNumber.hpp"
#include <iostream>


void symbols::addingSymbol(char variable, int number)
{
    symbolTable[variable] = number;

}


int symbols::getSymbolNumber(char variable) 
{
    return symbolTable[variable];
}