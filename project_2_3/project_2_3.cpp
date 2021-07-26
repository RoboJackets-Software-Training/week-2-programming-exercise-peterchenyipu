#include <iostream>
#include "NumberConverter.h"
#include <vector>

std::vector<double> readInVector(std::string s) {
    int prev_location = 0;
    int next_location = 0;
    std::vector<double> result;
    while (s.find(',', prev_location) != std::string::npos) {
        next_location = s.find(',', prev_location);
        //std::cout << "prev_location: " << prev_location << std::endl;
        //std::cout << "next_location: " << next_location << std::endl;
        // substr [,]
        //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
        result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
        next_location++;
        prev_location = next_location;
    }
    result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
    return result;
}

int main() {
    std::vector<double> params;
    std::string paramsS;
    std::cin >> paramsS;
    params = readInVector(paramsS);
    NumberConverter numConv(params);

    char convertType;
    std::cin >> convertType;

    std::string num;
    std::cin >> num;
    char inputType;
    if (num.substr(0, 2) == "0x") {
        num = num.substr(2);
        inputType = 'h';
        numConv.hexInput += 1;
    } else if (num[0] == 'b') {
        num = num.substr(1);
        inputType = 'b';
        numConv.binInput += 1;
    } else {
        inputType = 'd';
        numConv.decimalInput += 1;
    }

    std::cout << "input: " << num << std::endl;
    std::cout << "output type: " << convertType << std::endl;
    if (convertType == 'd') // to decimal
    {
        int result = 0;
        if (inputType == 'h') {
            result = numConv.hexToDecimal(num);
        } else if (inputType == 'b') {
            result = numConv.binaryToDecimal(num);
        }
        std::cout << "result: " << result <<std::endl;
        numConv.decimalOutput += 1;
    } else if (convertType == 'h') // to hex
    {
        std::string result = "";
        if (inputType == 'd') {
            int input = std::stoi(num);
            result = numConv.decimalToHex(input);
        } else if (inputType == 'b') {
            result = numConv.binaryToHex(num);
        }
        std::cout << "result: " << result <<std::endl;
        numConv.hexOutput += 1;
    } else if (convertType == 'b') // to binary
    {
        std::string result;
        if (inputType == 'd') {
            int input = std::stoi(num);
            result = numConv.decimalToBinary(input);
        } else if (inputType == 'h') {
            result = numConv.hexToBinary(num);
        }
        std::cout << "result: " << result <<std::endl;
        numConv.binOutput += 1;
    }

}
