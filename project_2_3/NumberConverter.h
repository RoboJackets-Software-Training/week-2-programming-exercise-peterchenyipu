#include <string>
#pragma once


class NumberConverter {
    public:
        int binaryToDecimal(std::string input);
        int hexToDecimal(std::string input);
        std::string decimalToHex(int input);
        std::string binaryToHex(std::string input);
        std::string decimalToBinary(int input);
        std::string hexToBinary(std::string input);


    private:
        int hexCharToNumber(char input);
        char numberToHexChar(int input);
};