#include <stdio.h> 
#include <stdlib.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int A, B, amari, result; 
    scanf("%d %d", &A, &B); 
    
    // Read two integers A and B from the input
    // int A = Integer.parseInt(sc.next()); 
    // int B = Integer.parseInt(sc.next()); 
    
    // Initialize variables to hold the remainder and the result
    // int amari = 0; 
    // int result = 0; 
    
    // Calculate the initial result based on the formula (B - 1) / (A - 1)
    result = (B - 1) / (A - 1); 
    
    // Calculate the remainder when (B - 1) is divided by (A - 1)
    amari = (B - 1) % (A - 1); 
    
    // If there is a remainder, increment the result by 1
    if (amari != 0) { 
        result += 1; 
    } 
    
    // Create a PrintWriter object to output the result
    // PrintWriter out = new PrintWriter(System.out); 
    
    // Print the final result to the console
    printf("%d\n", result); 
    
    // Close the Scanner to free resources
    // sc.close(); 
    
    // Flush the PrintWriter to ensure all output is written
    // out.flush(); 
    
    return 0; 
} 

