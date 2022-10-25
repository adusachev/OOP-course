#include "tests.h"
#include "string.h"
#include<iostream>



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
