#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input); // Read the first line (which we will ignore)
    std::getline(std::cin, input); // Read the second line

    std::istringstream iss(input);
    std::vector<int> dn;
    std::string d;

    while (std::getline(iss, d, ' ')) {
        dn.push_back(std::stoi(d));
    }

    int sum = 0;

    for (size_t i = 0; i < dn.size(); ++i) {
        for (size_t j = i + 1; j < dn.size(); ++j) {
            sum += dn[i] * dn[j];
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

