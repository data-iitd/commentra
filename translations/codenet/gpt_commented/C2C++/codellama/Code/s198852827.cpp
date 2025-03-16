#include<iostream>

// Macro to calculate the absolute value of a number
#define ABS(x) (((x)<(0))?(-(x)):(x))

int main(void) {
    // Declare variables
    int N, t, x, y, nx = 0, ny = 0, nt = 0;
    int i, j, k, tmp;

    // Read the number of test cases
    std::cin >> N;
    
    // Loop through each test case
    for(i = 0; i < N; i++) {
        // Read the time and coordinates for each test case
        std::cin >> t >> x >> y;
        
        // Calculate the time left after accounting for the previous time and the distance traveled
        tmp = t - nt - (ABS(x - nx) + ABS(y - ny));
        
        // Check if the remaining time is negative or odd
        if(tmp < 0 || tmp % 2) {
            // If so, print "No" and exit the program
            std::cout << "No" << std::endl;
            return 0;
        }
        
        // Update the current position and time for the next iteration
        nt = t; // Update the previous time
        nx = x; // Update the previous x coordinate
        ny = y; // Update the previous y coordinate
    }
    
    // If all test cases are valid, print "Yes"
    std::cout << "Yes" << std::endl;
    return 0;
}

