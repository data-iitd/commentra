
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int a, b, c;
    if (std::getline(iss, line,'') && std::getline(iss, line)) {
        std::istringstream(line) >> a;
        std::istringstream(line) >> b;
        c = a - b * 2;
        if (c < 0) c = 0;
        std::cout << c << std::endl;
    }
    return 0;
}

