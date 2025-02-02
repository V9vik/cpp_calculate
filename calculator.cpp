#include <iostream>
#include <optional>
#include <string>
#include <cmath>
#include <limits>  
#include "calculator.h"

using Number = double;

bool ReadNumber(Number& result) {
    std::cin >> result;
    if (std::cin.fail()) {
        std::cerr << "Error: Numeric operand expected\n";
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {
    Number current = 0.0;
    std::optional<Number> memory;

    if (!ReadNumber(current)) {
        return false;
    }

    std::string command;
    while (std::cin >> command) {
        if (command == "+") {
            Number operand = 0.0;
            if (!ReadNumber(operand)) return false;
            current += operand;
        } else if (command == "-") {
            Number operand = 0.0;
            if (!ReadNumber(operand)) return false;
            current -= operand;
        } else if (command == "*") {
            Number operand = 0.0;
            if (!ReadNumber(operand)) return false;
            current *= operand;
        } else if (command == "/") {
            Number operand = 0.0;
            if (!ReadNumber(operand)) return false;
            current = operand != 0 ? current / operand : INFINITY;
        } else if (command == "**") {
            Number exponent = 0.0;
            if (!ReadNumber(exponent)) return false;
            current = std::pow(current, exponent);
        } else if (command == "=") {
            std::cout << current << std::endl;
        } else if (command == ":") {
            if (!ReadNumber(current)) return false;
        } else if (command == "c") {
            current = 0.0;
        } else if (command == "s") {
            memory = current;
        } else if (command == "l") {
            if (memory.has_value()) {
                current = memory.value();
            } else {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
        } else if (command == "q") {
            return true;
        } else {
            std::cerr << "Error: Unknown token " << command << std::endl;
            return false;
        }
    }