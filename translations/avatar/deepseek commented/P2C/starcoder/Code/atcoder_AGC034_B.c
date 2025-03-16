#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    a = (a > b)? a : b;
    b = (a < b)? a : b;
    while (a % b > 0) {
        a = b;
        b = a % b;
    }
    return b;
}

// Main function to solve the problem
int main() {
    char s[100000];  // Read input string
    scanf("%s", s);
    char t[100000];  // Initialize an empty string to store processed characters
    int i = 0;  // Initialize index
    
    // Process the input string character by character
    while (i < strlen(s)) {
        if (s[i] == 'A') {
            t[i] = 'A';
            i++;
        } else if (s[i] == 'B') {
            if (i < strlen(s) - 1) {
                if (s[i + 1] == 'C') {
                    t[i] = 'D';
                    i += 2;
                } else {
                    t[i] = 'X';
                    i++;
                }
            } else {
                t[i] = 'X';
                i++;
            }
        } else {
            t[i] = 'X';
            i++;
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
                numA++;
            } else {
                total += numA;
            }
        }
    }
    
    printf("%d\n", total);  // Print the total count
    
    // Define constants for infinity and modulo
    int INF = 1000000000;
    int mod = 7 + 1000000000;
    
    return 0;
}

