#include <iostream> // Include the iostream library for input/output

int main() { // Define the main function
    int A, B; // Declare two integer variables A and B
    std::cin >> A >> B; // Read two integers from the standard input and store them in variables A and B
    if (A < 10 && B < 10) { // Check if both A and B are less than 10
        std::cout << A * B << std::endl; // If true, print the product of A and B to the standard output
    } else { // If the condition is false
        std::cout << "-1" << std::endl; // Print -1 to the standard output as an error message
    }
    return 0; // Indicate that the program has run successfully
} // End of main function
// <END-OF-CODE>
