
#include <iostream>
#include <string>
#include <map>

int main() {
    // Read an integer input n which represents the threshold for majority
    int n;
    std::cin >> n;

    // Read a line of input, split it into a map of strings to integers, and store it in m
    std::map<std::string, int> m;
    std::string word;
    while (std::cin >> word) {
        m[word]++;
    }

    // Initialize a variable to track if a majority element is possible
    bool possible = true;

    // Iterate through each unique element in the map m
    for (auto const& [key, value] : m) {
        // Check if the count of the current element key is greater than or equal to n/2 + 1
        if (value >= n / 2 + 1) {
            // If it is, set possible to False and break the loop
            possible = false;
            break;
        }
    }

    // Print 'YES' if a majority element is not found, otherwise print 'NO'
    std::cout << (possible? "YES" : "NO") << std::endl;

    return 0;
}
