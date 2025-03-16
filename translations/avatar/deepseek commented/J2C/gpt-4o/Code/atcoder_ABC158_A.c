#include <stdio.h>
#include <string.h>

// Function to check if both 'A' and 'B' are present in the string
void solve(const char *s) {
    if (strchr(s, 'A') != NULL && strchr(s, 'B') != NULL) { // Check for 'A' and 'B'
        printf("Yes\n"); // Print "Yes" if both are found
    } else {
        printf("No\n"); // Print "No" if either is missing
    }
}

int main() {
    char s[100]; // Declare a string to hold the input
    scanf("%s", s); // Read the input string from the console
    solve(s); // Call the solve function with the input string
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
