

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( ) {
    long long N = 0 ; // Declaring a long long variable `N` and initializing it with the value 0
    long long A = 0 ; // Declaring a long long variable `A` and initializing it with the value 0
    long long B = 0 ; // Declaring a long long variable `B` and initializing it with the value 0
    long long k = 0 ; // Declaring a long long variable `k` and initializing it with the value 0

    scanf ( "%lld %lld %lld", &N, &A, &B ) ; // Reading the first long long integer `N`, the second long long integer `A`, and the third long long integer `B` from the standard input

    if ( isValidInput ( N, A, B ) ) { // Checking if the input values are valid
        if ( A + B <= N ) { // Checking if the sum of `A` and `B` is less than or equal to `N`
            k = calculateK ( N, A, B ) ; // Calculating the number of times `A + B` can be added to `N` and storing the result in `k`

            if ( remainingPartGreaterThanA ( N, k, A ) ) { // Checking if the remaining part of `N` after subtracting `k * (A + B)` is greater than `A`
                printResult ( N, k, A ) ; // Printing the result of the expression `A * k + (N - k * (A + B)) - (N - (k * (A + B) + A))`
            } else {
                printResult ( N, k, A ) ; // Printing the result of the expression `A * k + (N - k * (A + B))`
            }
        } else if ( A + B > N && A <= N ) { // Checking if the sum of `A` and `B` is greater than `N`, but `A` is less than or equal to `N`
            printA ( ) ; // Printing the value of `A`
        } else { // If neither of the above conditions is true
            printN ( ) ; // Printing the value of `N`
        }
    }

    return 0 ; // Returning 0 to indicate successful execution of the program
}

bool isValidInput ( long long n, long long a, long long b ) {
    return ( 1 <= n && n <= pow ( 10, 18 ) && 0 <= a && 0 <= b && 0 < a + b && a + b <= pow ( 10, 18 ) ) ;
}

long long calculateK ( long long n, long long a, long long b ) {
    return n / ( a + b ) ;
}

bool remainingPartGreaterThanA ( long long n, long long k, long long a ) {
    return ( n - k * ( a + b ) ) > a ;
}

void printResult ( long long n, long long k, long long a ) {
    long long result = 0 ;
    if ( remainingPartGreaterThanA ( n, k, a ) ) {
        result = a * k + ( n - k * ( a + b ) ) - ( n - ( k * ( a + b ) + a ) ) ;
    } else {
        result = a * k + ( n - k * ( a + b ) ) ;
    }
    printf ( "%lld\n", result ) ;
}

void printA ( ) {
    printf ( "%lld\n", A ) ;
}

void printN ( ) {
    printf ( "%lld\n", N ) ;
}

// END-OF-CODE