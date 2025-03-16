#include <iostream>  // Include the input/output stream library

int main() {  // Define the main function
    long long int a, b, c;  // Declare variables to store the input values
    std::cin >> a >> b >> c;  // Read three long long integers from the user

    long long int d = c - a - b;  // Calculate the difference between c and the sum of a and b
    if ((d > 0) && ((4 * a * b) < d * d))  // Check if the difference is positive and satisfies the specific condition
        std::cout << "Yes" << std::endl;  // Print "Yes" if the condition is met
    else
        std::cout << "No" << std::endl;  // Print "No" otherwise

    return 0;  // Return 0 to indicate successful program termination
}  // End of main function
// <END-OF-CODE>
