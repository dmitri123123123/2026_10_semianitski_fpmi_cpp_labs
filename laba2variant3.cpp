#include <iostream>
int main() {
	std::cout << "Enter n: ";
	long long n;
	std::cin >> n;
	if (n <= 0) {
		std::cout << " ENTER ONLY POSITIVE n";
	}
	long long temp = n;
	long long min_digit = 9;
	long long powers_of_10 = 1;
	while (temp > 0) {
		long long current_digit = temp % 10;
		if (current_digit != 0 && current_digit < min_digit) {
			min_digit = current_digit;

		}
		powers_of_10 *= 10;
		temp /= 10;
	}
	n = n * 10 + min_digit;
	n = min_digit * powers_of_10 * 10 + n;
	std::cout << n << std::endl;

	return 0;

}