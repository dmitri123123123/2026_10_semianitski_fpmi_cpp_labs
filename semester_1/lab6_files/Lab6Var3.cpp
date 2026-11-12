#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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
	std::ifstream klop("C:\\Users\\dmitr\\source\\repos\\Lab6Var3\\vvod.txt");
	std::ofstream dox("C:\\Users\\dmitr\\source\\repos\\Lab6Var3\\vivod.txt");
	if (!klop.is_open() || !dox.is_open()) {
		std::cout << "ERROR WITH FILES" << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(klop, line)) {
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

    klop.close();
    dox.close();

    return 0;
}
            