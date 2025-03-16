#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector<int> L;
    std::string line;

    // Read the first input line (not used)
    std::getline(std::cin, line);

    int r = 1;
    // Read the second input line
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int k;

    while (iss >> k) {
        L.insert(L.end(), k, r);
        r++;
    }

    // Read the third input line (not used)
    std::getline(std::cin, line);

    // Read the fourth input line
    std::getline(std::cin, line);
    std::istringstream iss2(line);
    int j;

    while (iss2 >> j) {
        std::cout << L[j - 1] << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
