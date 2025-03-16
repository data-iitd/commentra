
#include <stdio.h>
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
    int n; // Declare an integer variable for the length of the string
    scanf("%d", &n); // Read the integer input for the length of the string
    
    char s[n]; // Declare a character array to store the string input
    scanf("%s", s); // Read the string input
    
    char sb[n - 1]; // Declare a character array to store the new string
    int k = 0; // Initialize a variable to keep track of the index in the new string
    
    // Build a new string based on the absolute differences between adjacent characters
    for (int i = 1; i < n; i++) {
        sb[k++] = abs(s[i] - s[i - 1]); // Append the absolute difference to the new string
    }
    
    // Special case when the length of the string is 2
    if (n == 2) {
        printf("%c\n", sb[0]); // Print the first character of the new string
        return 0; // Exit the program
    }
    
    // Convert the character array to a string
    s[n - 1] = '\0'; // Add a null terminator to the end of the string
    
    // Check if the new string contains the character '1'
    if (strstr(sb, "1")) {
        printf("%d\n", cal(sb, '1')); // Calculate and print the result for character '1'
    } else {
        printf("%d\n", cal(sb, '2') * 2); // Calculate and print the result for character '2', multiplied by 2
    }
    
    return 0; // Return 0 to indicate successful execution
}

