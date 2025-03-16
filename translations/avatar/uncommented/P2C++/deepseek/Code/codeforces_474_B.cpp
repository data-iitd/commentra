#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector<int> L;
    std::string input;
    std::getline(std::cin, input);
    int r = 1;
    std::stringstream ss(input);
    std::string k;
    while (ss >> k) {
        for (int i = 0; i < std::stoi(k); ++i) {
            L.push_back(r);
        }
        ++r;
    }
    std::getline(std::cin, input);
    std::stringstream ss2(input);
    while (ss2 >> k) {
        std::cout << L[std::stoi(k) - 1] << std::endl;
    }
    return 0;
}

