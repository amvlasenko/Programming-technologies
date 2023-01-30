#include <iostream>
#include <cctype>
#include <set>
#include <fstream>

char *cRemoveSymbols(char *destination, const char *source) {
    int i = 0;
    while (*source) {
        if (!std::isalpha(*source)) {
            *(destination + i) = *source;
            ++i;
            ++source;
        } else {
            ++source;
        }
    }
    *(destination + i) = '\0';

    return destination;
}

std::string cppRemoveSymbols(const std::string &source) {
    std::string destination;
    for (int i = 0; i < source.size(); ++i) {
        if (!std::isalpha(source[i])) {
            destination += source[i];
        }
    }
    return destination;
}

int main() {
    std::ifstream fin;
    fin.open("input.txt");

    int i = 1;
    while (!fin.eof()) {
        size_t stringSize;
        std::string cppString = "";
        std::string newCppString = "";
        fin >> stringSize;
        fin >> std::ws;
        char *cString = new char[stringSize + 1];
        char *destString = new char[stringSize + 1];
        fin.getline(cString, stringSize + 1);
        cppString = std::string(cString);
        std::cout << "before c: " << cString << "\n";
        cRemoveSymbols(destString, cString);
        std::cout << "after c: " << destString << "\n";
        std::cout << "before cpp: " << cppString << "\n";
        newCppString = cppRemoveSymbols(cppString);
        std::cout << "after cpp: " << newCppString << "\n";
        std::cout << "------------------------------------------------\n";

        delete[] cString;
        delete[] destString;
        ++i;
    }
}
