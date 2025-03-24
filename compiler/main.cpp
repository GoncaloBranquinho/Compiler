#include <iostream>
#include "tokenizer.h"
#include <fstream>
#include <vector>
#include <string>
#include <utility>

int main(int argc, char* argv[]) {
    std::vector<std::pair<std::string,Token>> tokens;
    if (argc != 2) {
        std::cout << "Error: You must pass the file name as an argument, and nothing else." << std::endl;
        std::cout << "Example: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error: Unable to open the file!" << std::endl;
        return 1;
    }

    std::string line;
    while(std::getline(file,line)) {
        tokenize(line,tokens);
    }
    std::cout << "{ ";
    bool first = true; 
    for (auto p : tokens) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << "<" << toString(p.second) << ", " << "'" << p.first << "'" << ">";
        first = false;
    }

    std::cout << " }" << std::endl;

    file.close();
    return 0;
}       
