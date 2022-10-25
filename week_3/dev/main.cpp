#include <iostream>
#include <cstddef>  // size_t
#include <cstring>  // strlen, strcpy
#include <algorithm>




struct String {

    /*  Конструктор */
    String(const char* s = "") {
        size = strlen(s);
        str = strcpy(new char[this->size + 1], s);
    }

    /*  Еще конструктор */
    String(size_t n, char c) {
        size = n;
        char* s = new char[n + 1];
        for (int i = 0; i < n; i++) {
            s[i] = c;
        }
        this->str = s;
    }

    /* Деструктор */
    ~String() {
        delete[] str;
    }

    /* Конструктор копирования */
    String(const String& other) {
        size = other.size;
        str = new char[other.size + 1];
        for (int i = 0; i != other.size; i++) {
            str[i] = other.str[i];
        }
    }

    /* Меняет местами текущий объект с объектом other */
    void swap(String& other) {
        std::swap(this->size, other.size);
        std::swap(this->str, other.str);
    }

    /* Оператор присваивания */
    String& operator=(const String& other) {
        if (this != &other) {
            String(other).swap(*this);
        }
        return *this;
    }

    /* Добавляет копию строки-аргумента в конец текущей строки */
    void append(String& other) {
        int n = this->size + other.size;
        char* temp = new char[n + 1];
        strcpy(temp, this->str);
        strcat(temp, other.str);
        temp[n] = '\0';
        delete[] this->str;
        this->str = &temp[0];
        this->size = strlen(this->str);
    }

    /* Вывод информации об объекте: содержимое строки и ее размер */
    void print_info() {
        std::cout << "String: ";
        for (int i = 0; i < this->size; i++) {
            std::cout << this->str[i];
        }
        std::cout << std::endl;
        std::cout << "Size: " << this->size << std::endl;
        std::cout << std::endl;
    }


    size_t size;
    char* str;
};






void test_constructor() {

    String s1("my string");  // конструктор 1
    s1.print_info();

    String s2(15, 'a');  // конструктор 2
    s2.print_info();

    s1 = String(s2);  // конструктор копирования
    s1.print_info();
}



void test_swap() {
    String s1("first string");
    s1.print_info();

    String s2("second string");
    s2.print_info();


    s1.swap(s2);  // меняем местами s1 и s2
    s1.print_info();
    s2.print_info();
}



void test_ravno() {
    String s1("first string");
    s1.print_info();

    String s2;
    s2.print_info();

    s2 = s1;  // присваиваем строке s2 строку s1
    s2.print_info();
}

void test_append() {
    String s1("Hello");
    s1.print_info();

    String s2("World");
    s2.print_info();

    s1.append(s2);  // к строке s1 добавляем строку s2
    s1.print_info();
}



int main() {
   

    //test_constructor();
    //test_swap();
    //test_ravno();
    test_append();




    return 0;
}


