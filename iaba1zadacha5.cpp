#include <iostream>
int main() {
	int n;
	std::cout << "enter n";
	std::cin >> n;
	int f0 = 0;
	int f1 = 1;
	std::cout << "Fibonacci number";
	for (int i = 0; i < n; i++) {
		std::cout << f0 << " ";
		int next = f0 + f1;
		f0 = f1;
		f1 = next;
	}
	std::cout << std::endl;
	return 0;
}