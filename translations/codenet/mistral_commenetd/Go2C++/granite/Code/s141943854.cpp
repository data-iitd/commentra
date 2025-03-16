

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
            int num;
            std::cin >> num;
            sum += num;
        }
        std::cout << sum << std::endl;
    }

    return 0;
}

// END-OF-CODE