
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Ensure a is the larger and b is the smaller number
    a = a > b? a : b;
    b = a > b? b : a;
    // Use the Euclidean algorithm to find GCD
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Main function to solve the problem
int main() {
    // Read input string
    char s[100005];
    scanf("%s", s);
    char t[100005];  // Initialize an empty string to build the result
    int i = 0;        // Initialize index for traversing the input string

    // Process the input string character by character
    while (s[i]!= '\0') {
        if (s[i] == 'A') {
            // If the character is 'A', add it to the result
            t[i] = 'A';
            i++;  // Move to the next character
        } else if (s[i] == 'B') {
            // If the character is 'B', check the next character
            if (s[i + 1] == 'C') {
                // If the next character is 'C', add 'D' to the result
                t[i] = 'D';
                i += 2;  // Skip the next character as well
            } else {
                // If the next character is not 'C', add 'X' to the result
                t[i] = 'X';
                i++;  // Move to the next character
            }
        } else {
            // For any other character, add 'X' to the result
            t[i] = 'X';
            i++;
        }
    }
    t[i] = '\0';  // Null-terminate the result string

    int total = 0;  // Initialize total count
    int numA = 0;    // Initialize count of 'A's encountered

    // Calculate the total based on the processed string
    for (int i = 0; t[i]!= '\0'; i++) {
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

    return 0;
}

