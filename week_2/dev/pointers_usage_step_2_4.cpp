#include <iostream>

using namespace std;


//bool contains_classic(int* m, int size, int value) {
//    /// <summary>
//    /// Функция для поиска элемента в массиве
//    for (int i = 0; i != size; ++i) {
//        if (m[i] == value) {
//            return true;
//        }
//    }
//    return false;
//}


bool contains(int* p, int* q, int value) {
    /// <summary>
    /// Функция для поиска элемента в массиве через указатели
    /// 
    /// <param name="p"> указатель на первый эл - т массива
    /// <param name="q"> указатель на эл - т массива, следующий за последним
    /// <param name="value"> искомое значение
    for (; p != q; ++p) {
        if (*p == value) {
            return true;
        }
    }
    return false;
}




int* max_element_1(int* p, int* q) {
    /// <summary>
    /// Функция для поиска максимума в массиве через указатели
    /// 
    /// <param name="p"> указатель на первый эл - т массива
    /// <param name="q"> указатель на эл - т массива, следующий за последним
    /// <returns> указатель на максимальный эл-т
    int* pmax = p;
    for (; p != q; ++p) {
        if (*p > *pmax) {
            pmax = p;
        }
    }
    return pmax;
}



bool max_element_2(int* p, int* q, int* res) {
    /// <summary>
    ///
    /// <param name="p"> указатель на первый эл - т массива
    /// <param name="q"> указатель на эл - т массива, следующий за последним
    /// <param name="res"> максимальный элемент
    /// <returns> false, если массив пустой, true иначе
    if (p == q) {
        return false;
    }
    *res = *p;
    for (; p != q; ++p) {
        if (*p > *res) {
            *res = *p;
        }
    }
    return true;
}




bool max_element_3(int* p, int* q, int** res) {
    /// <summary>
    /// Комбинация max_element_1 и max_element_2
    /// Изет указатель на значение максимального элемента в массиве
    ///
    /// <param name="p"> указатель на первый эл - т массива
    /// <param name="q"> указатель на эл - т массива, следующий за последним
    /// <param name="res"> указатель на максимальный элемент
    /// <returns> false, если массив пустой, true иначе
    if (p == q) {
        return false;
    }
    *res = p;
    for (; p != q; ++p) {
        if (*p > **res) {
            *res = p;
        }
    }
    return true;
}






int tests_2_4() {

    {
        int m[10] = { 111, 2, 3, 4, 5 };
        int* p = m;
        int* q = &m[9];
        cout << contains(p, q, 1) << endl;;
        cout << endl;
    }

    {
        int m[10] = { 111, 2, 3, 4, 5, 666, 7, 8, 1, 2 };
        int* pmax = max_element_1(m, m + 10);
        cout << " Maximum = " << *pmax << endl;
        cout << endl;
    }

    {
        int m[10] = { 111, 2, 3, 4, 5, 666, 7, 8, 1, 2 };
        int max = 0;
        if (max_element_2(m, m + 10, &max)) {
            cout << " Maximum = " << max << endl;
        }
        cout << endl;
    }

    {
        int m[10] = { 111, 2, 3, 4, 5, 666, 7, 8, 1, 2 };
        int* pmax = 0;
        if (max_element_3(m, m + 10, &pmax)) {
            cout << " Maximum = " << *pmax << endl;
        }
    }



    return 0;
}













