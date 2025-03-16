#include <iostream> // Include iostream for input/output
#include <cstdlib>  // Include cstdlib for general functions
#include <limits>   // Include limits for data type limits
#include <cmath>    // Include cmath for mathematical functions

int main() {
    int n; // Declare an integer variable n
    
    // Read an integer input from the user
    std::cin >> n;
    
    // Calculate and print the result based on the input n
    // The expression (24 + (24 - n)) simplifies to (48 - n)
    std::cout << (24 + (24 - n)) << std::endl;
    
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
