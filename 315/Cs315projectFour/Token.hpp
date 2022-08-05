//
// Created by Ali A. Kooshesh on 10/11/21.
// Edited by Amit Deb on 10/12/21
//

#ifndef ROMANCALCULATORSTARTER_TOKEN_HPP
#define ROMANCALCULATORSTARTER_TOKEN_HPP

#include <vector>
#include <string>

/*
    This class is a token and contains a roman number, a end of line and file variable, and 
*/


class Token {
public:
    Token() { init(); }
    Token(char c) { init(); _symbol = c; }
    Token(const std::string &s) {
        init();
        _romanNumber = s;
    }

    void otherSign(const char &chr) {_symbol = chr;}

    std::string romanNumber() const     { return _romanNumber; }
    void romanNumber(const std::string &str ) { _romanNumber = str; }

    bool &eof()  { return _eof; }
    void eof(bool change) {_eof = change;}
    bool &eol()  { return _eol; }
    void eol(bool change) {_eol = change;}

    bool isOpenParen() const  { return _symbol == '('; }
    bool isCloseParen() const { return _symbol == ')'; }

    bool isEqualSign() const              { return _symbol == '='; }
    bool isMultiplicationOperator() const { return _symbol == '*'; }
    bool isAdditionOperator() const       { return _symbol == '+'; }
    bool isSubtractionOperator() const    { return _symbol == '-'; }
    bool isModuloOperator() const         { return _symbol == '%'; }
    bool isDivisionOperator() const       { return _symbol == '/'; }
    bool isAVariable() const              { return _symbol >= 'a' && _symbol <= 'z'; }
    char &variable()                      { return _symbol; }

    bool isRomanNumber() const;

    void print();

    std::string getRomanNumber() {return _romanNumber;}

private:
    void init();

    std::string _romanNumber;
    bool _eof, _eol;
    char _symbol;
};

#endif //ROMANCALCULATORSTARTER_TOKEN_HPP
