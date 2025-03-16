

#include <stdio.h> // Including the standard header file for input/output operations
#include <stdlib.h> // Including the standard header file for dynamic memory allocation

int main ( void ) { // Defining the main function that is executed when the program runs
    int n, value, result, pos = 0, flag = 0 ; // Declaring and initializing the variables n, value, result, pos, and flag

    scanf ( "%d", &n ) ; // Reading the number of elements in the ArrayList from the standard input stream

    int *a = ( int * ) malloc ( n * sizeof ( int ) ) ; // Dynamically allocating memory for an array of n integers and assigning the pointer to the variable a

    for ( int i = 0 ; i < n ; i ++ ) { // Using a for loop to read and store each element in the array
        scanf ( "%d", &value ) ; // Reading an integer value from the standard input stream
        a [ i ] = value ; // Storing the value in the array at the ith index
    }

    if ( a [ 0 ] > 15 ) { // Checking if the first element in the array is greater than 15
        result = 15 ; // Assigning 15 to the result variable if the condition is true
    } else {
        for ( int i = 1 ; i < n ; i ++ ) { // Using a for loop to compare each element with the previous one
            if ( a [ i ] - a [ i - 1 ] > 15 ) { // Checking if the difference between two consecutive elements is greater than 15
                pos = i - 1 ; // Assigning the index of the previous element to the pos variable if the condition is true
                flag = 1 ; // Assigning 1 to the flag variable to indicate that the condition is true
                break ; // Exiting the loop if the condition is true
            }
        }
        if ( flag == 1 ) { // Checking if the flag variable is equal to 1, indicating that the condition in the inner for loop was true
            result = a [ pos ] + 15 ; // Assigning the sum of the previous element and 15 to the result variable
        } else {
            result = a [ n - 1 ] + 15 ; // Assigning the sum of the last element and 15 to the result variable if the flag variable is 0
        }
    }

    if ( result > 90 ) result = 90 ; // Checking if the result is greater than 90 and assigning 90 to the result variable if it is

    printf ( "%d", result ) ; // Printing the result to the standard output stream

    free ( a ) ; // Freeing the dynamically allocated memory for the array

    return 0 ; // Returning 0 to indicate successful program execution
}

