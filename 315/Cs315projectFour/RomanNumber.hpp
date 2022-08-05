//
//Created by Amit Deb on 10/17/21
//

#include<iostream>
#include<string>
#include<map>

class RomanNumber{
public:
    RomanNumber();
    int romanToDecimal(std::string romanNumber);
    std::string decimalToRoman(int decimal);
    bool isAValidRomanNumber(std::string romanNumber) {return romanNumber == decimalToRoman(romanToDecimal(romanNumber));}
private:
    int valueOfRoman(char romanChar);
    std::map<std::string, int> romanDigitToDecimal =
    {
        {"I", 1}, {"V", 5}, {"X",10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}
    };
    std::map<int, std::string> decimalToRomanDigit =
    {
        {1,"I"}, {4,"IV"}, {5,"V"},{9,"IX"}, {10,"X"}, {40,"XL"}, {50,"L"}, {90,"XC"}, {100,"C"}, {400,"CD"}, {500,"D"}, {900,"CM"}, {1000,"M"}
    };
};