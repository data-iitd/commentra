#include <iostream>
#include <vector>
#define N 2000

// Declare global variables
int num1, math[N + 1] = {0}; // Initialize the math array to 0

int main() {
    int a, num2, ans, sum = 0; // Declare variables for input and calculations

    // Initialize the first element of the math array to 1
    math[0] = 1;

    // Read the number of elements for the first set
    std::cin >> num1;

    // Loop to read each element and update the possible sums
    for (int i = 0; i < num1; i++) {
        std::cin >> a; // Read the current element
        sum += a; // Update the total sum

        // Update the math array to reflect the new possible sums
        for (int j = sum - a; j >= 0; j--) {
            if (math[j] == 1) {
                math[j + a] = 1; // Mark the new sum as possible
            }
        }
    }

    // Read the number of queries for possible sums
    std::cin >> num2;

    // Loop to check if each queried sum is possible
    for (int i = 0; i < num2; i++) {
        std::cin >> ans; // Read the queried sum
        // Check if the queried sum is possible and print the result
        (math[ans] == 1) ? std::cout << "yes\n" : std::cout << "no\n";
    }

    return 0; // End of the program
}

// <END-OF-CODE>
