#include <iostream>
long long processNumber(long long n);
int main() {
   std::cout << "Enter n: ";
    long long n;
    std::cin >> n;
    if (n <= 0) {
        std::cout << " ENTER ONLY POSITIVE n" <<std::endl;
        return 1;
    }
    std::cout << "Result: " << processNumber(n) << std::endl;

    return 0;
}
long long processNumber(long long n) {
    long long temp = n;
    long long min_digit = 9;
    long long multiplier = 10;
    while (temp > 0) {
        long long digit = temp % 10;
        if (digit != 0 && digit < min_digit) {
            min_digit = digit;
        }
        multiplier *= 10;
        temp /= 10;
    }
    return min_digit * multiplier + (n * 10) + min_digit;
}