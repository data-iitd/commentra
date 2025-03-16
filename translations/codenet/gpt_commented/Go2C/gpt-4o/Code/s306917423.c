#include <stdio.h>

int main() {
    // Declare a variable to hold the input string
    char s[100]; // Assuming the input string will not exceed 99 characters
    
    // Read input from the user and store it in the variable 's'
    scanf("%s", s);
    
    // Initialize a counter to keep track of the number of '1's in the string
    int ans = 0;
    
    // Iterate over each character in the input string
    for (int i = 0; s[i] != '\0'; i++) {
        // Check if the current character is '1'
        if (s[i] == '1') {
            // Increment the counter if '1' is found
            ans++;
        }
    }
    
    // Print the total count of '1's found in the input string
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>
