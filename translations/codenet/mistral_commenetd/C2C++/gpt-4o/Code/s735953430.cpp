#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

int main() {
    // Declare variables
    int i_min, min; // i_min stores the index of the minimum number, min stores the minimum number
    int i, j, k; // i, j, k are loop variables
    int X, N; // X is the given number, N is the number of numbers to be subtracted

    // Read input values X and N from the user
    std::cin >> X >> N;

    // Check if N is zero, if yes, print X and exit the program
    if (N == 0) {
        std::cout << X << std::endl;
        return 0;
    }

    // Initialize two vectors plus and minus of size 256
    std::vector<int> plus(256);
    std::vector<int> minus(256);
    for (i = 0; i < 256; i++) {
        // Initialize plus vector with numbers from 0 to 255
        plus[i] = i;
        // Initialize minus vector with negative numbers of plus vector
        minus[i] = (-1 * i);
    }

    // Subtract the given numbers from the plus vector
    for (i = 0; i < N; i++) {
        std::cin >> j;
        // Set the corresponding index in the plus vector to zero
        plus[j] = 0;
    }

    // Initialize variables i_min and min with initial values
    i_min = 0;
    min = 1000;

    // Find the minimum number in the plus vector that is not zero and can form the difference X
    for (i = 255; i >= 0; i--) {
        // Skip the iteration if the current number in the plus vector is zero and it is not the first element
        if (plus[i] == 0 && i > 0) {
            continue;
        }
        // Calculate the difference between X and the current number in the plus vector
        k = X - plus[i];
        // If the difference is negative, make it positive
        if (k < 0) { k *= -1; }
        // Update min and i_min if the current difference is smaller than the previous minimum
        if (k <= min) {
            min = k;
            i_min = i;
        }
    }

    // Print the index of the minimum number
    std::cout << i_min << std::endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
