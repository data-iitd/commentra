#include <stdio.h> // Including header file for input and output operations
#include <stdlib.h> // Including header file for memory management
#include <string.h> // Including header file for string operations

int main() { // Defining the main function
    char a[100]; // Declaring a character array to store input
    scanf("%s", a); // Reading a line of input from the user
    char *p = strchr(a, ','); // Finding the first occurrence of ',' in the input string
    while (p != NULL) { // Looping until the end of the input string
        *p = ' '; // Replacing the ',' with a space
        p = strchr(p + 1, ','); // Finding the next occurrence of ',' in the input string
    }
    printf("%s\n", a); // Printing the manipulated string
    return 0; // Returning 0 to indicate successful execution
}
