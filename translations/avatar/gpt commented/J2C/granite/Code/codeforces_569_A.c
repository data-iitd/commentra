
#include <stdio.h> // Include the standard input/output library

int main() {
    int T, S, q; // Declare the variables T, S, and q as integers
    
    // Read three integers from the input: T, S, and q
    scanf("%d %d %d", &T, &S, &q); // Use the scanf function to read input from the console
    
    long previous = S; // Initialize 'previous' with the starting value S
    int answer = 0; // Initialize the answer counter
    
    // Loop until 'previous' is less than 'T'
    while (previous < T) {
        answer++; // Increment the answer counter
        previous *= q; // Multiply 'previous' by 'q' for the next iteration
    }
    
    // Output the final count of how many times 'previous' was multiplied before reaching 'T'
    printf("%d\n", answer); // Use the printf function to output the answer to the console
    
    return 0; // Return 0 to indicate successful program execution
}
