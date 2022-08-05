//
// Created by by Amit Deb on 10/18/21
//

#include <iostream>
#include <map>
/*
    This class holds variables and its corresponding variable in a map.
    This class can give symbol number from map
*/
class symbols
{
    public:
    symbols(){}
    symbols(char variable, int number);

    void addingSymbol(char variable, int number);

    int getSymbolNumber(char variable);

    private:
    std::map<char, int> symbolTable;
};