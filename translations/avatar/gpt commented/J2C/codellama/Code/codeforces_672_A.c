#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a character array from the concatenation of numbers 1 to 1000
char* generateString() {
    char* str = (char*) malloc(1001 * sizeof(char)); // Allocating memory for the string
    int i;
    
    // Looping through numbers 1 to 1000 and appending them to the string
    for (i = 0; i < 1000; i++) {
        str[i] = (char) (i + 48); // Appending the current number to the string
    }
    
    // Terminating the string with a null character
    str[i] = '\0';
    
    // Returning the generated string
    return str;
}

int main() {
    int n; // Declaring an integer variable to store the user input
    
    // Reading an integer input from the user
    scanf("%d", &n);
    
    // Printing the character at the (n-1)th index of the generated character array
    printf("%c\n", generateString()[n - 1]);
    
    return 0;
}

