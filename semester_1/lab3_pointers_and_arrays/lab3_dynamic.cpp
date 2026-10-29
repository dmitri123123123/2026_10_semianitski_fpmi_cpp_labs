#include <iostream>
#include <random>
int MassiveSize() {
	int n;
		std::cout << "Введите размер массива (n > 1)";
		std::cin >> n;
		if (n <= 1) {
			std::cout << "ОШИБКА (n должно быть >1)\n";
			return 0;
	}
	return n;
}
void ManualFilling(long long* arr, int n) {
	std::cout << "Введите элементы массива n.\n";
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
}
bool RandomFilling(long long* arr, int n) {
	long long a, b;
		std::cout << " Введите начало интервала рандома a: ";
		std::cin >> a;
		std::cout << "Введите конец интервала рандома b: ";
		std::cin >> b;
		if (a > b) {
			std::cout << "b > a";
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
	std::cout << "Массив: ";
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}
void FindPalindrome(long long* arr, int n, int& Start, int& Length) {
	Start = -1;
	Length = 0;

	if (n <= 0) return;
	for (int length = n; length >= 2; length--) {
		for (int start = 0; start <= n - length; start++) {
			int end = start + length - 1;

			bool Palindrome = true;
			int left = start;
			int right = end;

			while (left < right) {
				if (arr[left] != arr[right]) {
					Palindrome = false;
					break;
				}
				left++;
				right--;
			}

			if (Palindrome) {
				Start = start;
				Length = length;
				return ;
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "RU");
	int n = MassiveSize();
	if (n <= 1) {
		return 1;
	}
	long long* arr = new long long[n];
	int choise;
	std::cout << " Выберите метод ввода : 1 - с клавиатуры ,другое - рандом";
	std::cin >> choise;
	if (choise == 1) {
		ManualFilling(arr, n);
	}
	else {
		if (!RandomFilling(arr, n)) {
			return 1;
		}
	}
	PrintMassive(arr, n);

	int Start = -1;
	int Length = 0;

	FindPalindrome(arr, n, Start, Length);

	if (Length >= 2) {
		std::cout << "Палиндром: ";
		for (int i = Start; i < Start + Length; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
	else {
		std::cout << "ОШИБКА: палиндром не найден\n";
	}

	delete[] arr;
	return 0;
}
