#pragma once

#include <iostream>
#include <string>

namespace PlayerInput {
    struct EndOfInput {};

    inline std::string readLine(std::istream& input = std::cin) {
        std::string line;

        if (!std::getline(input, line)) {
            throw EndOfInput{};
        }

        const auto first = line.find_first_not_of(" \t\r\n\f\v");

        if (first == std::string::npos) {
            return {};
        }

        const auto last = line.find_last_not_of(" \t\r\n\f\v");
        return line.substr(first, last - first + 1);
    }
}