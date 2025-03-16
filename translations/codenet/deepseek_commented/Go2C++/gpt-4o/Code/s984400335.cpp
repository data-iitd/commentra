#include <iostream>
#include <algorithm> // For std::min

// Function to find the minimum of two integers
int min(int x, int y) {
    return std::min(x, y); // Use std::min to find the minimum
}

int main() {
    int n, a, b;
    std::cin >> n >> a >> b; // Read three integers from input

    std::cout << min(n * a, b) << std::endl; // Print the minimum of n*a and b
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
