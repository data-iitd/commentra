#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string input;
    int a, b;

    std::getline(std::cin, input);
    std::istringstream(input) >> a;
    std::getline(std::cin, input);
    std::istringstream(input) >> b;

    int ret = a + b;

    if (ret < (a - b)) {
        ret = a - b;
    }
    if (ret < (a * b)) {
        ret = a * b;
    }

    std::cout << ret << std::endl;

    return 0;
}

// <END-OF-CODE>
