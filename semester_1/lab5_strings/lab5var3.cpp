#include <iostream>
#include <string>
int main() {
	setlocale(LC_ALL, "RU");
	std::string number;
	bool success = false;
	for (int atempts = 1; atempts <= 5; atempts++) {
		std::cout << "Введите ваш номер телефона" << "(" << atempts << "/" << "5" << ")" << std::endl;
		std::getline(std::cin, number);

		const char* sc1 = number.c_str();
		char* sc2 = new char[strlen(sc1) + 1];
		strcpy(sc2, sc1);

		if (number.length() != 19) {
			std::cout << "Ваш номер не корректный" << std::endl;
			continue;
		}
		std::string code = number.substr(6, 2);
		if (number[0] != '+' || number[1] != '3' || number[2] != '7' || number[3] != '5' || number[4] != ' ' || number[5] != '(' || number[8] != ')' || number[9] != ' ' || number[13] != '-' || number[16] != '-' || (code != "33" && code != "29" && code != "44" && code != "25")) {
			std::cout << "Ваш номер не корректный" << std::endl;
			continue;
		}
		if (number[10] < '0' || number[10] > '9' ||
			number[11] < '0' || number[11] > '9' ||
			number[12] < '0' || number[12] > '9' ||
			number[14] < '0' || number[14] > '9' ||
			number[15] < '0' || number[15] > '9' ||
			number[17] < '0' || number[17] > '9' ||
			number[18] < '0' || number[18] > '9') {

			std::cout << "Ваш номер не корректный" << std::endl;
			continue;
		}
		delete[] sc2;
		success = true;
		break;
	}
	if (!success) {
		std::cout << "Ошибка: Превышено количество попыток ввода" << std::endl;
		return 1;
	}
	int sum = 0;
	for (int i = 0; i < 19; ++i) {
		char chisla = number[i];
		if (chisla >= '0' && chisla <= '9') {
			sum += (chisla - '0');
		}
	}
		std::cout << "Ваш номер: " << number << std::endl;
		std::cout << "Сумма цифер вашего номера: " << sum << std::endl;

	return 0;
}