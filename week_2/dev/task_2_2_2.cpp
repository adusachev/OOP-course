
#include <iostream>


void reverse_input() {
    int a = 1;

    std::cin >> a;

    if (a == 0) {
        return;
    }

    reverse_input();

    std::cout << a << " ";
    return;
}
