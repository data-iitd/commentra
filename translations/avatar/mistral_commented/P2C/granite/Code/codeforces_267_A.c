

#include <stdio.h>

// Function to find the difference between two numbers using Euclidean algorithm
int substract ( int a, int b ) {
    // Check if 'a' is greater than 'b'
    if ( a > b ) {
        // Initialize total to 0
        int total = 0;
        // Continue the loop while both 'a' and 'b' are greater than 0
        while ( a > 0 && b > 0 ) {
            // Add the quotient of 'a' and 'b' to the total
            total += ( a / b );
            // Update 'a' and 'b' for the next iteration
            a = a % b;
            if ( a > 0 ) {
                // Add the quotient of 'b' and 'a' to the total
                total += ( b / a );
                // Update 'a' and 'b' for the next iteration
                b = b % a;
            }
        }
        // Return the total difference
        return total;
    }
    // Check if 'a' is smaller than 'b'
    else if ( a < b ) {
        // Initialize total to 0
        int total = 0;
        // Continue the loop while both 'a' and 'b' are greater than 0
        while ( a > 0 && b > 0 ) {
            // Add the quotient of 'b' and 'a' to the total
            total += ( b / a );
            // Update 'a' and 'b' for the next iteration
            b = b % a;
            if ( b > 0 ) {
                // Add the quotient of 'a' and 'b' to the total
                total += ( a / b );
                // Update 'a' and 'b' for the next iteration
                a = a % b;
            }
        }
        // Return the total difference
        return total;
    }
    // Check if 'a' is equal to 'b'
    else {
        // Return 1 if 'a' is equal to 'b'
        return 1;
    }
}

// Take the number of test cases as input
int main ( ) {
    int n;
    scanf ( "%d", &n );
    // Initialize an empty list to store the differences
    int lst[n];
    // Iterate through each test case
    for ( int i = 0 ; i < n ; i++ ) {
        // Take two numbers as input
        int a, b;
        scanf ( "%d %d", &a, &b );
        // Append the difference between 'a' and 'b' to the list
        lst[i] = substract ( a, b );
    }
    // Print each difference in the list
    for ( int i = 0 ; i < n ; i++ ) {
        // Print the difference
        printf ( "%d\n", lst[i] );
    }
    return 0;
}

