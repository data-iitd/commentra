#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::vector<std::string> scList;
    std::string input;

    while (true) {
        try {
            std::getline(std::cin, input);
            scList.push_back(input);
        } catch (const std::exception& e) {
            break;
        }
    }

    std::stringstream ss(scList[0]);
    std::string token;
    std::vector<int> numlist;

    while (std::getline(ss, token, ' ')) {
        numlist.push_back(std::stoi(token));
    }

    int Sheep = numlist[0];
    int Wolf = numlist[1];

    if (Wolf >= Sheep) {
        std::cout << "unsafe" << std::endl;
    } else {
        std::cout << "safe" << std::endl;
    }

    return 0;
}

