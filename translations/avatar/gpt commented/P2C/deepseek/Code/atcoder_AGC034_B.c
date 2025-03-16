#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Ensure a is the larger and b is the smaller number
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    // Use the Euclidean algorithm to find GCD
    while (a % b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}

// Main function to solve the problem
void solve() {
    // Read input string
    char s[1000];
    scanf("%s", s);
    char t[1000] = "";  // Initialize an empty string to build the result
    int i = 0;   // Initialize index for traversing the input string

    // Process the input string character by character
    while (s[i] != '\0') {
        if (s[i] == 'A') {
            // If the character is 'A', add it to the result
            strncat(t, "A", 1);
            i++;  // Move to the next character
        } else if (s[i] == 'B') {
            // If the character is 'B', check the next character
            if (s[i + 1] != '\0') {
                if (s[i + 1] == 'C') {
                    // If the next character is 'C', add 'D' to the result
                    strncat(t, "D", 1);
                    i += 2;  // Skip the next character as well
                } else {
                    // If the next character is not 'C', add 'X' to the result
                    strncat(t, "X", 1);
                    i++;  // Move to the next character
                }
            } else {
                // If 'B' is the last character, add 'X' to the result
                strncat(t, "X", 1);
                i++;
            }
        } else {
            // For any other character, add 'X' to the result
            strncat(t, "X", 1);
            i++;
        }
    }

    int total = 0;  // Initialize total count
    int numA = 0;   // Initialize count of 'A's encountered

    // Calculate the total based on the processed string
    for (int j = 0; j < strlen(t); j++) {
        if (t[j] == 'X') {
            // Reset count of 'A's when 'X' is encountered
            numA = 0;
        } else {
            if (t[j] == 'A') {
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
}

// Entry point of the program
int main() {
    solve();
    return 0;
}
