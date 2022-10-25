#include <iostream>
#include <cstddef>  // size_t
#include <cstring>  // strlen, strcpy
#include <algorithm>

#include "string.h"



String::String(const char* s) {
    size = strlen(s);
    str = strcpy(new char[this->size + 1], s); 
}

String::String(size_t n, char c) {
        size = n;
        char* s = new char[n + 1];
        for (int i = 0; i < n; i++) {
            s[i] = c;
        }
        this->str = s;
}

String::~String() {
        delete[] str;
}

String::String(const String& other) {
        size = other.size;
        str = new char[other.size + 1];
        for (int i = 0; i != other.size; i++) {
            str[i] = other.str[i];
        }
}

void String::swap(String& other) {
    std::swap(this->size, other.size);
    std::swap(this->str, other.str);
}

String& String::operator=(const String& other) {
    if (this != &other) {
        String(other).swap(*this);
    }
    return *this;
}

void String::append(String& other) {
    int n = this->size + other.size;
    char* temp = new char[n + 1];
    strcpy(temp, this->str);
    strcat(temp, other.str);
    temp[n] = '\0';
    delete[] this->str;
    this->str = &temp[0];
    this->size = strlen(this->str);
}

void String::print_info() {
    std::cout << "String: ";
    for (int i = 0; i < this->size; i++) {
        std::cout << this->str[i];
    }
    std::cout << std::endl;
    std::cout << "Size: " << this->size << std::endl;
    std::cout << std::endl;
}
