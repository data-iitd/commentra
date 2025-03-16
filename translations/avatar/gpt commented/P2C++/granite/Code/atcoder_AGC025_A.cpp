
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // Read input from the user
    std::string n;
    std::cin >> n;

    // Define a vector of string representations of powers of ten
    std::vector<std::string> a = {"10", "100", "1000", "10000", "100000"};

    // Convert the input string into a vector of integers and calculate the sum
    int new = std::accumulate(n.begin(), n.end(), 0) - '0';

    // Check if the input is one of the predefined values in the vector 'a'
    if (std::find(a.begin(), a.end(), n)!= a.end()) {
        // If the input matches one of the predefined values, print 10
        std::cout << 10 << std::endl;
    } else {
        // If the input does not match, print the calculated sum
        std::cout << new << std::endl;
    }

    return 0;
}
