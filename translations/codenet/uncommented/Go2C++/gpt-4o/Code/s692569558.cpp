#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line); // Read the first line (not used)
    std::getline(std::cin, line); // Read the second line

    std::istringstream iss(line);
    std::vector<int> dn;
    int num;

    while (iss >> num) {
        dn.push_back(num);
    }

    int sum = 0;
    for (size_t i = 0; i < dn.size(); i++) {
        for (size_t j = i + 1; j < dn.size(); j++) {
            sum += dn[i] * dn[j];
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// <END-OF-CODE>
