#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    int n ; // Declaring and initializing a variable to store the number of test cases
    scanf ( "%d" , &n ) ; // Reading the number of test cases from the standard input stream

    // Allocating an array of size 'n' to store characters
    char ch [ n ] ;
    int s1 = 0 , s2 = 0 ; // Initializing two variables to keep track of the sum of x and y coordinates respectively
    int i , j = 0 , flag = 0 , dif = 0 ; // Declaring and initializing variables

    // Reading input for each test case
    for ( i=0 ; i<n ; i++ ) {
        int x , y ; // Declaring and initializing variables to store the values of 'x' and 'y'
        scanf ( "%d %d" , &x , &y ) ; // Reading the values of 'x' and 'y' for the current test case

        int temp1 = s1 + x ; // Calculating the sum of 's1' and 'x'
        int temp2 = s2 + y ; // Calculating the sum of 's2' and 'y'

        // Checking if the difference between the sums is within the limit of 500
        if ( abs ( temp1 - temp2 ) <= 500 ) {
            s1 += x ; // Updating the value of 's1'
            ch [ j ++ ] = 'A' ; // Adding 'A' to the character array 'ch'
            continue ; // Skipping the rest of the loop and moving to the next iteration
        }

        // Checking if the difference between the absolute values of the sums is within the limit of 500
        if ( abs ( temp1 - s2 ) <= 500 ) {
            s2 += y ; // Updating the value of 's2'
            ch [ j ++ ] = 'G' ; // Adding 'G' to the character array 'ch'
            continue ; // Skipping the rest of the loop and moving to the next iteration
        }

        flag = 1 ; // Setting the flag to 1 if the difference between the sums is greater than 500
        break ; // Exiting the loop if the difference is greater than 500
    }

    // Checking if the flag is set to 1, indicating that the difference between the sums is greater than 500 for the current test case
    if ( flag == 1 )
        printf ( "-1\n" ) ; // Printing -1 if the difference is greater than 500
    else {
        char ans [ j + 1 ] ; // Initializing an empty string to store the answer
        for ( i=0 ; i<j ; i++ )
            ans [ i ] = ch [ i ] ; // Converting the character array 'ch' to a string 'ans'
        ans [ j ] = '\0' ; // Adding a null character to the end of the string 'ans'
        printf ( "%s\n" , ans ) ; // Printing the string 'ans' as the answer for the current test case
    }

    return 0 ; // Returning 0 to indicate that the program executed successfully
}

