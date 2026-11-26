#include <iostream>
#include <iomanip>
#include <chrono> 
#include <ctime> 
#include <string>
#include <fstream>
#include <vector>
std::time_t Now() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}

auto FormatTime(std::time_t time, bool is_utc_format = false) {
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4996)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif
    return is_utc_format ? std::put_time(std::gmtime(&time), "%d.%m.%Y %H:%M:%S")
        : std::put_time(std::localtime(&time), "%d.%m.%Y %H:%M:%S");
#if defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
}

void WriteLog(const std::string& message) {
    std::ofstream logFile("C:\\Users\\dmitr\\source\\repos\\Lab6Var3\\log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << "[" << FormatTime(Now(), false) << "] " << message << "\n";
    }
}
bool isValidPhone(const std::string& number) {
    if (number.length() != 19) {
        return false;
    }

    std::string code = number.substr(6, 2);
    if (number[0] != '+' || number[1] != '3' || number[2] != '7' || number[3] != '5' ||
        number[4] != ' ' || number[5] != '(' || number[8] != ')' || number[9] != ' ' ||
        number[13] != '-' || number[16] != '-' ||
        (code != "33" && code != "29" && code != "44" && code != "25")) {
        return false;
    }

    if (number[10] < '0' || number[10] > '9' ||
        number[11] < '0' || number[11] > '9' ||
        number[12] < '0' || number[12] > '9' ||
        number[14] < '0' || number[14] > '9' ||
        number[15] < '0' || number[15] > '9' ||
        number[17] < '0' || number[17] > '9' ||
        number[18] < '0' || number[18] > '9') {
        return false;
    }

    return true;
}
int main() {
    WriteLog("=== Запуск программы ===");
	std::ifstream klop("C:\\Users\\dmitr\\source\\repos\\Lab6Var3\\Lab6Var3\\vvod.txt");
	std::ofstream dox("C:\\Users\\dmitr\\source\\repos\\Lab6Var3\\Lab6Var3\\vivod.txt");
	if (!klop.is_open() || !dox.is_open()) {
		std::cout << "ERROR WITH FILES" << std::endl;
         WriteLog("ОШИБКА: Не удалось открыть vvod.txt или vivod.txt");
		return 1;
	}
    WriteLog("Файлы vvod.txt и vivod.txt успешно открыты");
	std::string line;
    int lineCount = 0;
	while (std::getline(klop, line)) {
        lineCount++;
		if (!line.empty() && line.back() == '\r') {
			line.pop_back();
		}
	std::vector<std::string> validNumbers;
	std::string currentNum = "";
	for (size_t i = 0; i <= line.length(); ++i) {
		if (i == line.length() || line[i] == ';') {
            if (isValidPhone(currentNum)) {
                validNumbers.push_back(currentNum);
            }
            currentNum = "";
        }
        else {
            currentNum += line[i];
        }
    }
    if (validNumbers.empty()) {
        dox << "no valid numbers\n";
    }
    else {
        for (size_t i = 0; i < validNumbers.size(); ++i) {
            if (i > 0) dox << " ";
            dox << validNumbers[i];
        }
        dox << "\n";
    }
    }

    WriteLog("Обработка завершена. Прочитано и записано строк: " + std::to_string(lineCount)); 
    klop.close();
    dox.close();
    WriteLog("Файлы vvod.txt и vivod.txt закрыты. Завершение работы.\n");
    return 0;
}
            