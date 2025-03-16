#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int a, b;
    iss >> a >> b;

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
