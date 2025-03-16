#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cal(char *s, char c) {
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

int main() {
    int n;
    scanf("%d", &n); // Read the integer input for the length of the string
    char s[n + 1];
    scanf("%s", s); // Read the string input
    char *sb = malloc(n * sizeof(char)); // Initialize a character array to build the new string
    
    // Build a new string based on the absolute differences between adjacent characters
    for (int i = 1; i < n; i++) {
        sb[i] = abs(s[i] - s[i - 1]); // Append the absolute difference
    }
    
    // Special case when the length of the string is 2
    if (n == 2) {
        printf("%c", sb[0]); // Print the first character of the new string
        return 0; // Exit the program
    }
    
    // Convert the character array to a string
    s = sb; 
    
    // Check if the new string contains the character '1'
    if (strstr(s, "1")) {
        printf("%d", cal(s, '1')); // Calculate and print the result for character '1'
    } else {
        printf("%d", cal(s, '2') * 2); // Calculate and print the result for character '2', multiplied by 2
    }
    return 0;
}

