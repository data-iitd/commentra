#include <iostream>
#include <vector>
#include <string>
#include <numeric> // for std::accumulate

int main() {
    std::string n;
    std::cin >> n;

    std::vector<std::string> a = {"10", "100", "1000", "10000", "100000"};

    // Convert the input string into a list of integers and calculate the sum
    int new_sum = std::accumulate(n.begin(), n.end(), 0, [](int sum, char c) { return sum + (c - '0'); });

    // Check if the input is one of the predefined values in the list 'a'
    if (std::find(a.begin(), a.end(), n) != a.end()) {
        // If the input matches one of the predefined values, print 10
        std::cout << 10 << std::endl;
    } else {
        // If the input does not match, print the calculated sum
        std::cout << new_sum << std::endl;
    }

    return 0;
}
