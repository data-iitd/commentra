#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int main() {
    // Read input from the user
    std::string n;
    std::cin >> n;

    // Define a list of string representations of powers of ten
    std::vector<std::string> a = {"10", "100", "1000", "10000", "100000"};

    // Convert the input string into a list of integers and calculate the sum
    int new_sum = 0;
    for (char c : n) {
        new_sum += c - '0'; // Convert char to int
    }

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

// <END-OF-CODE>
