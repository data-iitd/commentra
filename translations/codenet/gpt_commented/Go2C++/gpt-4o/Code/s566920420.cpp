#include <iostream> // Include the iostream library for input and output operations

int main() {
    int a; // Declare a variable 'a' of type int to store user input
    std::cin >> a; // Read an integer value from standard input and store it in 'a'
    
    // Calculate the expression a + a^2 + a^3 and print the result
    std::cout << a + a * a + a * a * a << std::endl; 
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
