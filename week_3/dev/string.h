#pragma once


struct String {

    /*  Конструктор */
    String(const char* s = "");

    /*  Еще конструктор */
    String(size_t n, char c);

    /* Деструктор */
    ~String();

    /* Конструктор копирования */
    String(const String& other);

    /* Меняет местами текущий объект с объектом other */
    void swap(String& other);

    /* Оператор присваивания */
    String& operator=(const String& other);

    /* Добавляет копию строки-аргумента в конец текущей строки */
    void append(String& other);

    /* Вывод информации об объекте: содержимое строки и ее размер */
    void print_info();


    size_t size;
    char* str;
};
