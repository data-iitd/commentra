#include <iostream> // Include the iostream library for input and output

int main() {
    // Declare two integer variables to hold user input
    int a, b;
    
    // Read two integers from standard input
    std::cin >> a >> b;
    
    // Calculate and print the product of a and b, 
    // and also print the perimeter of a rectangle with sides a and b
    std::cout << a * b << " " << (a + b) * 2 << std::endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
