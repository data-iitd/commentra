#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>

std::string TenToN(int number, int n) {
    std::string s = "";
    int tmp = number;
    while (true) {
        s = std::to_string(tmp % n) + s;
        if (tmp < n) {
            break;
        }
        tmp /= n;
    }
    return s;
}

int main() {
    int N, K;
    std::cin >> N >> K;

    std::string s = TenToN(N, K);
    std::cout << s.length() << std::endl;

    return 0;
}

