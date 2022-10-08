#include <iostream>


void str_input() {
    std::string a;

    char c = '\0';

    while (std::cin.get(c)) {
        if (c == '\n') {
            break;
        }

        std::cin >> a;
        std::cout << a << " ";
    }
}












