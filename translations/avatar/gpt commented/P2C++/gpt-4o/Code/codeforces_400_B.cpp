#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    // Read two integers n and m from input
    int n, m;
    std::cin >> n >> m;

    // Create a set to store the differences
    std::set<int> differences;

    // Read n strings and calculate the difference in indices of 'S' and 'G'
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;

        // Find the indices of 'S' and 'G'
        int indexS = s.find('S');
        int indexG = s.find('G');

        // Calculate the difference and insert it into the set
        differences.insert(indexS - indexG);
    }

    // Check if any of the calculated differences are negative
    bool hasNegative = false;
    for (const auto& diff : differences) {
        if (diff < 0) {
            hasNegative = true;
            break;
        }
    }

    // Print the result
    std::cout << (hasNegative ? -1 : differences.size()) << std::endl;

    return 0;
}
// <END-OF-CODE>
