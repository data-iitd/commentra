#include <iostream>

int main(void) {
    // Declare two integer variables A and B
    int A, B;

    // Read two integers from user input
    std::cin >> A >> B;

    // Check if both A and B are less than 10
    if (A < 10 && B < 10) {
        // If both are less than 10, print their product
        std::cout << A * B << std::endl;
    } else {
        // If either A or B is 10 or greater, print -1
        std::cout << "-1" << std::endl;
    }

    // Return 0 to indicate successful execution
    return 0;
}
