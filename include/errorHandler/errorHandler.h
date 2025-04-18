#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <iostream>
#include <stdexcept>
#include <string>

class CompilerError : public std::exception {
public:
    explicit CompilerError(const std::string& message) : message_(message) {}
    virtual const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;
};

class SyntaxError : public CompilerError {
public:
    explicit SyntaxError(const std::string& message) : CompilerError("Syntax Error: " + message) {}
};

class SemanticError : public CompilerError {
public:
    explicit SemanticError(const std::string& message) : CompilerError("Semantic Error: " + message) {}
};

#endif

