#include <iostream>
#include <vector>
#include <string>

int main() {
    int firstline;
    std::cin >> firstline;
    int total = 0;
    std::vector<char> memory;
    for (int x = 0; x < firstline; ++x) {
        int A, G;
        std::cin >> A >> G;
        if (total + A <= 500) {
            total += A;
            memory.push_back('A');
        } else {
            total -= G;
            memory.push_back('G');
        }
    }
    for (char c : memory) {
        std::cout << c;
    }
    std::cout << std::endl;
    return 0;
}

