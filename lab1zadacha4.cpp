#include <iostream>
int main() {
	int number;
	std::cout << "enter a six-digit number";
	std::cin >> number;

	int n1 = number / 100000;
	int n2 = (number / 10000) % 10;
	int n3 = (number / 1000) % 10;
	int n4 = (number / 100) % 10;
	int n5 = (number / 10) % 10;
	int n6 = number % 10;
	int summa_first_three = n1 + n2 + n3;
	int summa_last_three = n4 + n5 + n6;
	if (summa_first_three == summa_last_three) {
		std::cout << "this is a lucky number" << std::endl;
	}
	else {
		std::cout << "this is a unlucky number" << std::endl;
	}
	return 0;
}