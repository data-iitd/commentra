#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<std::string> input_array;
    std::string token;

    while (std::getline(iss, token, ' ')) {
        input_array.push_back(token);
    }

    int result = 0;

    for (const auto& str : input_array) {
        result += 1;
        if (str == "0") break;
    }

    std::cout << result << std::endl;
    return 0;
}
