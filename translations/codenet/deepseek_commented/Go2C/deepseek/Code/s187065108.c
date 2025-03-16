#include <stdio.h>
#include <stdlib.h>

// Function to read a single word from input
char* readString() {
    char* str = (char*)malloc(100 * sizeof(char)); // Allocate memory for the string
    scanf("%s", str);
    return str;
}

// Function to convert a string to an integer
int readInt() {
    char* str = readString();
    int num = atoi(str);
    free(str); // Free the allocated memory
    return num;
}

// Main function to execute the program
int main() {
    // Read initial values for r, D, and x
    int r = readInt();
    int D = readInt();
    int x = readInt();
    
    // Loop to calculate and print the values of x for 10 iterations
    for (int i = 1; i <= 10; i++) {
        x = r * x - D;
        printf("%d\n", x);
    }
    
    return 0;
}
