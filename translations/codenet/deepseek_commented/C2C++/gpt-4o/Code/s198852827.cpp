#include <iostream>  // Include the iostream library for input-output operations
#include <cmath>     // Include the cmath library for mathematical functions

#define ABS(x) (((x) < (0)) ? (-(x)) : (x))  // Define a macro to return the absolute value of a number

int main() {  // Start of the main function
    int N, t, x, y, nx = 0, ny = 0, nt = 0;  // Declare variables to store the values of N, t, x, y, and their initial positions nx, ny, and starting time nt
    std::cin >> N;  // Read the number of movements from the standard input
    for (int i = 0; i < N; i++) {  // Start a loop that runs N times
        std::cin >> t >> x >> y;  // Read the time and coordinates for each movement
        int tmp = t - nt - (ABS(x - nx) + ABS(y - ny));  // Calculate the difference between the required time and the actual time needed to reach the coordinates
        if (tmp < 0 || tmp % 2) {  // Check if the difference is less than 0 or if it is odd
            std::cout << "No" << std::endl;  // Output "No" and terminate the program
            return 0;
        }
        nx = x;  // Update the current x-coordinate
        ny = y;  // Update the current y-coordinate
        nt = t;  // Update the current time
    }
    std::cout << "Yes" << std::endl;  // If the loop completes without issues, output "Yes"
    return 0;
}  // End of the main function
// <END-OF-CODE>
