#include <iostream>
#include <vector>
#include <sstream>
#include <numeric> // for std::accumulate

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::vector<int> numbers;
    std::string token;

    while (std::getline(iss, token, ' ')) {
        numbers.push_back(std::stoi(token));
    }

    std::vector<int> ABC(numbers.begin(), numbers.end());

    if (std::count(ABC.begin(), ABC.end(), 5) == 2) {
        if (std::accumulate(ABC.begin(), ABC.end(), 0) == 17) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
