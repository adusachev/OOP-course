#include<iostream>


int power(int x, unsigned p) {

	int x_pow = 1;

	for (int i = 0; i < p; i++) {
		x_pow *= x;
	}

	return x_pow;
}



void tests_task1() {
	unsigned a = 0;
	unsigned b = 1;
	unsigned c = 2;
	unsigned d = 3;
	unsigned e = 4;

	int x = 3;

	std::cout << power(x, a) << std::endl;
	std::cout << power(x, b) << std::endl;
	std::cout << power(x, c) << std::endl;
	std::cout << power(x, d) << std::endl;
	std::cout << power(x, e) << std::endl;
}




















