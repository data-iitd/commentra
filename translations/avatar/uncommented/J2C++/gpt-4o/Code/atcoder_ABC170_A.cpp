#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string str;
    int result = 0;

    while (iss >> str) {
        result += 1;
        if (str == "0") break;
    }

    std::cout << result << std::endl;
    return 0;
}

// <END-OF-CODE>
