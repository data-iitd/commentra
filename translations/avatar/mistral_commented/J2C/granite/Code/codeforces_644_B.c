
#include <stdio.h> // Including the standard header file for input/output operations
#include <stdlib.h> // Including the standard header file for dynamic memory allocation

int main ( void ) { // Defining the main function that is executed when the program runs
    int n, b, t, d ; // Declaring the variables n, b, t, and d of type int
    scanf ( "%d %d", & n, & b ) ; // Reading the values of n and b from the standard input using the scanf function
    long long ans [ n ] ; // Declaring an array of long long type named ans with a length equal to the value of the variable n
    int front = 0, rear = - 1 ; // Declaring the variables front and rear of type int to keep track of the front and rear indices of the queue

    for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop that iterates from 0 to n-1
        scanf ( "%d %d", & t, & d ) ; // Reading the values of t and d from the standard input using the scanf function

        while ( front <= rear && ans [ front ] <= t ) { // Starting a while loop that iterates as long as front is less than or equal to rear and the element at the front index of the queue is less than or equal to t
            front ++ ; // Incrementing the front index by 1
        }

        if ( rear - front + 1 <= b ) { // Checking whether the size of the queue is less than or equal to the value of the variable b
            ans [ ++ rear ] = ( front == 0? t : ans [ rear - 1 ] ) + d ; // Adding the answer to the queue
        } else {
            ans [ ++ rear ] = - 1 ; // If the condition is false, then the answer for the current test case is -1
        }
    }

    for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop that iterates from 0 to n-1
        printf ( "%lld ", ans [ i ] ) ; // Printing the answer for the current test case followed by a space
    }

    printf ( "\n" ) ; // Printing a new line character to separate the output from the rest of the program
    return 0 ; // Returning 0 to indicate successful execution of the program
}

