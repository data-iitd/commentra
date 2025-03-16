#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

int main() {
    // Take an input from the user and store it in variable 'a'
    std::string a;
    std::getline(std::cin, a);

    // Count the number of '1's in the input
    int count_of_ones = std::count(a.begin(), a.end(), '1');

    // If there are no '1's, print 0
    if (count_of_ones == 0) {
        std::cout << 0 << std::endl;
    } else {
        // Split the string by '1' and count '0's in each segment
        std::vector<int> counts;
        std::stringstream ss(a);
        std::string segment;

        while (std::getline(ss, segment, '1')) {
            // Count '0's in the segment and add 1
            counts.push_back(segment.length() - std::count(segment.begin(), segment.end(), ' '));
        }

        // Calculate the product of (count of '0's + 1) for each segment
        int result = 1;
        for (int count : counts) {
            result *= (count + 1);
        }

        std::cout << result << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
