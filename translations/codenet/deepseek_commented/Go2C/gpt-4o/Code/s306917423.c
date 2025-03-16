#include <stdio.h>

int main() {
    // Initialize a string variable to store the input
    char s[100]; // Assuming the input will not exceed 99 characters
    // Read input from the standard input and store it in the variable `s`
    scanf("%s", s);
    
    // Initialize a variable to count the number of '1's in the input string
    int ans = 0;
    // Iterate over each character in the string `s`
    for (int i = 0; s[i] != '\0'; i++) {
        // Check if the character is '1'
        if (s[i] == '1') {
            // Increment the count of '1's
            ans++;
        }
    }
    // Print the count of '1's to the standard output
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>
