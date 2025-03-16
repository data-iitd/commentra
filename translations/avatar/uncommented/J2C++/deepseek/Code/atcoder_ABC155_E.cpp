#include <iostream>
#include <vector>
#include <string>

int main() {
    const long long INF = 1e15;
    std::string number;
    std::cin >> number;
    std::vector<int> digits(number.length() + 1);
    for (size_t i = 0; i < number.length(); ++i) {
        digits[i] = number[number.length() - 1 - i] - '0';
    }
    long long bills = 0;
    for (size_t i = 0; i <= number.length(); ++i) {
        if (digits[i] == 10) {
            digits[i + 1]++;
            digits[i] = 0;
        }
        if (digits[i] < 5) {
            bills += digits[i];
        } else if (digits[i] == 5) {
            if (digits[i + 1] >= 5) {
                digits[i + 1]++;
            }
            bills += 5;
        } else {
            digits[i + 1]++;
            bills += 10 - digits[i];
        }
    }
    std::cout << bills << std::endl;
    return 0;
}
