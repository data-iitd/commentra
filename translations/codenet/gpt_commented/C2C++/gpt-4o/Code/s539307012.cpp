#include <iostream>

int main() {
    // Declare variables
    int n, x, min, m;

    // Read the number of elements (n), a value (x), and the initial minimum value (min)
    std::cin >> n >> x >> min;

    // Adjust x by subtracting the initial minimum value
    x -= min;

    // Loop through the remaining n-1 elements to read their values
    for(int i = 1; i < n; i++) {
        // Read the next element into variable m
        std::cin >> m;

        // Subtract the current element from x
        x -= m;

        // Update min if the current element is smaller than the current minimum
        if(min > m) {
            min = m;
        }
    }

    // Calculate and print the result based on the number of elements and the adjusted x divided by the minimum value
    std::cout << n + x / min << std::endl;

    return 0; // Return 0 to indicate successful completion of the program
} // <END-OF-CODE>
