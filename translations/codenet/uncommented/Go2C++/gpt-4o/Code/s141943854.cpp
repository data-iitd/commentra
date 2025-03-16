#include <iostream>
#include <string>

void check(bool condition) {
    if (!condition) {
        std::cerr << "error: invalid input" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    std::string sage;
    std::getline(std::cin, sage);

    if (sage == "1") {
        std::cout << "Hello World" << std::endl;
    } else if (sage == "2") {
        int sum = 0;
        for (int i = 0; i < 2; i++) {
            std::string input;
            std::getline(std::cin, input);
            try {
                int num = std::stoi(input);
                sum += num;
            } catch (const std::invalid_argument&) {
                check(false);
            }
        }
        std::cout << sum << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
