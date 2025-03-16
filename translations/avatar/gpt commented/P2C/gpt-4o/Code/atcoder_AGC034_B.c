#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    // Ensure a is the larger and b is the smaller number
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    // Use the Euclidean algorithm to find GCD
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve() {
    char s[100000]; // Assuming the input string will not exceed 100000 characters
    scanf("%s", s); // Read input string
    char t[100000]; // Initialize an array to build the result
    int i = 0, j = 0; // Initialize indices for traversing the input string and result

    // Process the input string character by character
    while (s[i] != '\0') {
        if (s[i] == 'A') {
            // If the character is 'A', add it to the result
            t[j++] = 'A';
            i++; // Move to the next character
        } else if (s[i] == 'B') {
            // If the character is 'B', check the next character
            if (s[i + 1] != '\0') {
                if (s[i + 1] == 'C') {
                    // If the next character is 'C', add 'D' to the result
                    t[j++] = 'D';
                    i += 2; // Skip the next character as well
                } else {
                    // If the next character is not 'C', add 'X' to the result
                    t[j++] = 'X';
                    i++; // Move to the next character
                }
            } else {
                // If 'B' is the last character, add 'X' to the result
                t[j++] = 'X';
                i++;
            }
        } else {
            // For any other character, add 'X' to the result
            t[j++] = 'X';
            i++;
        }
    }
    t[j] = '\0'; // Null-terminate the result string

    int total = 0; // Initialize total count
    int numA = 0;  // Initialize count of 'A's encountered

    // Calculate the total based on the processed string
    for (i = 0; t[i] != '\0'; i++) {
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
}

int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
