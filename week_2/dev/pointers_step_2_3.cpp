#include <iostream>

using namespace std;


int max_element(int* m, int size) {
    int max = *m;  // m - ��������� �� ������ ��-� �������
    for (int i = 1; i < size; ++i)
        if (m[i] > max)
            max = m[i];
    return max;
}



int tests_2_3() {

    {
        int i = 3;
        int* p = 0;  // ��������� �� ���������� ���� int

        p = &i;  // ��������� p ��������� �� ���������� i
        *p = 10;  // ���������� ������ �� ������ p, �.�. i

        cout << i << endl;;
    }

    {
        int m[10] = { 111, 2, 3, 4, 5 };
        int* p = &m[0];  // ����� ������ �������
        int* q = &m[4];  // ����� ���������� ��������

        cout << *q << endl;
        cout << *p << endl;
        cout << *(p + 2) << " = " << m[2] << endl;
        cout << endl;

        int* t = m;  // ��������� �� ������ �������������� � ��������� �� ������ ��-� ������� (!!!)
        cout << *t << endl;
        cout << "max: " << max_element(m, 10) << endl;
    }



    return 0;
}