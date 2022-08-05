#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <vector>
#include <utility>

#include "Token.hpp"
#include "Tokenizer.hpp"
#include "InfixToPostfix.hpp"
#include "RomanNumber.hpp"
#include "symbolTable.hpp"

/*
    This main file converts a text file of Roman Expressions, converts those expressions into polish notation and calculates them. 
    Once calculated it prints the calculation and the variable associated to it
*/

//This Function calculates polish notation from Roman Numerals and Variables Assigned
std::pair <char, int> calcPostFix(std::vector<Token *> assignmentStatement, symbols variableToAddTo, const std::vector<Token *> PREassignmentStatement)
{
    std::stack<int> numbers;
    for(auto token: assignmentStatement)
    {
        //if the token is a Roman convert to decimal and push on stack
        if(token->isRomanNumber())
        {
            RomanNumber temp = RomanNumber();
            int number = temp.romanToDecimal(token->getRomanNumber());
            if(temp.isAValidRomanNumber(token->getRomanNumber()))
            {
                numbers.push(number);                
            }
            else
            {
                std::cout << "NOT VALID Roman Numeral" << std::endl;
            }

        }
        //if the token is a variable, get the value of variable in the class holding all the variables. 
        //Then push the value on stack.
        else if(token->isAVariable())
        {
            int number = variableToAddTo.getSymbolNumber(token->variable());
            numbers.push(number);
        }
        else
        {
            int second = numbers.top(); numbers.pop();
            int first = numbers.top(); numbers.pop();
            if(token->isAdditionOperator()){
                numbers.push(first + second);
            }
            else if(token->isSubtractionOperator())
            {
                numbers.push(first - second);
            }
            else if(token->isMultiplicationOperator())
            {
                numbers.push(first * second);
            }
            else if(token->isDivisionOperator())
            {
                numbers.push(first / second);
            }
            else if(token->isModuloOperator())
            {
                numbers.push(first % second);
            }
            else
            {
                std::cout <<"expected an arthmetic operator" << std::endl;
                token->print();
                exit(1);
            }
        }
    }
    std::pair <char, int> solution (PREassignmentStatement.at(0)->variable(), numbers.top());
    return solution;
    
}

    // The convert function expects an infix expression, not
    // an assignment statements. Therefore, we store the
    // tokens that represent the expression in "tokens"
    // and use it to convert the infix expression.
const std::vector<Token *> convertToPostFix(const std::vector<Token *> assignmentStatement) {
    InfixToPostfix *itop = new InfixToPostfix();
    std::vector<Token *> postfixTokens;
    std::vector<Token *> tokens;

    for( int i = 2; i < assignmentStatement.size(); i++ )
            tokens.push_back(assignmentStatement.at(i));
    itop->convert( tokens, postfixTokens );
    delete itop;
    return postfixTokens;
}



int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile\n";
        exit(1);
    }
    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if (!inputStream.is_open()) {
        std::cout << "Unable to open " << argv[1] << ". Terminating...";
        exit(1);
    }
    inputStream.close();
    
     Tokenizer tokenizer = Tokenizer(argv[1]);
     std::vector<Token *> assignmentStatement;
     Token *token = tokenizer.getToken();
    symbols variableToAddTo = symbols();

     // The assumption is that there is at least one new-line character
     // to terminate the last statement before end-of-file gets detected.
     RomanNumber converting = RomanNumber();
     while( ! token->eof() ) {
        assignmentStatement.push_back(token);
        if(token->eol()) 
        {
            std::pair <char, int> solution = calcPostFix(convertToPostFix(assignmentStatement), variableToAddTo, assignmentStatement);
            std::cout << solution.first << " equals " << converting.decimalToRoman(solution.second) << std::endl;
            variableToAddTo.addingSymbol(solution.first, solution.second);
            assignmentStatement.clear();
        }
        token = tokenizer.getToken();
    }
    
}
