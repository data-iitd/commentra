#include <stdio.h> // Including standard input-output header
#include <stdlib.h> // Including standard library for atoi

// Function to find the greatest common divisor of two numbers
long getGCD(long a, long b) {
    if (b == 0) { // Base case: if b is 0, return a as the gcd
        return a;
    } else {
        return getGCD(b, a % b); // Recursive call: finding the gcd of b and the remainder of a divided by b
    }
}

int main() { // Starting the main function
    int n, m; // Declaring variables for n and m
    scanf("%d %d", &n, &m); // Reading the first two integers n and m from standard input
    int a[n]; // Creating an integer array a of size n

    // Initializing the array a with input values
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp); // Reading an integer value
        a[i] = temp / 2; // Dividing it by 2 before storing it in the array
    }

    long gcd; // Declaring a variable gcd to store the greatest common divisor
    long lcd = 1; // Declaring and initializing a variable lcm to store the least common multiple

    // Finding the least common multiple of all array elements
    for (int i = 0; i < n; i++) {
        gcd = getGCD(lcd, a[i]); // Finding the greatest common divisor of lcm and the current array element
        lcd = lcd * a[i] / gcd; // Updating the value of lcm

        // Checking if lcm is greater than m
        if (lcd > m) {
            printf("0\n"); // If true, printing 0 and returning from the function
            return 0;
        }
    }

    // Checking if any array element is a factor of lcm
    for (int i = 0; i < n; i++) {
        if ((lcd / a[i]) % 2 == 0) { // Checking if the remainder of lcm divided by the current array element is 0 and even
            printf("0\n"); // If true, printing 0 and returning from the function
            return 0;
        }
    }

    // Printing the result
    printf("%ld\n", (m / lcd + 1) / 2); // Printing the final result
    return 0; // Returning from the main function
}

// <END-OF-CODE>
