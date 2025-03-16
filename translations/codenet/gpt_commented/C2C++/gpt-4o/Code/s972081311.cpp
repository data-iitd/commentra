#include <iostream>

int main() {
    // Declare variables to hold the input number and the sum
    int n, sum;

    // Read an integer input from the user
    std::cin >> n;

    // Calculate the sum of the first n natural numbers using the formula n*(n+1)/2
    sum = (n * (n + 1)) / 2;

    // Print the calculated sum to the console
    std::cout << sum << std::endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
