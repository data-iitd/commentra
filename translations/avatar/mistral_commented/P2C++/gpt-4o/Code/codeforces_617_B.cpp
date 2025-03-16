#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    // Read the input from the standard input
    std::string a;
    std::getline(std::cin, a);

    // Check if the string contains any '1' character
    if (a.find('1') == std::string::npos) {
        // If it doesn't, print 0 and exit the program
        std::cout << 0 << std::endl;
        return 0;
    }

    // If the string contains at least one '1' character, we proceed to calculate the product
    std::vector<int> zero_counts;
    size_t start = 0, end;

    // Split the string by '1' and count zeros in each segment
    while ((end = a.find('1', start)) != std::string::npos) {
        zero_counts.push_back(end - start); // Count zeros before the '1'
        start = end + 1; // Move past the '1'
    }
    zero_counts.push_back(a.length() - start); // Count zeros after the last '1'

    // Calculate the product of (number of zeros + 1) for each segment
    long long product_of_zeros = 1;
    for (int count : zero_counts) {
        product_of_zeros *= (count + 1);
    }

    // Finally, print the result
    std::cout << product_of_zeros << std::endl;

    return 0;
}

// <END-OF-CODE>
