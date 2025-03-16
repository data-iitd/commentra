
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Including header files for input/output operations and mathematical calculations

int main ( ) { 
    
    // Main function is the entry point of the program
    
    double input ; 
    double countOdd ; 
    double result ; 
    
    // Declaring variables to store input, number of odd numbers and result
    
    scanf ( "%lf" , &input ) ; 
    
    // Reading a double value from the input
    
    countOdd = round ( input / 2 ) ; 
    
    // Calculating the number of odd numbers up to the given input
    
    result = countOdd / input ; 
    
    // Using round function to round the result to 10 decimal places
    
    printf ( "%.10lf" , result ) ; 
    
    // Printing the result
    
    return 0 ; 
    
    // Returning 0 to indicate successful execution
    
}

