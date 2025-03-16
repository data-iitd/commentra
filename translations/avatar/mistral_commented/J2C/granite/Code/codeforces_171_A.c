
#include <stdio.h>

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
    // Creating an instance of FastReader
    int n, m, t;

    // Reading input for number of test cases
    scanf("%d", &n);

    // Reading input for number of operations
    scanf("%d", &m);

    // Calling reverse function for m and adding it to n
    t = reverse(m);
    printf("%d\n", t + n);

    return 0;
}

