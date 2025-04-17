#include <iostream>
#include "lexer.h"
#include <fstream>
#include <vector>
#include <string>
#include <utility>

int main(int argc, char* argv[]) {
    std::vector<TokenInfo> tokens;
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
    int row = 0;
    while(std::getline(file,line)) {
        tokenize(line,tokens,row++);
    }
    for (auto p : tokens) {
        std::cout << toString(p.token) << ": " << "'" << p.text << "'" << " Row: " << p.row << " Col: " << p.col << std::endl;
    }
    file.close();
    return 0;
}       
