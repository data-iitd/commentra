
#include <stdio.h> // Including the standard input/output library

int main() { // Defining the main function
    int a, b, c; // Declaring variables a, b, and c
    char input[100]; // Declaring an array to store input
    fgets(input, 100, stdin); // Reading input from the standard input
    sscanf(input, "%d %d", &a, &b); // Scanning the input and storing it in variables a and b
    c = a - b * 2; // Performing a mathematical operation to calculate a result
    if (c < 0) c = 0; // Checking if the result is negative and setting it to 0 if true
    printf("%d\n", c); // Printing the result to the standard output
    return 0; // Returning 0 to indicate successful execution
}

