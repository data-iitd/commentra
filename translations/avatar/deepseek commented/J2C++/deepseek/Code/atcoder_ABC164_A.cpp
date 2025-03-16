#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::vector<std::string> scList;
    std::string line;

    // Continuously read input lines from the user until an exception occurs
    while (true) {
        try {
            std::getline(std::cin, line);
            scList.push_back(line);
        } catch (const std::exception& e) {
            break;
        }
    }

    // Get the first line of input and split it into an array of strings
    std::stringstream ss(scList[0]);
    std::string numlist[2];
    std::getline(ss, numlist[0], ' ');
    std::getline(ss, numlist[1], ' ');

    // Parse the first element to get the number of sheep
    int Sheep = std::stoi(numlist[0]);

    // Parse the second element to get the number of wolves
    int Wolve = std::stoi(numlist[1]);

    // Check if the number of wolves is greater than or equal to the number of sheep
    if (Wolve >= Sheep) {
        std::cout << "unsafe" << std::endl; // Print "unsafe" if the condition is true
    } else {
        std::cout << "safe" << std::endl; // Print "safe" otherwise
    }

    return 0;
}
