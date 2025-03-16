#include <stdio.h>
#include <string.h>

int main() {
    // Declare a string variable to hold the input
<<<<<<< HEAD
    char s[100]; // Assuming the maximum length of the string is 99 characters
=======
    char s[100]; // Assuming the maximum length of the string is 99 characters + 1 for null terminator
>>>>>>> 98c87cb78a (data updated)
    
    // Read input string from the user
    scanf("%s", s);
    
    // Declare variables to store the positions of 'A' and 'Z'
    int a = -1, z = -1; // Initialize to -1 to indicate not found
    
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
    if (a != -1 && z != -1) { // Check if both 'A' and 'Z' were found
        printf("%d\n", z - a + 1);
    } else {
        printf("0\n"); // If either 'A' or 'Z' is not found, print 0
    }
    
    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
