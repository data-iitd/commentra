#include <iostream>
#include <vector>
#include <string>

int main() {
    int firstline;
    std::cin >> firstline;
    int total = 0;
    std::vector<std::string> memory;

    for (int x = 0; x < firstline; x++) {
        int A, G;
        std::cin >> A >> G;
        if (total + A <= 500) {
            total += A;
            memory.push_back("A");
        } else {
            total -= G;
            memory.push_back("G");
        }
    }

    for (const auto& m : memory) {
        std::cout << m;
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
