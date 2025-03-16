#include <iostream> // Include the iostream library for input/output

int main() // The entry point of the program
{
    // Declare two integer variables n and m
    int n, m;

    // Use the cin object to read two integers from the standard input and store them in n and m variables
    std::cin >> n >> m;

    // Calculate the product of (n - 1) and (m - 1) and store the result in the variable result
    int result = (n - 1) * (m - 1);

    // Use the cout object to print the result to the standard output
    std::cout << result << std::endl;

    // Indicate that the program has run successfully and terminate it
    return 0;
}

// <END-OF-CODE>
