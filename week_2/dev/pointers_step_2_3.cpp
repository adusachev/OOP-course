#include <iostream>

using namespace std;


int max_element(int* m, int size) {
    int max = *m;  // m - указатель на первый эл-т массива
    for (int i = 1; i < size; ++i)
        if (m[i] > max)
            max = m[i];
    return max;
}



int tests_2_3() {

    {
        int i = 3;
        int* p = 0;  // указатель на переменную типа int

        p = &i;  // указатель p указывает на переменную i
        *p = 10;  // изменяется ячейка по адресу p, т.е. i

        cout << i << endl;;
    }

    {
        int m[10] = { 111, 2, 3, 4, 5 };
        int* p = &m[0];  // адрес начала массива
        int* q = &m[4];  // адрес последнего элемента

        cout << *q << endl;
        cout << *p << endl;
        cout << *(p + 2) << " = " << m[2] << endl;
        cout << endl;

        int* t = m;  // указатель на массив предобразуется в указатель на первый эл-т массива (!!!)
        cout << *t << endl;
        cout << "max: " << max_element(m, 10) << endl;
    }



    return 0;
}