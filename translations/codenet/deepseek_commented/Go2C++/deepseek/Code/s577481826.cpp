#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int a, b;
    iss >> a;

    std::getline(std::cin, line);
    std::istringstream iss2(line);
    iss2 >> b;

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
