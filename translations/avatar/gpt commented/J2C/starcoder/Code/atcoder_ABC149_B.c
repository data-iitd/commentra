#include <stdio.h>

int main() {
    // Declare variables to hold the values of A, B, K, and the results x, y
    long A, B, K; 
    long x, y; 

    // Set up input reading from standard input with UTF-8 encoding
    setbuf(stdin, NULL); 
    
    // Read a line of input, split it into tokens, and parse them as long integers
    scanf("%ld %ld %ld", &A, &B, &K); 
    
    // Perform calculations based on the input values
    x = A - K; 
    if (x < 0) {
        y = B + x; 
        x = 0; 
        if (y < 0) {
            y = 0; 
        } 
    } 
    
    // Display the results of the calculations
    printf("%ld %ld\n", x, y); 
    
    return 0; 
}

