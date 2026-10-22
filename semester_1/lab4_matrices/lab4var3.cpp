#include <iostream>
#include <random>
int** VideletPamitMatrix(int stroki, int stolbzi) {
	int** matrix = new int* [stroki];
	for (int i = 0;i < stroki;i++) {
		matrix[i] = new int[stolbzi];
	}
	return matrix;
}
void FillRuk(int** matrix, int stroki, int stolbzi) {
	std::cout << "vvedite elementi matrizi: " << stroki << "*" << stolbzi << std::endl;
	for (int i = 0;i < stroki;i++) {
		for (int j = 0;j < stolbzi; j++) {
			std::cin >> matrix[i][j];
		}
	}
}
bool FillRandom(int** matrix, int stroki, int stolbzi) {
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
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbzi;j++) {
			matrix[i][j] = dist(gen);
		}
	}
	return true;
}
void NewMatrix(int** A, int** B, int stroki, int stolbzi) {
	for (int i = 0; i < stroki; ++i) {
		for (int j = 0; j < stolbzi; ++j) {
			int sum = 0;
			for (int dstr = -1;dstr <= 1;dstr++) {
				for (int dstlb = -1;dstlb <= 1;dstlb++) {
					if (dstr == 0 && dstlb == 0) continue;
					int neighborRow = i + dstr;
					int neighborCol = j + dstlb;
					if (neighborRow >= 0 && neighborRow < stroki && neighborCol >= 0 && neighborCol < stolbzi) {
						sum += A[neighborRow][neighborCol];
					}
				}
			}
			B[i][j] = sum;
		}
	}
}
void printMatrix(int** matrix, int stroki, int stolbzi, const char* title) {
	std::cout << "\n--- " << title << " ---\n";
	for (int i = 0; i < stroki; i++) {
		for (int j = 0; j < stolbzi;j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}
}
void OsvobodiPamit(int** matrix, int stroki) {
	for (int i = 0; i < stroki; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main() {

	int stroki, stolbzi;
	std::cout << "enter stroki: ";
	std::cin >> stroki;
	std::cout << "enter stolbzi: ";
	std::cin >> stolbzi;

	if (stroki <= 0 || stolbzi <= 0) {
		std::cout << "error!\n";
		return 1;
	}

	int** A = VideletPamitMatrix(stroki, stolbzi);
	int** B = VideletPamitMatrix(stroki, stolbzi);

	int choice;
	std::cout << "select filling method : 1- manual , another- random ";
	std::cin >> choice;

	if (choice == 1) {
		FillRuk(A, stroki, stolbzi);
	}
	else {
		FillRandom(A, stroki, stolbzi);
	}

	NewMatrix(A, B, stroki, stolbzi);

	printMatrix(A, stroki, stolbzi, "first matrix A");
	printMatrix(B, stroki, stolbzi, "second matrix B");

	OsvobodiPamit(A, stroki);
	OsvobodiPamit(B, stroki);

	return 0;
}