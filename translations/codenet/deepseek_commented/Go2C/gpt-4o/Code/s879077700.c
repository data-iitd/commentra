#include <stdio.h>
#include <string.h>

int main() {
    // Declare a string variable to store the input
    char a[100]; // Assuming the input will not exceed 99 characters
    // Read a string input from the user and store it in `a`
    scanf("%s", a);
    
    // Initialize the variable `ans` with the value "Good"
    char ans[] = "Good";
    
    // Loop through the first three characters of the string `a`
    for (int i = 0; i < 3; i++) {
        // Check if the current character is the same as the next character
        if (a[i] == a[i + 1]) {
            // If the condition is true, change the value of `ans` to "Bad"
            strcpy(ans, "Bad");
            break; // No need to check further if we already found a match
        }
    }
    
    // Print the value of `ans`
    printf("%s\n", ans);
    
    return 0;
}

// <END-OF-CODE>
