//
//Created by Amit Deb on 10/17/21
//
#include "RomanNumber.hpp"

#include <map>

RomanNumber::RomanNumber()
{
}

int RomanNumber::valueOfRoman(char romanChar)
{
    std::string singleRoman(1,romanChar);
    return romanDigitToDecimal[singleRoman];
}

int RomanNumber::romanToDecimal(std::string romanNumber)
{
    int summation = 0;
    for(int i = 0; i  < romanNumber.size(); i++)
    {
        if (i == romanNumber.size() - 1)
        {
            summation = summation + valueOfRoman(romanNumber[i]);
        }
        else{
            if(valueOfRoman(romanNumber[i]) >= valueOfRoman(romanNumber[i+1]))
            {
                summation = summation + valueOfRoman(romanNumber[i]);
            }
            else
            {
                summation = summation - valueOfRoman(romanNumber[i]);
            }
        }


    } 
    return summation;
}

std::string RomanNumber::decimalToRoman(int decimal)
{
    std::string summation = "";
    while(decimal != 0)
    {
        //Gets the subsequence of where decimal exist in map
        auto upperBound = decimalToRomanDigit.upper_bound(decimal);
        //Substract upperBound
        upperBound--;
        //add char (RomanString) to string
        summation = summation + (upperBound->second);
        //subtract decimal to grab next decimal
        decimal = decimal - (upperBound->first);
    }
    return summation;
}