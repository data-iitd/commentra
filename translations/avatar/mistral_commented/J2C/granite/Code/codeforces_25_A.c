
#include <stdio.h>  // Include the header file for input/output operations

int main ( void ) {  // Main function to start the program
    int n ;  // Declare a variable to store the number of elements in the array
    printf ( "Enter the number of elements in the array: " ) ;  // Prompt the user to enter the number of elements
    scanf ( "%d", &n ) ;  // Read the number of elements from user input

    int array [ n + 1 ] ;  // Declare an array of size n+1 to store the input elements

    // Read the elements of the array from user input
    for ( int i = 1 ; i <= n ; i ++ ) {
        printf ( "Enter element %d: ", i ) ;
        scanf ( "%d", &array [ i ] ) ;  // Read the i-th element of the array
    }

    int odd = 0, even = 0, odd_ind = 0, even_ind = 0 ;  // Declare variables to count odd and even elements and their indices

    // Count the number of odd and even elements and store their indices
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( array [ i ] % 2 == 0 ) {  // If the current element is even
            even ++ ;  // Increment the count of even elements
            even_ind = i ;  // Store the index of the current even element
        } else {  // If the current element is odd
            odd ++ ;  // Increment the count of odd elements
            odd_ind = i ;  // Store the index of the current odd element
        }
    }

    // Determine the output based on the count of odd and even elements
    if ( odd > even ) {  // If there are more odd elements than even elements
        printf ( "The index of the last even element is %d.\n", even_ind ) ;  // Print the index of the last even element
    } else {  // If there are more even elements than odd elements
        printf ( "The index of the last odd element is %d.\n", odd_ind ) ;  // Print the index of the last odd element
    }

    return 0 ;  // Return 0 to indicate successful execution of the program
}
