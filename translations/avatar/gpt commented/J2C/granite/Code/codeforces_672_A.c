
#include <stdio.h> // Including the standard input/output library

// Function to generate a character array from the concatenation of numbers 1 to 1000
char* generateString() {
    char* str = (char*)malloc(1001 * sizeof(char)); // Allocating memory for the string
    int index = 0; // Index variable to keep track of the current position in the string
    
    // Looping through numbers 1 to 1000 and appending them to the string
    for (int i = 1; i <= 1000; i++) {
        sprintf(str + index, "%d", i); // Converting the current number to a string and appending it to the string
        index += sprintf(str + index, "%d", i); // Incrementing the index by the length of the appended string
    }
    
    return str; // Returning the generated string
}

int main() {
    int n; // Variable to store the user input
    
    // Reading an integer input from the user
    scanf("%d", &n);
    
    // Printing the character at the (n-1)th index of the generated string
    printf("%c\n", generateString()[n - 1]);
    
    free(generateString()); // Freeing the memory allocated for the string
    
    return 0; // Returning 0 to indicate successful execution
}

