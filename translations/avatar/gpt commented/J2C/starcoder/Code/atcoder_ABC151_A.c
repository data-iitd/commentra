#include <stdio.h>
#include <stdlib.h>

// Function to perform modular addition
long sum(long a, long b, long module) { 
    return (a + b + module) % module; 
} 

// Function to perform modular subtraction
long sub(long a, long b, long module) { 
    return (a - b + module) % module; 
} 

// Function to perform modular multiplication
long prod(long a, long b, long module) { 
    return (a * b) % module; 
} 

// Function to perform modular division
long div(long a, long b, long module) { 
    return (a * inv(b, module)) % module; 
} 

// Function to compute the modular inverse using the Extended Euclidean Algorithm
long inv(long a, long module) { 
    long b = module; 
    long u = 1; 
    long v = 0; 
    
    // Extended Euclidean Algorithm to find the inverse
    while (b > 0) { 
        long t = a / b; 
        a -= t * b; 
        u -= t * v; 
        long z = a; 
        a = b; 
        b = z; 
        z = u; 
        u = v; 
        v = z; 
    } 
    
    // Ensure the result is positive
    u %= module; 
    if (u < 0) u += module; 
    
    // Return the modular inverse
    return u; 
} 

// Function to read a line of input from the user
char* readLine() { 
    char* line = NULL; 
    size_t len = 0; 
    ssize_t read; 
    
    read = getline(&line, &len, stdin); 
    if (read == -1) { 
        exit(EXIT_FAILURE); 
    } 
    
    return line; 
} 

// Function to output the next character in the ASCII sequence of the first character of the input
void printNextChar(char* line) { 
    printf("%c", line[0] + 1); 
} 

// Main function
int main(int argc, char** argv) { 
    // Declare a string to hold the input
    char* line; 
    
    // Read a line of input from the user
    line = readLine(); 
    
    // Output the next character in the ASCII sequence of the first character of the input
    printNextChar(line); 
    
    // Free the memory allocated to the string
    free(line); 
    
    return 0; 
} 

