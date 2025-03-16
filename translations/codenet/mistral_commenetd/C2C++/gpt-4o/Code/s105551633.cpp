#include <iostream>
#include <cmath>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

// Function to find the number of digits in a given number
int digit(int64 n) {
    int res = 0; // Initialize result
    while (n > 0) { // While number is not zero
        res++; // Increment result by 1
        n /= 10; // Divide number by 10 to get next digit
    }
    return res; // Return the result
}

// Function to run the program
void run() {
    int64 n; // Initialize number variable
    std::cin >> n; // Read number from standard input
    int min = digit(n); // Initialize minimum with the number of digits in the number
    for (int i = 1; (int64)i * i <= n; i++) { // Loop from 1 to square root of the number
        if (n % i != 0) continue; // If current number is not a factor of the given number, skip to next iteration
        int64 a = i; // Initialize first factor
        int64 b = n / i; // Initialize second factor
        min = MIN(min, MAX(digit(a), digit(b))); // Update minimum with the maximum of digits in first and second factors
    }
    std::cout << min << std::endl; // Print the minimum number of digits in any factor of the given number
}

// Main function
int main() {
    run(); // Call run function to execute the program
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
