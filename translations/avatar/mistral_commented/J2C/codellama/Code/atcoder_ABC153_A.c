// Including necessary C libraries for reading input from the console and handling exceptions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function is the entry point of the C program
int main() {

    // Creating a character array to store the input from the console
    char str[100];

    // Reading a single line of input from the console and storing it in the character array 'str'
    fgets(str, 100, stdin);

    // Parsing the first two elements of the character array 'str' as integers 'h' and 'a' respectively
    int h = atoi(strtok(str, " "));
    int a = atoi(strtok(NULL, " "));

    // Initializing a variable 'num' to keep track of the number of steps
    int num = 0;

    // Using a for loop to simulate the given condition
    for (int i = 1; h > 0; i++) {

        // Subtracting 'a' from 'h' in each iteration
        h = h - a;

        // Incrementing the 'num' variable after each successful subtraction
        num++;
    }

    // Printing the final result 'num' to the console
    printf("%d\n", num);

    // Ending the C program with the comment "