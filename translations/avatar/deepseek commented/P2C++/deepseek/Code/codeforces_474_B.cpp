#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector<int> L;
    std::string input1;
    std::getline(std::cin, input1);
    int r = 1;
    std::istringstream iss1(input1);
    std::string k;
    while (iss1 >> k) {
        L.insert(L.end(), r, std::stoi(k));
        r++;
    }

    std::string input2;
    std::getline(std::cin, input2);
    std::istringstream iss2(input2);
    std::string j;
    while (iss2 >> j) {
        std::cout << L[std::stoi(j) - 1] << std::endl;
    }

    return 0;
}

