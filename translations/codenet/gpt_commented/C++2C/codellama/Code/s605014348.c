#include <stdio.h>
#include <math.h>

// Function prototype for div
int div(int n);

int main() {
    int num; // Variable to store the input number
    scanf("%d", &num); // Read an integer from the user
    printf("%d:", num); // Output the initial number followed by a colon

    // Loop until num is reduced to 1
    while(num != 1) {
        // Find and output the smallest divisor of num
        printf(" %d", div(num));
        // Divide num by its smallest divisor
        num = num / div(num);
    }
    printf("\n"); // Print a newline at the end of output
}

// Function to find the smallest divisor of n
int div(int n) {
    // Check if n is even, return 2 if it is
    if(n % 2 == 0) return 2;

    // Calculate the square root of n for optimization
    int s = sqrt(n);
    
    // Check for odd divisors from 3 up to the square root of n
    for(int i = 3; i <= s; i += 2) {
        // If i is a divisor of n, return it
        if(n % i == 0) return i;
    }

    // If no divisors found, return n (n is prime)
    return n;
}

