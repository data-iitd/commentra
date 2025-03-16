
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string sage;
    std::cin >> sage;

    if (sage == "1") {
        std::cout << "Hello World" << std::endl;
    } else if (sage == "2") {
        int sum = 0;
        for (int i = 0; i < 2; i++) {
            std::string num_str;
            std::cin >> num_str;
            int num = std::atoi(num_str.c_str());
            sum += num;
        }
        std::cout << sum << std::endl;
    }

    return 0;
}

