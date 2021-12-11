#include <iostream>

#include "utils.hpp"

std::vector<std::string> split (std::string data, std::string delimiter) {
    std::string token;
    std::vector<std::string> result;
    size_t posStart = 0, posEnd;
    size_t delimterLength = delimiter.length();

    while ((posEnd = data.find(delimiter, posStart)) != std::string::npos) {
        token = data.substr(posStart, posEnd - posStart);
        posStart = posEnd + delimterLength;
        result.push_back(token);
    }

    result.push_back(data.substr(posStart));
    return result;
}