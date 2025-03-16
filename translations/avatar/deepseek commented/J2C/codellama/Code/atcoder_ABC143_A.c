#include <stdio.h> // Including the standard input/output library
#include <stdlib.h> // Including the standard library for input/output operations
#include <string.h> // Including the string library for string operations

int main() { // Defining the main function
    char input[100]; // Declaring a character array to store input
    int a, b, c; // Declaring three integer variables
    scanf("%s", input); // Reading input into the character array
    sscanf(input, "%d %d", &a, &b); // Parsing the input string and storing the values in the variables
    c = a - b * 2; // Performing a mathematical operation to calculate a result
    if (c < 0) c = 0; // Checking if the result is negative and setting it to 0 if true
    printf("%d\n", c); // Printing the result to the standard output
    return 0; // Returning 0 to indicate successful execution
}
