#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::vector<std::string> scList;
    std::string line;

    // Read input lines from the console and store them in the vector
    while (true) {
        try {
            std::getline(std::cin, line);
            scList.push_back(line);
        } catch (const std::exception& e) {
            break;
        }
    }

    // Extract the first line of the input (which contains the number of sheep and wolves)
    std::istringstream iss(scList[0]);
    int Sheep, Wolve;
    std::string numlist[2];

    // Read the first two elements of the numlist array as integers representing the number of sheep and wolves
    iss >> numlist[0] >> numlist[1];
    Sheep = std::stoi(numlist[0]);
    Wolve = std::stoi(numlist[1]);

    // Check if the number of wolves is greater than or equal to the number of sheep
    // If so, print "unsafe" to the console. Otherwise, print "safe".
    if (Wolve >= Sheep) {
        std::cout << "unsafe" << std::endl;
    } else {
        std::cout << "safe" << std::endl;
    }

    return 0;
}
