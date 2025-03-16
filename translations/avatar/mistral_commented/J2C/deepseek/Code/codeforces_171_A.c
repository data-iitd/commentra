#include <stdio.h>
#include <stdlib.h>

// Function for reversing a number
int reverse(int n) {
    // Base case for numbers less than 10
    if (n < 10)
        return n * 10;

    // Initializing variables
    int t = n, r = 0;

    // Reversing the number
    while (t > 0) {
        // Adding the digit to the reversed number
        r = (r * 10) + t % 10;

        // Moving to the next digit
        t = t / 10;
    }

    // Returning the reversed number
    return r;
}

// Main method
int main() {
    // Reading input for number of test cases
    int n, m;
    scanf("%d %d", &n, &m);

    // Calling reverse function for m and adding it to n
    int t = reverse(m);
    printf("%d\n", t + n);

    return 0;
}
