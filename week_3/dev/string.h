#pragma once


struct String {

    /*  ����������� */
    String(const char* s = "");

    /*  ��� ����������� */
    String(size_t n, char c);

    /* ���������� */
    ~String();

    /* ����������� ����������� */
    String(const String& other);

    /* ������ ������� ������� ������ � �������� other */
    void swap(String& other);

    /* �������� ������������ */
    String& operator=(const String& other);

    /* ��������� ����� ������-��������� � ����� ������� ������ */
    void append(String& other);

    /* ����� ���������� �� �������: ���������� ������ � �� ������ */
    void print_info();


    size_t size;
    char* str;
};
