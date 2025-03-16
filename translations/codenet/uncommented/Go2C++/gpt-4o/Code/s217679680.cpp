#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    int a, b;
    iss >> a >> b;

    int tap = 0;
    int consent = 1;
    while (consent < b) {
        consent += a - 1;
        tap++;
    }
    std::cout << tap << std::endl;

    return 0;
}

// <END-OF-CODE>
