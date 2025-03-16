#include <iostream>

int main() {
    // Declare integer variables to hold input values
    int r, d, x;
    
    // Read three integers from standard input
    std::cin >> r >> d >> x;
    
    // Start a loop that will run 10 times
    for (int i = 0; i < 10; i++) {
        // Update the value of x using the formula r*x - d
        x = r * x - d;
        // Print the updated value of x
        std::cout << x << std::endl;
    }
    
    return 0;
}

// <END-OF-CODE>
