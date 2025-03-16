#include <stdio.h>
#include <string.h>

int main() {
    // Declare a variable to hold the input string
    char s[100]; // Assuming the input string will not exceed 99 characters
    
    // Read a string input from the user
    scanf("%s", s);
    
    // Initialize the answer variable with "No"
    char *ans = "No";
    
    // Find the first occurrence of 'C' and the last occurrence of 'F'
    char *firstC = strchr(s, 'C');
    char *lastF = strrchr(s, 'F');
    
    // Check if the first occurrence of 'C' is before the last occurrence of 'F'
    if (firstC != NULL && lastF != NULL && firstC < lastF) {
        // If true, set the answer to "Yes"
        ans = "Yes";
    }
    
    // Check if 'C' does not exist in the string
    if (firstC == NULL) {
        // If true, set the answer to "No"
        ans = "No";
    }
    
    // Print the final answer
    printf("%s\n", ans);
    
    return 0;
}

// <END-OF-CODE>
