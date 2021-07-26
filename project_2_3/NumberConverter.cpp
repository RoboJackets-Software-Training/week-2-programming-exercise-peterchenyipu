#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "NumberConverter.h"


/**
 * returns a number 0-15 based off of a hex char
 * This uses ascii to figure out number it corresponds to
 * @param input
 * @return
 */
int NumberConverter::hexCharToNumber(char input) {
  // this means it is [A,B,C,D,E,F]
  if(input > 57) {
    return input - (65 - 10);
  } else {
    // this is a digit in ascii
    return input - 48;
  }
}

/**
 * returns the character that is the given hex number
 * only valid on 0-15
 * @param input
 * @return
 */
char NumberConverter::numberToHexChar(int input) {
  if(input < 10) {
    // it is a digit
    return input + 48;
  } else {
    return (input - 10) + 65;
  }
}

int NumberConverter::binaryToDecimal(std::string input) {
    int result = 0;
    int multiplier = 1;
    for (int i = input.length() - 1; i >= 0; i--) {
        result += multiplier * (int)(input[i] - '0');
        multiplier *= 2;
    }
    return result;
}

int NumberConverter::hexToDecimal(std::string input) {
    int result = 0;
    int multiplier = 1;
    for (int i = input.length() - 1; i >= 0; i--) {
        result += multiplier * hexCharToNumber(input[i]);
        multiplier *= 16;
    }
    return result;
}

std::string NumberConverter::decimalToHex(int input) {
    std::string result = "";
    do {
        result = numberToHexChar(input % 16) + result;
        input = input / 16;
    } while(input != 0);
    return result;
}

std::string NumberConverter::binaryToHex(std::string input) {
    std::string result = "";
    while(input.size() > 4){
        std::string toProcess = input.substr(input.size() - 4 ,4);

        int digitsum = 0;
        int multiplier = 1;
        for (int i = toProcess.size() - 1; i >= 0; i--) {
            digitsum = digitsum + multiplier * (toProcess[i] - '0');
            multiplier *= 2;
        }
        result = numberToHexChar(digitsum) + result;

        input = input.substr(0, input.size() - 4);
    }

    std::string toProcess = input.substr(1,input.size()-1);
    int digitsum = 0;
    int multiplier = 1;
    for (int i = toProcess.size() - 1; i >= 0; i--) {
        digitsum = digitsum + multiplier * (toProcess[i] - '0');
        multiplier *= 2;
    }
    result = numberToHexChar(digitsum) + result;
    return result;




}

std::string NumberConverter::decimalToBinary(int input) {
    std::string result = "";
    do {
        result = (char) ((input % 2) + '0') + result;
        input = input / 2;
    } while(input != 0);
    return result;
}

std::string NumberConverter::hexToBinary(std::string input) {
    int num = hexToDecimal(input);
    std::string result = decimalToBinary(num);
    int remainder = result.length() % 4;
    for (int i = remainder; i < 4; i++) {
        result = "0" + result;
    }
    return result;

}

NumberConverter::NumberConverter(std::vector<double> vector) {
    this->decimalInput = vector[0];
    this->binInput = vector[1];
    this->hexInput = vector[2];
    this->decimalOutput = vector[3];
    this->binOutput = vector[4];
    this->hexOutput = vector[5];
}

NumberConverter::~NumberConverter() {
    std::cout << "decimal_inputs: " << decimalInput << std::endl;
    std::cout << "binary_inputs: " << binInput << std::endl;
    std::cout << "hex_inputs: " << hexInput << std::endl;
    std::cout << "decimal_outputs: " << decimalOutput << std::endl;
    std::cout << "binary_outputs: " << binOutput << std::endl;
    std::cout << "hex_outputs: " << hexOutput << std::endl;
}

NumberConverter::NumberConverter(double d, double d1, double d2, double d3, double d4, double d5) {
    this->decimalInput = d;
    this->binInput = d1;
    this->hexInput = d2;
    this->decimalOutput = d3;
    this->binOutput = d4;
    this->hexOutput = d5;
}
