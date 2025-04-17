#include <unordered_set>
#include <vector>
#include <cctype>
#include <utility>
#include <string>
#include "lexer.h"

std::string toString(Token token) {
    switch (token) {
        case Token::KEYWORD: return "KEYWORD";
        case Token::ID: return "ID";
        case Token::NUMBER: return "NUMBER";
        case Token::OPERATOR: return "OPERATOR";
        case Token::DELIMITER: return "DELIMITER";
        case Token::PUNCTUATION: return "PUNCTUATION";
        case Token::ASSIGN: return "ASSIGN";
        default: return "UNKNOWN";;
    }
}


std::unordered_set<std::string> keyword_set = { "break", "continue", "do", "else", "for", "if", "return", "while" };

void tokenize(std::string& s, std::vector<TokenInfo>& tokens, int row) {
    int col = 0;
    while(col < s.size()) {
        TokenInfo info;
        info.row = row+1;
        info.col = col+1;
        std::string text;
        char c = s[col++];
        text.push_back(c);
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
            case '<':
            case '>':
            case '^':
            case '~':
            case '&':
                info.token = Token::OPERATOR;
                info.text = text;
                tokens.push_back(info);
                break;
            case '(':
            case ')':
            case '{':
            case '}':
            case '[':
            case ']':
            case '"':
                info.set(Token::DELIMITER,text);
                tokens.push_back(info);
                break;
            case ';':
            case ',':
            case ':':
            case '.':
                info.set(Token::PUNCTUATION,text);
                tokens.push_back(info);
                break;
            default:
                if (std::isdigit(c)) {
                    while(col < s.size() && std::isdigit(s[col])) text.push_back(s[col++]);
                    if (col < s.size() && s[col] == '.') text.push_back(s[col++]);
                    while(col < s.size() && std::isdigit(s[col])) text.push_back(s[col++]);
                    info.set(Token::NUMBER, text);
                }
                else if (std::isalpha(c) || c == '_') {
                    while (col < s.size() && (std::isalnum(s[col]) || s[col] == '_')) text.push_back(s[col++]);
                    if (keyword_set.find(text) != keyword_set.end()) info.set(Token::KEYWORD,text);
                    else info.set(Token::ID,text);
                }
                else if (c == '=') info.set(Token::ASSIGN,text);
                else if (col < s.size() && ( (c == '=' && s[col] == '=') || (c == '|' && s[col] == '|') || (c == '&' && s[col] == '&') ) ) {
                    text.push_back(s[col++]);
                    info.set(Token::OPERATOR,text);
                } 
                else info.set(Token::UNKNOWN,text);
                tokens.push_back(info);
        }
    }
}
