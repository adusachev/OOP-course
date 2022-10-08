#include <iostream>

int logarithm_integer(int a) {

    int b = 1;  // приближение логарифма
    int p = 0;  // степень 2 приближенного логарифма

    while (b <= a) {
        b *= 2;
        p += 1;
    }
    if (b > a) {
        b /= 2;
        p -= 1;
    }
    //std::cout << p << std::endl;
    //std::cout << b;
    return p;
}




void input_task6() {

    int T;
    std::cin >> T;

    int t = 0;
    int a, p;

    while (t < T) {
        std::cin >> a;
        t++;
        p = logarithm_integer(a);
        std::cout << p << std::endl;
    }
}

