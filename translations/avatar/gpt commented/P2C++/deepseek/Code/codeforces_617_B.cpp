#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>  // For std::accumulate

int main() {
    std::string input;
    std::getline(std::cin, input);  // Read an input line (not used in further calculations)

    std::string a;
    std::getline(std::cin, a);  // Read a string input from the user

    // Check if the string contains any '1's
    // If there are no '1's, print 0
    // Otherwise, calculate the product of counts of '0's between '1's
    if (a.find('1') == std::string::npos) {
        std::cout << 0 << std::endl;
    } else {
        std::stringstream ss(a);
        std::string segment;
        std::vector<int> counts;

        while (std::getline(ss, segment, '1')) {
            if (!segment.empty()) {
                counts.push_back(segment.length());
            }
        }

        for (auto& count : counts) {
            count = count.length() + 1;
        }

        int product = 1;
        for (const auto& count : counts) {
            product *= count;
        }

        std::cout << product << std::endl;
    }

    return 0;
}
