
#include <iostream>

// Function to compute the Greatest Common Divisor (GCD) of two numbers
int G(int a, int b) {
    // Continue looping until b becomes 0
    while (a % b!= 0) {
        // Update a and b using the Euclidean algorithm
        a = b;
        b = a % b;
    }
    // Return the GCD
    return b;
}

// Function to compute the Least Common Multiple (LCM) of two numbers
int L(int a, int b) {
    // Calculate LCM using the relationship between GCD and LCM
    return a * b / G(a, b);
}

int main() {
    // Read input values and split them into a list
    int x, y, a, b;
    std::cin >> x >> y >> a >> b;

    // Calculate the LCM of x and y
    int lcm = L(x, y);

    // Calculate and print the count of multiples of LCM in the range [a, b]
    std::cout << b / lcm - (a - 1) / lcm << std::endl;

    return 0;
}

