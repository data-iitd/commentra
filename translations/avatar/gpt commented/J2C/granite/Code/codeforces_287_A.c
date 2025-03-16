
#include <stdio.h>
#include <string.h>

int main() {
    char str[4][3]; // Declare a 2D array to hold 4 strings of length 3
    int i, j, yes = 0; // Initialize variables
    
    // Loop to read 4 strings from user input
    for (i = 0; i < 4; i++) {
        scanf("%s", str[i]); // Read a string and store it in the array
    }
    
    // Outer loop to iterate through the first 3 strings
    for (i = 0; i < 3; i++) {
        // Inner loop to check conditions on characters of the strings
        for (j = 0; j < 2; j++) {
            // Check if the characters in the strings meet the specified conditions
            if ((str[i][j] == str[i][j + 1] && 
                (str[i + 1][j] == str[i][j] || 
                 str[i + 1][j + 1] == str[i][j])) ) || 
                (str[i + 1][j] == str[i + 1][j + 1] && 
                (str[i][j] == str[i + 1][j] || 
                 str[i][j + 1] == str[i + 1][j]))) ) {
                
                yes = 1; // Set flag to indicate a match was found
                printf("YES\n"); // Output "YES"
                break; // Exit the inner loop
            }
        }
        
        // If a match was found, exit the outer loop
        if (yes == 1) {
            break;
        }
    }
    
    // If no matches were found, output "NO"
    if (yes == 0) {
        printf("NO\n");
    }
    
    return 0;
}
