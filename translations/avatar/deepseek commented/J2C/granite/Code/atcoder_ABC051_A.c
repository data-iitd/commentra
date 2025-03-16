
#include <stdio.h> // Including standard input/output library
#include <string.h> // Including string manipulation library

int main() { // Defining the main function
    char input[100]; // Declaring a character array to store input
    fgets(input, 100, stdin); // Reading a line of input from the user and storing it in the input array
    char *token = strtok(input, ","); // Tokenizing the input string using comma as the delimiter
    while (token!= NULL) { // Iterating through each token in the input string
        printf("%s ", token); // Printing each token followed by a space
        token = strtok(NULL, ","); // Retrieving the next token in the input string
    }
    printf("\n"); // Printing a new line after printing all tokens
    return 0; // Returning 0 to indicate successful execution of the program
}

