#include <stdio.h>
#include <stdlib.h>

// Function to read an integer as input
int scanInt() {
    int num;
    scanf("%d", &num); // Read the next token as an integer
    return num;        // Return the integer
}

// Function to read a string as input
char* scanString() {
    char *str = (char*)malloc(100 * sizeof(char)); // Allocate memory for a string
    scanf("%s", str); // Read the next token as a string
    return str;       // Return the string
}

// Function to read an array of integers as input
int* scanInts(int n) {
    int *sl = (int*)malloc(n * sizeof(int)); // Allocate memory for an array of n integers
    for (int i = 0; i < n; i++) {           // Iterate through each index of the array
        sl[i] = scanInt();                 // Read and store an integer at the current index
    }
    return sl;                            // Return the array
}

// Function to read an array of strings as input
char** scanStrings(int n) {
    char** sl = (char**)malloc(n * sizeof(char*)); // Allocate memory for an array of n strings
    for (int i = 0; i < n; i++) {                 // Iterate through each index of the array
        sl[i] = scanString();                    // Read and store a string at the current index
    }
    return sl;                                  // Return the array
}

// Main function to execute the program
int main() {
    // Read the first three integers as input
    int r = scanInt();
    int D = scanInt();
    int x = scanInt();

    // Iterate through a loop 10 times
    for (int i = 1; i <= 10; i++) {
        // Calculate the new value of x using the given formula
        x = r * x - D;

        // Print the value of x to the console
        printf("%d\n", x);
    }

    return 0;
}
