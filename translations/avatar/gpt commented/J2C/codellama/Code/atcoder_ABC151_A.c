#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Class to perform operations in a modular arithmetic system
struct RemRing { 
    long module; // Variable to store the modulus value 

    // Constructor to initialize the modulus
    struct RemRing(long module) { 
        this->module = module; 
    } 

    // Method to perform modular addition
    long sum(long a, long b) { 
        return (a + b + this->module) % this->module; 
    } 

    // Method to perform modular subtraction
    long sub(long a, long b) { 
        return (a - b + this->module) % this->module; 
    } 

    // Method to perform modular multiplication
    long prod(long a, long b) { 
        return (a * b) % this->module; 
    } 

    // Method to perform modular division
    long div(long a, long b) { 
        return (a * inv(b)) % this->module; 
    } 

    // Method to compute the modular inverse using the Extended Euclidean Algorithm
    long inv(long a) { 
        long b = this->module; 
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
        u %= this->module; 
        if (u < 0) u += this->module; 
        
        // Return the modular inverse
        return u; 
    } 
};

// Main function to read input from the console
int main() { 
    // Create a BufferedReader to read input from the console
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1); 
    
    // Declare a string to hold the input
    String s; 
    
    // Read a line of input from the user
    s = r.readLine(); 
    
    // Output the next character in the ASCII sequence of the first character of the input
    printf("%c", s.charAt(0) + 1); 
    
    // End of code
    return 0; 
} 


