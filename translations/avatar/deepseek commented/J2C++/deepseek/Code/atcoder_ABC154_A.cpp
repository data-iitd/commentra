#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string str[2];
    iss >> str[0] >> str[1];

    std::getline(std::cin, line);
    std::istringstream tokenizer(line);
    int a, b;
    tokenizer >> a >> b;

    std::getline(std::cin, line);
    if (line == str[0]) {
        std::cout << (a - 1) << " " << b << std::endl;
    } else {
        std::cout << a << " " << (b - 1) << std::endl;
    }

    return 0;
}

