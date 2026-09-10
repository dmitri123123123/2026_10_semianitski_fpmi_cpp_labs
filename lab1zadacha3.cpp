#include <iostream>

int main() {
    int number;
    std::cout << "enter four-digit number: ";
    std::cin >> number;

    int n1 = number / 1000;
    int n2 = (number / 100) % 10;
    int n3 = (number / 10) % 10;
    int n4 = number % 10;

    if (n1 == n4) {
        if (n2 == n3) {
            std::cout << "Yes , this is palindrom!" << std::endl;
        }
    }
    else {
        std::cout << "No , this is no palindrom." << std::endl;
    }

    return 0;
}