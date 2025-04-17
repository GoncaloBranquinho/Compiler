#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <unordered_set>
#include <vector>
#include <utility>

enum class Token {
    KEYWORD,    
    ID,
    NUMBER,
    OPERATOR,
    DELIMITER,
    PUNCTUATION,
    ASSIGN,
    UNKNOWN
};

struct TokenInfo {
    Token token;
    std::string text;
    int row;
    int col;
    void set(Token newToken, std::string newText) {token = newToken; text = newText;} 
};

std::string toString(Token token);

void tokenize(std::string& s, std::vector<TokenInfo>& tokens, int row);

#endif


