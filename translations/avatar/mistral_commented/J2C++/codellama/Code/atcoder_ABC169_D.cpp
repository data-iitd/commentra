#include <iostream>
#include <cmath>

using namespace std ;

int main ( ) {
    try {
        long n ;
        int sqrt ;
        int answer = 0 ;

        // Reading a long integer value from user input
        cin >> n ;

        // Calculating the square root of the given number
        sqrt = ( int ) sqrt ( n ) ;

        // Checking for prime factors of the given number
        for ( int i = 2 ; i <= sqrt ; i ++ ) {
            int count = 0 ;
            while ( 0 == ( n % i ) ) {
                n /= i ;
                count ++ ;
            }

            // Calculating the contribution of the current prime factor to the answer
            for ( int j = 1 ; count - j >= 0 ; j ++ ) {
                count -= j ;
                answer ++ ;
            }
        }

        // Checking for the remaining prime factor (if any)
        if ( n > 1 ) {
            answer ++ ;
        }

        // Printing the result
        cout << answer << endl ;

    } catch ( exception e ) {
        cout << "Error: " << e.what ( ) << endl ;
    }

    return 0 ;
}

