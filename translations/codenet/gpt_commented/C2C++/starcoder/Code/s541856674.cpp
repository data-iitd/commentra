#include <iostream>

int main() {
    // Declare variables to hold the input values
    int N = 0; // Variable to store the first input value
    int R = 0; // Variable to store the second input value

    // Read two integers from user input
    std::cin >> N >> R;

    // Check if the first input value N is greater than or equal to 10
    if(N >= 10) {
        // If N is 10 or more, print the value of R as is
        std::cout << R << std::endl;
    } else {
        // If N is less than 10, calculate and print R adjusted by the difference from 10
        std::cout << R + 100 * (10 - N) << std::endl;
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
