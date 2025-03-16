#include <stdio.h>      // Include standard input/output library
#include <stdlib.h>     // Include standard library for memory allocation
#include <string.h>     // Include string library for string manipulation

// Function to count the number of set bits in the binary representation of a number
int rec(long x) {
    int answer = 0;

    // Count the number of set bits
    for (int k = 31; k >= 0; k--) {
        if ((x & (1 << k)) != 0) // If the k-th bit is set
            answer++;             // Increment the answer
    }

    return answer; // Return the count of set bits
}

int main() {
    int n; // Number of test cases
    scanf("%d", &n); // Read the number of test cases

    // Initialize an array 'a' to store the frequency of each number
    int a[33] = {0}; // Array to hold frequencies, initialized to 0

    // Read each test case and update the frequency of the number in the array 'a'
    for (int i = 0; i < n; i++) {
        long num; // Variable to hold the number
        scanf("%ld", &num); // Read a number
        int index = rec(num); // Get the index of the number in the array 'a'
        a[index]++; // Increment the frequency of the number in the array 'a'
    }

    // Calculate the answer
    double answer = 0.0; // Variable to hold the final answer
    for (int i = 0; i < 33; i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1); // Calculate the sum of squares of numbers up to the current number
        answer += summ; // Add the sum to the answer
    }

    // Print the answer as a long integer
    printf("%ld\n", (long)answer); // Cast answer to long and print
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
