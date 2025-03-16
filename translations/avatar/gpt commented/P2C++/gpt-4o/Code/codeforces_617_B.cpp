#include <iostream>
#include <string>
#include <vector>
#include <numeric> // For std::accumulate
#include <algorithm> // For std::count

int main() {
    std::string input; // Variable to hold the input
    std::getline(std::cin, input); // Read the input line (not used in further calculations)

    std::getline(std::cin, input); // Read a string input from the user

    // Check if the string contains any '1's
    // If there are no '1's, print 0
    if (std::count(input.begin(), input.end(), '1') == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::vector<int> counts; // Vector to hold counts of '0's between '1's
        size_t start = 0, end;

        // Split the input string by '1's and count '0's in each segment
        while ((end = input.find('1', start)) != std::string::npos) {
            counts.push_back(std::count(input.begin() + start, input.begin() + end, '0') + 1);
            start = end + 1; // Move past the '1'
        }
        // Handle the last segment after the last '1'
        counts.push_back(std::count(input.begin() + start, input.end(), '0') + 1);

        // Calculate the product of these counts
        int product = std::accumulate(counts.begin(), counts.end(), 1, std::multiplies<int>());
        std::cout << product << std::endl;
    }

    return 0;
} // <END-OF-CODE>
