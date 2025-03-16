// Including necessary C libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function is the entry point of the C program
int main() {
    // Creating a buffer to read input from the console
    char buffer[100];

    // Reading a line of input from the console and storing it in the buffer
    fgets(buffer, 100, stdin);

    // Splitting the input string into an array of strings using space as delimiter
    char *x[100];
    x = strtok(buffer, " ");

    // Parsing the first and second elements of the input array into integers 'a' and 'b' respectively
    int a = atoi(x[0]);
    int b = atoi(x[1]);

    // Calculate the value of 'c' by subtracting 'b' multiplied by 2 from 'a'
    int c = a - b * 2;

    // If the value of 'c' is negative, set it to zero
    if (c < 0) {
        c = 0;
    }

    // Print the value of 'c' to the console
    printf("%d\n", c);

    // End of code
    return 0;
}


