

#include <stdio.h>

int main ( ) { 
    int VP, VD, T, F, C ; 
    scanf ( "%d %d %d %d %d", &VP, &VD, &T, &F, &C ) ; // Read the input values for VP, VD, T, F, and C
    
    if ( VD <= VP ) { 
        printf ( "0" ) ; // If the thief's speed is not greater than the police's speed, print 0 and exit
        return 0 ; 
    } 
    
    int answer = 0 ; // Initialize the answer variable to 0
    int start = T ; // Initialize the start variable to the initial head start time (T)
    
    while ( true ) { 
        double x = ( double ) start * VP / ( VD - VP ) ; // Calculate the distance covered by the police car in one unit of time
        
        if ( ( start + x ) * VP >= C ) { 
            break ; // If the total distance covered by the police car is greater than or equal to C, break the loop
        } 
        
        start += 2 * x + F ; // Update the start variable by adding the distance covered and the refueling time
        answer ++ ; // Increment the answer variable by 1
    } 
    
    printf ( "%d", answer ) ; // Print the final value of answer
    
    return 0 ; // End the program
}

