#include <iostream> // Include the iostream library for input and output operations

int main() { // Entry point of the program
    int a, b; // Declare two integer variables 'a' and 'b' to store user input
    std::cin >> a >> b; // Read the first and second integer values from the standard input

    int res = a; // Initialize the result variable with the value of 'a'

    while (a >= b) { // Start a while loop that continues as long as 'a' is greater than or equal to 'b'
        res += (a / b); // Increment the result variable by the result of dividing 'a' by 'b'
        a = (a / b) + (a % b); // Update the value of 'a' with the result of the division and the remainder
    }

    std::cout << res << std::endl; // Print the value of the result variable to the standard output stream

    return 0; // Return 0 to indicate successful execution of the program
}
