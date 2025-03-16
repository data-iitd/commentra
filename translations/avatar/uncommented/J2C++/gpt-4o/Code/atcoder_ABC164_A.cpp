#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector<std::string> scList;
    std::string line;

    // Read input until EOF
    while (std::getline(std::cin, line)) {
        scList.push_back(line);
    }

    // Split the first line into numbers
    std::istringstream iss(scList[0]);
    int Sheep, Wolve;
    iss >> Sheep >> Wolve;

    // Check the condition and print the result
    if (Wolve >= Sheep) {
        std::cout << "unsafe" << std::endl;
    } else {
        std::cout << "safe" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
