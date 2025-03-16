
#include <stdio.h> // Including the standard input/output library

int main ( void ) { // Starting the main function
    int n ; // Declaring an integer variable n to store the number of elements in the array
    scanf ( "%d", & n ) ; // Reading the number of elements in the array from the standard input
    int arr [ n ] ; // Declaring an integer array of size n to store the elements of the array
    int sum = 0 ; // Initializing the sum variable to 0

    for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop to read and store the elements in the array
        scanf ( "%d", & arr [ i ] ) ; // Reading an integer value from the standard input and storing it in the current index of the array
        sum += arr [ i ] ; // Adding the current element to the sum variable
    }

    int c = 0 ; // Initializing the counter variable to 0
    char sb [ 100000 ] ; // Declaring a character array of size 100000 to store the indices of the elements that satisfy the condition
    int k = 0 ; // Initializing the index variable k to 0

    for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop to check if an element satisfies the condition
        if ( ( sum - arr [ i ] ) % ( n - 1 ) == 0 && ( sum - arr [ i ] ) / ( n - 1 ) == arr [ i ] ) { // Checking if the current element satisfies the condition
            c ++ ; // Incrementing the counter variable if the condition is true
            sprintf ( sb + k, "%d ", ( i + 1 ) ) ; // Formatting the index of the current element and storing it in the character array sb
            k += 2 ; // Incrementing the index variable k by 2 to move to the next position in the character array sb
        }
    }

    printf ( "%d\n", c ) ; // Printing the number of elements that satisfy the condition
    printf ( "%s", sb ) ; // Printing the indices of the elements that satisfy the condition separated by a space
    return 0 ; // Returning 0 to indicate successful execution of the program
}

