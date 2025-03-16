#include <stdio.h>  // For standard input and output
#include <string.h> // For string manipulation

// Function to solve the problem
void solve() {
    char s[100]; // Buffer to hold the input string

    // Read the input string
    scanf("%s", s);

    // Check if the string contains both 'A' and 'B'
    if (strchr(s, 'A') != NULL && strchr(s, 'B') != NULL) {
        printf("Yes\n"); // Print "Yes" if both characters are present
    } else {
        printf("No\n"); // Print "No" if either character is missing
    }
}

// Main function to start the program
int main() {
    solve(); // Call the solve function
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
