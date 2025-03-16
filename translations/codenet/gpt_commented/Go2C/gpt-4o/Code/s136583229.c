#include <stdio.h> // Include the standard I/O library

int main() {
    int data; // Declare a variable to hold the input integer
    scanf("%d", &data); // Read an integer value from standard input and store it in 'data'
    
    int result = data * data * data; // Calculate the cube of the input value
    printf("%d\n", result); // Print the result to standard output

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
