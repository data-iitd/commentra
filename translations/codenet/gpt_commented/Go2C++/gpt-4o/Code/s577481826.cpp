#include <iostream>
#include <string>
#include <sstream>
#include <limits>

int main() {
    // Initialize variables to store the input integers
    int a, b;

    // Read two integers from input
    std::cin >> a >> b;

    // Initialize ret with the sum of a and b
    int ret = a + b;

    // Check if ret is less than the difference of a and b
    if (ret < (a - b)) {
        ret = a - b; // Update ret to the difference if it's smaller
    }
    // Check if ret is less than the product of a and b
    if (ret < (a * b)) {
        ret = a * b; // Update ret to the product if it's smaller
    }

    // Print the final result
    std::cout << ret << std::endl;

    return 0;
}

// <END-OF-CODE>
