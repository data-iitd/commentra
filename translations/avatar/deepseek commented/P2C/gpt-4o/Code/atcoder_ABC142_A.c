#include <stdio.h>

int next_int() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    // Read the value of n from input
    int n = next_int();

    // Initialize a counter to keep track of odd numbers
    int t = 0;

    // Loop through each number from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Check if the current index plus one is odd
        if ((i + 1) & 1) {
            // Increment the counter if the condition is true
            t++;
        }
    }

    // Calculate the ratio of odd numbers to the total numbers and print it
    printf("%f\n", (double)t / n);

    return 0;
}

// <END-OF-CODE>
