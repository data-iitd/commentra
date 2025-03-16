#include <iostream>

// Function to swap the values of two integers
void swap(int &a, int &b) {
    int tmp; // Temporary variable to hold one of the values during swap
    tmp = a; // Store the value of a in tmp
    a = b;   // Assign the value of b to a
    b = tmp; // Assign the value stored in tmp to b
}

int main() {
    int a, b; // Declare two integer variables to hold user input

    // Infinite loop to continuously read input until termination condition is met
    while (true) {
        // Read two integers from user input
        std::cin >> a >> b;
        
        // Check for the termination condition (both inputs are zero)
        if (a == 0 && b == 0) break;

        // If the second number is less than the first, swap them
        if (b < a) swap(a, b);
        
        // Print the sorted values of a and b
        std::cout << a << " " << b << std::endl;
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
