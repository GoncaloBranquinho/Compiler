#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

enum class Token {
  KEYWORD,
  INCLUDE,
  ID,
  NUMBER,
  OPERATOR,
  DELIMITER,
  PUNCTUATION,
  LESS_THAN,
  GREATER_THAN,
  BOOLEAN,
  ASSIGN,
  NEGATION,
  PREPROCESSOR,
  UNKNOWN
};

std::string toString(Token token);

void tokenize(std::string &s,
              std::vector<std::pair<std::string, Token>> &tokens);

#endif
