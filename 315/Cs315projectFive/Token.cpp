//
// Created by Ali A. Kooshesh on 10/11/21.
// Edited by Amit Deb on 10/12/21
//

#include <iostream>
#include "Token.hpp"

void Token::print() {
    if( eol() ) std::cout << "EOL" ;
    else {
        std::cout << "Token::print -- Came across an unknown token. Terminating...\n";
        exit(1);
    }
}

void Token::init() {
    _fileName = "";
    _eof = _eol = _isTarget = _eoc = false;
}

bool Token::isFileName() const { return _fileName.length() > 0; }
