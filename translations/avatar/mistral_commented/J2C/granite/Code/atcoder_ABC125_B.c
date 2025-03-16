

#include <stdio.h> // Including the standard input/output library
#include <stdlib.h> // Including the standard library for memory allocation and other functions

int main() { // Defining the main function that is executed when the program is run
    int n; // Declaring the variable n to store the number of elements in the arrays
    char vStr[1000]; // Declaring the character array vStr to store the string representation of the values array
    char cStr[1000]; // Declaring the character array cStr to store the string representation of the costs array
    int vList[1000]; // Declaring the integer array vList to store the values array
    int cList[1000]; // Declaring the integer array cList to store the costs array
    int max = 0; // Initializing the variable max to 0

    scanf("%d", &n); // Reading the number of elements in the arrays from the standard input stream
    scanf("%s", vStr); // Reading the string representation of the values array from the standard input stream
    scanf("%s", cStr); // Reading the string representation of the costs array from the standard input stream

    int i = 0; // Declaring the variable i to iterate through the arrays
    char *token = strtok(vStr, " "); // Tokenizing the string representation of the values array using the space character as a delimiter
    while (token!= NULL) { // Iterating through each token in the string using a while loop
        vList[i] = atoi(token); // Converting each token to an integer and storing it in the vList array
        token = strtok(NULL, " "); // Getting the next token in the string
        i++; // Incrementing the index variable i for the next iteration
    }

    i = 0; // Resetting the index variable i to 0
    token = strtok(cStr, " "); // Tokenizing the string representation of the costs array using the space character as a delimiter
    while (token!= NULL) { // Iterating through each token in the string using a while loop
        cList[i] = atoi(token); // Converting each token to an integer and storing it in the cList array
        token = strtok(NULL, " "); // Getting the next token in the string
        i++; // Incrementing the index variable i for the next iteration
    }

    for (i = 0; i < n; i++) { // Iterating through each element in the arrays using a for loop
        int profit = vList[i] - cList[i]; // Calculating the profit for the current element by subtracting the cost from the value
        if (profit > 0) { // Checking if the profit is positive
            max += profit; // If the profit is positive, adding it to the max variable
        }
    }

    printf("%d", max); // Printing the maximum profit to the standard output stream

    return 0; // Returning 0 to indicate successful execution of the program
}



Translate the above C code to Python and end with comment "