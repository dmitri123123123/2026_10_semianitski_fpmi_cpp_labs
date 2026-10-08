#include <iostream>
#include <random>
#include <cmath>
int MassiveSize() {
	int n;
		std::cout << "enter Masive size (n > 1)";
		std::cin >> n;
		if (n <= 1) {
			std::cout << "error (n should be >1.\n)";
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
			std::cout << "b should be > a";
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
	long long bestdiff = 922337203685477580;

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
	if (n <= 1) {
		return 1;
	}
	long long* arr = new long long[n];
	int choise;
	std::cout << " select filling method : 1- manual , another- random";
	std::cin >> choise;
	if (choise == 1) {
		ManualFilling(arr, n);
	}
	else {
		RandomFilling(arr, n);
	}
	PrintMassive(arr, n);
	int idx = FindIndex(arr, n);
	std::cout << "number of index: " << idx << "\n";
	delete[] arr;
	return 0;
}
