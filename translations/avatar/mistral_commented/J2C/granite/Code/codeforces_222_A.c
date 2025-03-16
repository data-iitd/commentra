
#include <stdio.h> // Including the standard input/output library

int main ( void ) { // Defining the main function
    int n, k, l = 0, c = 1 ; // Declaring and initializing the variables n, k, l, and c with values 0 and 1 respectively

    scanf ( "%d %d", &n, &k ) ; // Reading the first two integers from the standard input and assigning them to variables n and k respectively

    for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop that iterates n times
        int a ; // Declaring a new integer variable a

        scanf ( "%d", &a ) ; // Reading the next integer from the standard input and assigning it to variable a

        if ( a == l ) c += 1 ; // If the current integer is equal to the previous one, increment the counter c by 1
        else c = 1 ; // Otherwise, reset the counter c to 1

        l = a ; // Assigning the current integer to the previous integer variable l
    }

    if ( c + k > n ) { // Checking if the sum of counter c and integer k is greater than the total number of integers n
        printf ( "%d", n - c ) ; // If true, print the difference between n and c
    } else {
        printf ( "-1" ) ; // If false, print -1
    }

    return 0 ; // Returning 0 to indicate successful execution of the program
}
