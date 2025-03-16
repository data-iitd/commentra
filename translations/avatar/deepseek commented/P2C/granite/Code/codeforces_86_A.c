

#include <stdio.h>
#include <math.h>

int main ( ) {
    int l, r, curr, s, first, second, ans, i, k ;
    scanf ( "%d %d", & l, & r ) ;
    // Taking the range as input from the user

    curr = r ;
    s = 0 ;
    // Initialize curr to r and s to 0

    while ( curr ) {
        s += 1 ;
        curr /= 10 ;
    }
    // Determine the number of digits in r and store it in s

    first = pow ( 10, s ) ;
    second = first / 2 ;
    // Calculate the smallest number with s digits and its half

    ans = - 1 ;
    // Initialize ans to -1 to store the maximum product found

    for ( i = l ; i <= r ; i ++ ) {
        curr = i ;
        rev = 0 ;
        while ( curr ) {
            rev = rev * 10 + 9 - curr % 10 ;
            curr /= 10 ;
        }
        ans = fmax ( ans, rev * i ) ;
    }
    // Iterate over the specified numbers, check if they are within the range,
    // reverse the digits, calculate the product, and update ans if necessary

    printf ( "%d", ans ) ;
    // Print the maximum product found

    return 0 ;
}
// Translate the above C code to Java and end with comment "