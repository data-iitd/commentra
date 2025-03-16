#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

int main() {
    // Declare variables for minimum index and minimum difference
    int i_min, min;
    int i, j, k;
    int X, N;

    // Read the values of X and N from user input
    std::cin >> X >> N;

    // If N is 0, print X and exit the program
    if (N == 0) {
        std::cout << X << std::endl; 
        exit(0);
    }
  
    // Initialize vectors to hold positive and negative values
    std::vector<int> plus(256);
    std::vector<int> minus(256);

    // Fill the plus vector with indices and minus vector with negative indices
    for (i = 0; i < 256; i++) {
        plus[i] = i;
        minus[i] = (-1 * i);
    }

    // Read N values and set corresponding indices in the plus vector to 0
    for (i = 0; i < N; i++) {
        std::cin >> j;
        plus[j] = 0; // Mark the value as unavailable
    }
  
    // Initialize minimum index and minimum difference
    i_min = 0;
    min = 1000;

    // Iterate through the plus vector in reverse order to find the closest value to X
    for (i = 255; i >= 0; i--) {
        // Skip indices that are marked as unavailable (0) and are greater than 0
        if (plus[i] == 0 && i > 0) {
            continue;
        }
        
        // Calculate the difference between X and the current value in the plus vector
        k = X - plus[i];
        if (k < 0) { 
            k *= -1; // Take the absolute value of the difference
        }

        // Update minimum difference and index if a closer value is found
        if (k <= min) {
            min = k;
            i_min = i; // Store the index of the closest value
        }
    }  
  
    // Print the index of the closest value found
    std::cout << i_min << std::endl;
  
    return 0;
}

// <END-OF-CODE>
