#include <iostream>
#include <limits>

int main() {
    long sum = 0; // Initialize sum to 0
    int m, n; // Declare variables
    int min = std::numeric_limits<int>::max(); // Initialize min to the maximum possible integer
    int max = std::numeric_limits<int>::min(); // Initialize max to the minimum possible integer

    // Read the number of integers to be input from the user
    std::cin >> n;

    // Iterate through each integer input
    for(int i = 0; i < n; i++) {
        std::cin >> m; // Read an integer input and assign it to m
        sum += m; // Add the current integer input to the sum
        
        // Update min and max values if the current input is smaller or larger
        if(min > m) {
            min = m; // Set min to the current input if it's smaller
        }
        if(max < m) {
            max = m; // Set max to the current input if it's larger
        }
    }
    
    // Print the minimum value, maximum value, and sum of the input integers
    std::cout << min << " " << max << " " << sum << std::endl;

    return 0; // Indicate that the program ended successfully
}

// <END-OF-CODE>
