#pragma once
#include <exception>
#include <string>

// Пользовательский класс для исключений
class CustomException : public std::exception {

private:
    std::string message;

public:
    CustomException(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }

};