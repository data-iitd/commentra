#include <iostream>

int main() {
    // Create a variable to read input from the user
    int a, b;
    
    // Read two integers from the input
    std::cin >> a >> b;
    
    // Initialize sum to 0, this will store the sum of the two numbers
    int sum = 0;
    
    // Loop runs twice, each time adding the larger of the two numbers to sum
    // and decrementing that number by 1
    for (int i = 0; i < 2; i++) {
        if (a >= b) {
            sum += a;
            a = a - 1;
        } else {
            sum += b;
            b = b - 1;
        }
    }
    
    // Print the final sum to the console
    std::cout << sum << std::endl;

    return 0;
}

// <END-OF-CODE>
