#include <stdio.h>
#include <string.h>

int main() {
    char str[4][100]; // Declare an array to hold 4 strings
    int i = -1, u = -1, yes = 0; // Declare variables for the loops
    
    // Loop to read 4 strings from user input
    while (i != 3) {
        i = i + 1; // Increment index
        scanf("%s", str[i]); // Read a string and store it in the array
    }
    
    // Outer loop to iterate through the first 3 strings
    while (u != 2) {
        u = u + 1; // Increment outer index
        i = -1; // Reset inner index
        
        // Inner loop to check conditions on characters of the strings
        while (i != 2) {
            i = i + 1; // Increment inner index
            
            // Check if the characters in the strings meet the specified conditions
            if ((str[u][i] == str[u][i + 1] && 
                (str[u + 1][i] == str[u][i] || 
                 str[u + 1][i + 1] == str[u][i])) ) || 
                (str[u + 1][i] == str[u + 1][i + 1] && 
                (str[u][i] == str[u + 1][i] || 
                 str[u][i + 1] == str[u + 1][i])) ) {
                
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

