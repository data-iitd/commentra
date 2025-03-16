#include <stdio.h> // Standard Input/Output Library
#include <string.h> // String Library

char str[21]; // Declare and initialize a character array named 'str' with a size of 21
int i, len; // Declare and initialize two integer variables named 'i' and 'len'

int main()
{
    printf("Enter a string: "); // Prompt the user to enter a string
    scanf("%s",str); // Read a string from the standard input and store it in the 'str' array

    len = strlen(str); // Calculate the length of the string stored in the 'str' array and assign it to the 'len' variable

    printf("Reversed string: "); // Print a message to indicate that the reversed string will be printed

    for(i = len-1; i >= 0; i--){ // Use a for loop to print each character of the string in reverse order
        putchar(str[i]); // Print the character at the index 'i' of the 'str' array
    }

    printf("\n"); // Print a newline character
    return 0; // Indicate successful execution
}