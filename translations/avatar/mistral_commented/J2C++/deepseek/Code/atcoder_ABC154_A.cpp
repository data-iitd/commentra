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
    std::istringstream iss2(line);
    int a, b;
    iss2 >> a >> b;

    std::getline(std::cin, line);
    std::string u = line;

    if (u == str[0]) {
        std::cout << (a - 1) << " " << b << std::endl;
    } else {
        std::cout << a << " " << (b - 1) << std::endl;
    }

    return 0;
}
