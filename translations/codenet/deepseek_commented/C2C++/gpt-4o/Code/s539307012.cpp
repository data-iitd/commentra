#include <iostream>  // Include the iostream library for input-output operations

int main() {
    int n, x, min, m;  // Declare variables to store input values
    std::cin >> n >> x >> min;  // Read three integers from standard input
    x -= min;  // Subtract the minimum value from x
    for (int i = 1; i < n; i++) {  // Start a loop from 1 to n-1
        std::cin >> m;  // Read the next integer
        x -= m;  // Subtract the current integer from x
        if (min > m) {  // Check if the current integer is less than the current min
            min = m;  // Update min to the current integer if true
        }
    }
    std::cout << n + x / min << std::endl;  // Print the result
    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
