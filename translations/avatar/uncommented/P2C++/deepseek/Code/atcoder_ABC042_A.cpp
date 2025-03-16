#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::vector<int> ABC;
    std::string token;

    while (std::getline(iss, token, ' ')) {
        ABC.push_back(std::stoi(token));
    }

    if (std::count(ABC.begin(), ABC.end(), 5) == 2) {
        std::cout << (std::accumulate(ABC.begin(), ABC.end(), 0) == 17 ? "YES" : "NO") << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
