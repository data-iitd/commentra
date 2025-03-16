#include <iostream> // Include the iostream library for input/output

int main() // Start of the main function
{
    unsigned long long int n, b = 0; // Declare variables n and b of type unsigned long long int and initialize b to zero

    std::cin >> n; // Read an unsigned long long integer value from the standard input and store it in the variable n

    b = (n * (n - 1)) / 2; // Calculate the sum of numbers from 1 to n-1 and store the result in the variable b

    std::cout << b << std::endl; // Print the value of b to the standard output

    return 0; // End of the main function with a return value of 0 indicating successful execution
}

// <END-OF-CODE>
