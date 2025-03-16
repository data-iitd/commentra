
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main ( ) {
    int n ; // Variable to store the integer n
    double sum_before = 0 , sum = 0 ; // Variables to store the sum of all numbers and the sum of their integer parts
    int non_int = 0 ; // Counter for non-integer values
    double max_sum = 0 , min_sum = 0 ; // Variables to store the maximum and minimum possible sums
    double ans = 0 ; // Variable to store the result
    double x = 0 ; // Variable to store the fractional part of the sum

    // Step 1: Reading Input
    scanf ( "%d" , &n ) ; // Read the integer n
    char str [ 1000 ] ; // String to store the second line of input
    fgets ( str , 1000 , stdin ) ; // Read the second line of input
    str [ strlen ( str ) - 1 ] = '\0' ; // Remove the newline character
    char *token = strtok ( str , " " ) ; // Tokenize the string

    // Step 2: Processing Input
    double arr [ 2 * n ] ; // Array to store the floating-point numbers
    for ( int i = 0 ; i < 2 * n ; i ++ ) {
        arr [ i ] = atof ( token ) ; // Convert each token to a double
        sum_before += arr [ i ] ; // Add to the sum of all numbers
        if ( arr [ i ] != floor ( arr [ i ] ) ) non_int ++ ; // Increment counter if the number is not an integer
        sum += floor ( arr [ i ] ) ; // Add the integer part of the number to the sum of integer parts
        token = strtok ( NULL , " " ) ; // Get the next token
    }

    // Step 3: Calculating Results
    max_sum = min ( n , non_int ) + sum ; // Calculate the maximum possible sum
    min_sum = max ( 0 , non_int - n ) + sum ; // Calculate the minimum possible sum
    if ( min_sum > sum_before )
        ans = ( min_sum - sum_before ) ; // If the minimum sum is greater than the actual sum
    else if ( max_sum < sum_before )
        ans = ( sum_before - max_sum ) ; // If the maximum sum is less than the actual sum
    else {
        x = sum_before - floor ( sum_before ) ; // Calculate the fractional part of the sum
        ans = min ( 1 - x , x ) ; // Find the smallest difference to 0 or 1
    }

    // Step 4: Output
    printf ( "%.3f" , ans ) ; // Print the result with a precision of three decimal places

    // 