#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> numbers;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ' ')) {
        numbers.push_back(std::stoi(token));
    }

    if (std::count(numbers.begin(), numbers.end(), 5) == 2) {
        int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
        if (sum == 17) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
