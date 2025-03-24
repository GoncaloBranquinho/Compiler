#include <unordered_set>
#include <vector>
#include <cctype>
#include <utility>
#include <string>
#include "tokenizer.h"

std::string toString(Token token) {
    switch (token) {
        case Token::KEYWORD: return "KEYWORD";
        case Token::INCLUDE: return "INCLUDE";
        case Token::ID: return "ID";
        case Token::NUMBER: return "NUMBER";
        case Token::OPERATOR: return "OPERATOR";
        case Token::DELIMITER: return "DELIMITER";
        case Token::PUNCTUATION: return "PUNCTUATION";
        case Token::LESS_THAN: return "LESS_THAN";
        case Token::GREATER_THAN: return "GREATER_THAN";
        case Token::BOOLEAN: return "BOOLEAN";
        case Token::ASSIGN: return "ASSIGN";
        case Token::NEGATION: return "NEGATION";
        case Token::PREPROCESSOR: return "PREPROCESSOR";
        default: return "UNKNOWN";;
    }
}


std::unordered_set<std::string> keyword_set = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", 
        "double", "else", "enum", "extern", "float", "for", "goto", "if", 
        "inline", "int", "long", "restrict", "return", "short", 
        "signed", "sizeof", "static", "struct", "switch", "typedef", "union", 
        "unsigned", "void", "while"
};

void tokenize(std::string& s, std::vector<std::pair<std::string,Token>>& tokens) {
    int ptr = 0;
    while(ptr < s.size()) {
        std::string token;
        char c = s[ptr];
        token.push_back(c);
        ptr++;
        switch (c) {
            case ' ':
            case '\t':
            case '\n':
            case '\r':
            case '\v':
            case '\f':
                break;
            case '+':
            case '*':
            case '/':
            case '-':
            case '%':
                tokens.push_back({token,Token::OPERATOR});
                break;
            case '(':
            case ')':
            case '{':
            case '}':
            case '[':
            case ']':
            case '"':
                tokens.push_back({token,Token::DELIMITER});
                break;
            case '<': 
                tokens.push_back({token,Token::LESS_THAN});
                break; 
            case '>':
                tokens.push_back({token, Token::GREATER_THAN});
                break;
            case ';':
            case ',':
            case '.':
            case ':':
                tokens.push_back({token, Token::PUNCTUATION});
                break;
            case '#':
                tokens.push_back({token, Token::PREPROCESSOR});
                break;
            default:
                if (std::isdigit(c)) {
                    while(ptr < s.size() && std::isdigit(s[ptr])) token.push_back(s[ptr++]);
                    if (ptr < s.size() && s[ptr] == '.') token.push_back(s[ptr++]);
                    while(ptr < s.size() && std::isdigit(s[ptr])) token.push_back(s[ptr++]);
                    tokens.push_back({token, Token::NUMBER});
                    continue;
                }
                if (std::isalpha(c) || c == '_') {
                    while (ptr < s.size() && (std::isalnum(s[ptr]) || s[ptr] == '_')) token.push_back(s[ptr++]);
                    if (keyword_set.find(token) != keyword_set.end()) tokens.push_back({token,Token::KEYWORD});
                    else tokens.push_back({token, Token::ID});
                    continue;
                }
                if (c == '=') {
                    if (ptr < s.size() && s[ptr] == '=') {
                        token.push_back(s[ptr++]);
                        tokens.push_back({token,Token::BOOLEAN});
                    }
                    else tokens.push_back({token,Token::ASSIGN});
                    continue;
                }
                if (ptr < s.size() && ( (c == '|' && s[ptr] == '|') || (c == '&' && s[ptr] == '&') ) ) {
                    token.push_back(s[ptr++]);
                    tokens.push_back({token,Token::BOOLEAN});
                    continue;
                } 
                if (c == '!') tokens.push_back({token,Token::NEGATION});   
                else tokens.push_back({token,Token::UNKNOWN});
        }
    }
}
