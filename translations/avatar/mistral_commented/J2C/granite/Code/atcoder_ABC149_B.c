

#include <stdio.h> // Including necessary C standard library headers
#include <stdlib.h>
#include <string.h>

int main() {
    long A, B, K; // Declaring variables A, B, and K of type long
    long x, y; // Declaring variables x and y of type long

    char input[1024]; // Declaring a character array named input with a maximum length of 1024 characters
    fgets(input, 1024, stdin); // Reading a line of input from the standard input and storing it in the input array

    char *token = strtok(input, " "); // Tokenizing the input array using the space character as a delimiter
    A = atol(token); // Converting the first token to a long value and assigning it to variable A

    token = strtok(NULL, " "); // Retrieving the next token from the input array
    B = atol(token); // Converting the second token to a long value and assigning it to variable B

    token = strtok(NULL, " "); // Retrieving the next token from the input array
    K = atol(token); // Converting the third token to a long value and assigning it to variable K

    x = A; // Assigning the value of A to x
    y = B; // Assigning the value of B to y

    x = A - K; // Subtracting K from A and assigning the result to x

    if (x < 0) { // Checking if x is negative
        y = B + x; // If x is negative, adding the absolute value of x to B and assigning the result to y
        x = 0; // Setting x to zero
    }

    if (y < 0) { // Checking if y is negative
        y = 0; // If y is negative, setting it to zero
    }

    printf("%ld %ld\n", x, y); // Printing the values of x and y separated by a space character

    return 0; // Returning 0 to indicate successful execution of the program
}

Translate the above C code to Python and end with comment "