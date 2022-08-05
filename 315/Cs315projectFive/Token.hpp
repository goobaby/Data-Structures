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
    Token(const std::string &s) {
        init();
        _fileName = s;
    }



    std::string fileName() const     { return _fileName; }
    void fileName(const std::string &str ) { _fileName = str; }
    void command(const std::string &com ) { _command = com; }

    bool &eof()  { return _eof; }
    void eof(bool change) {_eof = change;}

    bool &eol()  { return _eol; }
    void eol(bool change) {_eol = change;}

    bool isTarget() { return _isTarget; }
    void isTarget(bool change)  { _isTarget = change;}

    bool eoc()  { return _eoc; }
    void eoc(bool change) {_eoc = change;}

    bool noDep()  { return _noDependancies; }
    void noDep(bool change) {_noDependancies = change;}

    bool isFileName() const;

    void print();

    std::string getFileName() {return _fileName;}
    std::string getCommand() {return _command;}

private:
    void init();

    std::string _fileName, _command;
    bool _eof, _eol, _isTarget, _eoc, _noDependancies;

};

#endif //ROMANCALCULATORSTARTER_TOKEN_HPP
