#include <stdio.h>
#include <string.h>

int main() {
    // Declare a string variable to hold the input
    char s[100];
    
    // Read input string from the user
    scanf("%s", s);
    
    // Declare variables to store the positions of 'A' and 'Z'
    int a, z;
    
    // Loop through the string to find the first occurrence of 'A'
    for(int i = 0; i < strlen(s); i++) {
        if (s[i] == 'A') {
            a = i; // Store the index of 'A'
            break; // Exit the loop once 'A' is found
        }
    }
    
    // Loop through the string in reverse to find the last occurrence of 'Z'
    for(int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == 'Z') {
            z = i; // Store the index of 'Z'
            break; // Exit the loop once 'Z' is found
        }
    }
    
    // Calculate the number of characters between 'A' and 'Z' (inclusive) and print the result
    printf("%d\n", z - a + 1);
    
    // Return 0 to indicate successful completion of the program
    return 0;
}

