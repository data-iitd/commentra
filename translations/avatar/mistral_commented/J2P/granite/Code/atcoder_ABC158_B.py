

import sys

def main ( ) :
    N = int ( input ( ) ) # Reading the first integer `N` from the standard input
    A = int ( input ( ) ) # Reading the second integer `A` from the standard input
    B = int ( input ( ) ) # Reading the third integer `B` from the standard input

    k = 0 # Initializing an integer variable `k` with the value 0

    if ( isValidInput ( N, A, B ) ) : # Checking if the input values are valid
        if ( A + B <= N ) : # Checking if the sum of `A` and `B` is less than or equal to `N`
            k = calculateK ( N, A, B ) # Calculating the number of times `A + B` can be added to `N` and storing the result in `k`

            if ( remainingPartGreaterThanA ( N, k, A ) ) : # Checking if the remaining part of `N` after subtracting `k * (A + B)` is greater than `A`
                printResult ( N, k, A ) # Printing the result of the expression `A * k + (N - k * (A + B)) - (N - (k * (A + B) + A))`
            else :
                printResult ( N, k, A ) # Printing the result of the expression `A * k + (N - k * (A + B))`
        else if ( A + B > N && A <= N ) : # Checking if the sum of `A` and `B` is greater than `N`, but `A` is less than or equal to `N`
            printA ( ) # Printing the value of `A`
        else : # If neither of the above conditions is true
            printN ( ) # Printing the value of `N`
    sys.stdout.flush ( ) # Flushing the output buffer to save system resources

def isValidInput ( n, a, b ) :
    return ( 1 <= n and n <= 10 ** 18 and 0 <= a and 0 <= b and 0 < a + b and a + b <= 10 ** 18 ) ;

def calculateK ( n, a, b ) :
    return n // ( a + b ) ;

def remainingPartGreaterThanA ( n, k, a ) :
    return ( n - k * ( a + b ) ) > a ;

def printResult ( n, k, a ) :
    result = 0 ;
    if ( remainingPartGreaterThanA ( n, k, a ) ) :
        result = a * k + ( n - k * ( a + b ) ) - ( n - ( k * ( a + b ) + a ) ) ;
    else :
        result = a * k + ( n - k * ( a + b ) ) ;
    print ( result ) ;

def printA ( ) :
    print ( A ) ;

def printN ( ) :
    print ( N ) ;

if __name__ == "__main__" :
    main ( ) ;

