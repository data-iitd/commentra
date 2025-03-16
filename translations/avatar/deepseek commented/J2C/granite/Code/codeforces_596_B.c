

#include <stdio.h> // Step 1: Include the necessary C standard library headers.
int main ( void ) { // Step 2: Define the main function.
    int n ; // Step 3: Declare the variables needed to read input from the user.
    scanf ( "%d", & n ) ; // Step 4: Read the size of the array from the user.
    long arr [ n ] ; // Step 5: Declare an array to store the elements of the array.
    for ( int i = 0 ; i < n ; i ++ ) { // Step 6: Read the elements of the array from the user.
        scanf ( "%ld", & arr [ i ] ) ; 
    }
    long answer =labs ( arr [ 0 ] ) ; // Step 7: Initialize a variable to store the answer.
    for ( int i = 1 ; i < n ; i ++ ) { // Step 8: Calculate the absolute difference between consecutive elements and add it to the answer.
        answer +=labs ( arr [ i ] - arr [ i - 1 ] ) ; 
    }
    printf ( "%ld", answer ) ; // Step 9: Print the final answer.
    return 0 ; // Step 10: Return 0 to indicate successful program execution.
}
