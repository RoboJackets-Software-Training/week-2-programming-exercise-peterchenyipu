#include <string>
#include <vector>
#pragma once


class NumberConverter {
public:
    NumberConverter(std::vector<double> vector);

    NumberConverter(double d, double d1, double d2, double d3, double d4, double d5);

    int binaryToDecimal(std::string input);

    int hexToDecimal(std::string input);

    std::string decimalToHex(int input);

    std::string binaryToHex(std::string input);

    std::string decimalToBinary(int input);

    std::string hexToBinary(std::string input);

    double decimalInput;
    double decimalOutput;
    double hexInput;
    double hexOutput;
    double binInput;
    double binOutput;

    ~NumberConverter();


private:
    int hexCharToNumber(char input);

    char numberToHexChar(int input);
};