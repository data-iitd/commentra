#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric> // for std::accumulate

int main() {
    std::string a;
    std::getline(std::cin, a);

    // Count the number of '1's in the input string
    int count_ones = 0;
    for (char c : a) {
        if (c == '1') {
            count_ones++;
        }
    }

    if (count_ones == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // Split the string by '1' and count the number of '0's in each segment
    std::vector<int> segments;
    std::stringstream ss(a);
    std::string segment;
    while (std::getline(ss, segment, '1')) {
        if (!segment.empty()) {
            segments.push_back(segment.length());
        }
    }

    // Calculate the product of (count of '0's + 1) for each segment
    int result = 1;
    for (int num : segments) {
        result *= (num + 1);
    }

    std::cout << result << std::endl;
    return 0;
}
