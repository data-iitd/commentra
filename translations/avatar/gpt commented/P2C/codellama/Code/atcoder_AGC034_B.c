
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

// Function to compute the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Ensure a is the larger and b is the smaller number
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    // Use the Euclidean algorithm to find GCD
    while (b > 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Main function to solve the problem
int main() {
    // Read input string
    char s[100000];
    scanf("%s", s);
    int len = strlen(s);
    char t[100000];
    int i = 0;
    int j = 0;

    // Process the input string character by character
    while (i < len) {
        if (s[i] == 'A') {
            // If the character is 'A', add it to the result
            t[j] = 'A';
            j++;
            i++;
        } else if (s[i] == 'B') {
            // If the character is 'B', check the next character
            if (i < len - 1) {
                if (s[i + 1] == 'C') {
                    // If the next character is 'C', add 'D' to the result
                    t[j] = 'D';
                    j++;
                    i += 2;
                } else {
                    // If the next character is not 'C', add 'X' to the result
                    t[j] = 'X';
                    j++;
                    i++;
                }
            } else {
                // If 'B' is the last character, add 'X' to the result
                t[j] = 'X';
                j++;
                i++;
            }
        } else {
            // For any other character, add 'X' to the result
            t[j] = 'X';
            j++;
            i++;
        }
    }
    t[j] = '\0';

    int total = 0;
    int numA = 0;

    // Calculate the total based on the processed string
    for (i = 0; i < j; i++) {
        if (t[i] == 'X') {
            // Reset count of 'A's when 'X' is encountered
            numA = 0;
        } else {
            if (t[i] == 'A') {
                // Increment count of 'A's
                numA++;
            } else {
                // If the character is not 'A', add the count of 'A's to total
                total += numA;
            }
        }
    }

    // Print the final total
    printf("%d\n", total);

    // Define constants (not used further in the code)
    const int INF = 1000000000;
    const int mod = 7 + 1000000007;
    return 0;
}

