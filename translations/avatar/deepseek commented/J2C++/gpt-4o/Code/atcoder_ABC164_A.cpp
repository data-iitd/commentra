#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::vector<std::string> scList; // Create a vector to store input lines
    std::string line;

    // Continuously read input lines from the user until an exception occurs
    while (std::getline(std::cin, line)) {
        scList.push_back(line); // Add the input line to the vector
    }

    // Get the first line of input and split it into an array of strings
    std::istringstream iss(scList[0]);
    std::string num;
    int Sheep, Wolve;

    // Parse the first element to get the number of sheep
    iss >> num;
    Sheep = std::stoi(num);

    // Parse the second element to get the number of wolves
    iss >> num;
    Wolve = std::stoi(num);

    // Check if the number of wolves is greater than or equal to the number of sheep
    if (Wolve >= Sheep) {
        std::cout << "unsafe" << std::endl; // Print "unsafe" if the condition is true
    } else {
        std::cout << "safe" << std::endl; // Print "safe" otherwise
    }

    return 0;
}

// <END-OF-CODE>
