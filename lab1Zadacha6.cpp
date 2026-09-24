#include <iostream>
int main() {

	int a = 0;
	int b = 0;
	int d = 0;
	std::cout << "enter beginning a: ";
	std::cin >> a;
	std::cout << "enter end b: ";
	std::cin >> b;
	std::cout << "enter progression difference d: ";
	std::cin >> d;
	if (d <= 0) {
		std::cout << "error , d>0";
	}
	int n = a;
	std::cout << "multiples of three: ";
		while(n <= b) {
		if (n % 3 == 0) {
			std::cout << n << " ";
		}
			n = n + d;
			std::cout << std::endl;

	}
	return 0;



}