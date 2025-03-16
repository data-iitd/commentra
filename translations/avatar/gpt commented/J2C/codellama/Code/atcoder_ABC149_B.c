#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Declare variables to hold the values of A, B, K, and the results x, y
long A, B, K; 
long x, y; 

int main(void) {
    // Set up input reading from standard input with UTF-8 encoding
    setlocale(LC_ALL, "en_US.UTF-8"); 
    // Create an instance of Main class and pass the BufferedReader for input
    Main ins = new Main(stdin); 
    
    // Perform calculations based on the input values
    ins.calc(); 
    
    // Display the results of the calculations
    ins.showResult(); 
    
    return 0; 
} 

// Constructor to read input values A, B, and K from the BufferedReader
Main(FILE *in) {
    // Read a line of input, split it into tokens, and parse them as long integers
    char *line = NULL; 
    size_t len = 0; 
    ssize_t read; 
    char *token; 
    char *saveptr; 
    
    read = getline(&line, &len, in); 
    token = strtok_r(line, " ", &saveptr); 
    A = strtol(token, NULL, 10); 
    token = strtok_r(NULL, " ", &saveptr); 
    B = strtol(token, NULL, 10); 
    token = strtok_r(NULL, " ", &saveptr); 
    K = strtol(token, NULL, 10); 
    
    free(line); 
} 

// Method to perform the main calculation based on A, B, and K
void calc() {
    // Initialize x with the value of A and y with the value of B
    x = A; 
    y = B; 
    
    // Subtract K from A and assign the result to x
    x = A - K; 
    
    // Check if the result x is negative
    if (x < 0) {
        // If x is negative, adjust y by adding the negative value of x to B
        y = B + x; 
        // Set x to 0 since it cannot be negative
        x = 0; 
        
        // Ensure y is not negative
        if (y < 0) {
            y = 0; 
        } 
    } 
} 

// Method to display the results of the calculations
void showResult() {
    // Print the values of x and y
    printf("%ld %ld\n", x, y); 
} 

