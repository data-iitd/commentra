#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate a specific value based on the input string and character
int cal(const char *s, char c) {
    int n = strlen(s); // Get the length of the string
    int m = n - 1; // Calculate the last index of the string
    int ans = 0; // Initialize the answer variable

    // Iterate through each character in the string
    for (int i = 0; i < n; i++) {
        // Check if the current character matches 'c' and if the bitwise AND of m and i equals i
        if (s[i] == c && (m & i) == i) {
            ans ^= 1; // Toggle the answer using XOR operation
        }
    }
    return ans; // Return the final calculated answer
}

// Main logic to solve the problem
void solve() {
    int n;
    scanf("%d", &n); // Read the integer input for the length of the string
    char s[100001]; // Assuming the maximum length of the string is 100000
    scanf("%s", s); // Read the string input

    char sb[100001]; // String to hold the new string based on absolute differences
    int sb_index = 0; // Index for the new string

    // Build a new string based on the absolute differences between adjacent characters
    for (int i = 1; i < n; i++) {
        sb[sb_index++] = abs(s[i] - s[i - 1]) + '0'; // Append the absolute difference as a character
    }
    sb[sb_index] = '\0'; // Null-terminate the new string

    // Special case when the length of the string is 2
    if (n == 2) {
        printf("%c\n", sb[0]); // Print the first character of the new string
        return; // Exit the function
    }

    // Check if the new string contains the character '1'
    if (strchr(sb, '1')) {
        printf("%d\n", cal(sb, '1')); // Calculate and print the result for character '1'
    } else {
        printf("%d\n", cal(sb, '2') * 2); // Calculate and print the result for character '2', multiplied by 2
    }
}

// Main method to execute the program
int main() {
    solve(); // Call the solve function
    return 0; // Return success
}

// <END-OF-CODE>
