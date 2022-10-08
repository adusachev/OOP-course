#include <iostream>


void task3() {


	int n;
	std::cin >> n;

	int k = 0;
	while (k < n) {
		int a, b;
		std::cin >> a >> b;

		std::cout << a + b << std::endl;

		k++;
	}
}