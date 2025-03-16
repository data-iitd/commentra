#include<stdio.h>   // Include standard input/output library
#include<stdlib.h>  // Include standard library for general functions
#include<limits.h>  // Include limits library for data type limits
#include<math.h>    // Include math library for mathematical functions

public class Main {
    public static void main(String[] args) {
        int i, j, k, n; // Declare integer variables i, j, k, and n
        
        // Read an integer input from the user
        scanf("%d", &n);
        
        // Calculate and print the result based on the input n
        // The expression (24 + (24 - n)) simplifies to (48 - n)
        printf("%d\n", 24 + (24 - n));
        
        return 0; // Return 0 to indicate successful execution
    }
}

