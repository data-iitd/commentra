#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

// Function to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Main function to solve the problem
int main() {
    char *s = NULL;  // Read input string
    char *t = NULL;  // Initialize an empty string to store processed characters
    int i = 0;  // Initialize index
    
    // Process the input string character by character
    while (i < strlen(s)) {
        if (s[i] == 'A') {
            t += "A";
            i += 1;
        } else if (s[i] == 'B') {
            if (i < strlen(s) - 1) {
                if (s[i + 1] == 'C') {
                    t += "D";
                    i += 2;
                } else {
                    t += "X";
                    i += 1;
                }
            } else {
                t += "X";
                i += 1;
            }
        } else {
            t += "X";
            i += 1;
        }
    }
    
    int total = 0;  // Initialize total count
    int numA = 0;  // Initialize count of 'A' characters
    
    // Count the number of 'A' characters before each 'X' in the processed string
    for (i = 0; i < strlen(t); i++) {
        if (t[i] == 'X') {
            numA = 0;
        } else {
            if (t[i] == 'A') {
                numA += 1;
            } else {
                total += numA;
            }
        }
    }
    
    printf("%d\n", total);  // Print the total count
    
    // Define constants for infinity and modulo
    const int INF = 10 ** 25;
    const int mod = 7 + 10 ** 9;
    
    return 0;
}

