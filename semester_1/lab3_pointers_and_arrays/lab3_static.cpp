

#include <iostream>
#include <random>
#include <cmath>

const int MAX_SIZE = 10;

int MassiveSize() {
	int n;
	std::cout << "enter Masive size (1 < n <= " << MAX_SIZE << "): ";
	std::cin >> n;
	if (n <= 1 || n > MAX_SIZE) {
		std::cout << "error (n should be between 2 and " << MAX_SIZE << ").\n";
		return -1;
	}
	return n;
}
void ManualFilling(long long* arr, int n) {
	std::cout << "enter cell size n.\n";
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
}
bool RandomFilling(long long* arr, int n) {
	long long a, b;
	std::cout << " enter beginning of the interval of random a: ";
	std::cin >> a;
	std::cout << "enter end of the interval of randomm b: ";
	std::cin >> b;
	if (a > b) {
		std::cout << "b should be > a\n";
		return false;
	}
	std::mt19937 gen(45218965);
	std::uniform_int_distribution<long long> dist(a, b);
	for (int i = 0; i < n; ++i) {
		arr[i] = dist(gen);
	}
	return true;
}
void PrintMassive(const long long* arr, int n) {
	std::cout << "massive: ";
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}
int FindIndex(const long long* arr, int n) {
	int Index = -1;
	long long bestdiff = 999999999999999999;
	for (int i = 0; i < n; ++i) {
		long long leftsum = 0;
		long long rightsum = 0;
		for (int t = 0; t < i; ++t) {
			leftsum += arr[t];
		}
		for (int t = i + 1; t < n; ++t) {
			rightsum += arr[t];
		}
		long long diff = std::abs(leftsum - rightsum);
		if (diff < bestdiff) {
			bestdiff = diff;
			Index = i;
		}
	}
	return Index;
}
int main() {
	int n = MassiveSize();
	if (n == -1) return 0;
	long long arr[MAX_SIZE];
	int choise;
	std::cout << " select filling method : 1- manual , other- random";
	std::cin >> choise;
	if (choise == 1) {
		ManualFilling(arr, n);
	}
	else {
		if (!RandomFilling(arr, n)) return 0;
	}
	PrintMassive(arr, n);
	int idx = FindIndex(arr, n);
	std::cout << "number of index: " << idx << "\n";
	return 0;
}
