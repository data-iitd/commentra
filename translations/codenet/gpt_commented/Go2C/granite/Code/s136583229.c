
#include <stdio.h> // Include the standard input/output library

int main() {
    int data; // Declare an integer variable to hold the input value
    scanf("%d", &data); // Read an integer value from standard input and store it in 'data'
    
    int result = data * data * data; // Calculate the cube of the input value
    printf("%d\n", result); // Print the result to standard output
    
    return 0; // Return 0 to indicate successful execution
}
