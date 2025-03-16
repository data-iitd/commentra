#include <iostream>  // Include the iostream library for input-output operations
#include <vector>    // Include the vector library for dynamic arrays

int main()  // Define the main function, the entry point of the program
{
    long int n;  // Declare a variable to store the number of elements

    std::cin >> n;  // Read the value of n from the standard input
    std::vector<long int> a(n);  // Declare a vector `a` with size n
    std::vector<long int> count(n, 0);  // Declare a vector `count` with size n and initialize to zero

    for (long int i = 1; i < n; i++)  // Loop to read n-1 values into the vector `a`
        std::cin >> a[i];

    for (long int i = 1; i < n; i++)  // Loop to increment the `count` vector based on the values in `a`
        count[a[i] - 1]++;

    for (long int i = 0; i < n; i++)  // Loop to print the values in the `count` vector
        std::cout << count[i] << std::endl;

    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
