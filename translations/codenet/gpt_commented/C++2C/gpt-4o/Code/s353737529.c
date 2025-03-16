#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Direction vectors for moving in 4 directions (up, right, down, left)
int dy[4] = {-1, 0, +1, 0};
int dx[4] = {0, +1, 0, -1};

<<<<<<< HEAD
// Constants for infinity and modulo operations
=======
// Constants for infinity
>>>>>>> 98c87cb78a (data updated)
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;

// Function to compute the greatest common divisor (GCD) using recursion
int gcd(int a, int b) {
    if (b == 0) return a; // Base case: if b is 0, return a
    return gcd(b, a % b); // Recursive case
}

//-----------------------ここから-----------

int main(void) {
    int n; // Variable to hold the input number

    // Read an integer from standard input
    scanf("%d", &n);

    // Initialize an empty string to hold the binary representation
    char s[64]; // Assuming a maximum of 64 bits for the binary representation
    int index = 0; // Index for the string

    // Special case: if the input number is 0, output '0' and exit
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    // Loop to convert the number to its binary representation in a specific format
    while (n != 0) {
        // Check if the current number is even or odd
        if (n % 2 == 0) {
            s[index++] = '0'; // Append '0' for even numbers
        } else {
            s[index++] = '1'; // Append '1' for odd numbers
        }

        // Adjust the number for the next iteration
        n -= abs(n % 2); // Reduce n by 1 if it's odd
        n /= -2; // Divide n by -2 to continue the conversion
    }

    // Reverse the string to get the correct binary representation
    for (int i = 0; i < index / 2; i++) {
        char temp = s[i];
        s[i] = s[index - 1 - i];
        s[index - 1 - i] = temp;
    }
<<<<<<< HEAD

    // Null-terminate the string
    s[index] = '\0';
=======
    s[index] = '\0'; // Null-terminate the string
>>>>>>> 98c87cb78a (data updated)

    // Output the final binary string
    printf("%s\n", s);

    return 0;
}
