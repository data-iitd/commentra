#include <iostream>

int main() {
    // Declare an integer variable 'n' for input and an unsigned long long int 'm' for storing the result
    int n;
    unsigned long long int m;

    // Read an integer value from the user and store it in 'n'
    std::cin >> n;

    // Initialize 'm' with the value of 'n'
    m = n;

    // Decrease 'n' by 1 to prepare for the factorial calculation
    n--;

    // Loop to calculate the factorial of 'n' (m = n!)
    for (; n > 1; n--) {
        // Multiply 'm' by the current value of 'n'
        m *= n;
    }

    // Print the calculated factorial value stored in 'm'
    std::cout << m << std::endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}
