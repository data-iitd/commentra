
#include <iostream>
#include <cmath>

using namespace std ;

long N , A , B ; // Declaring three long integer variables `N`, `A`, and `B`

bool isValidInput ( long n , long a , long b ) { // Declaring a function `isValidInput` that takes three long integer arguments `n`, `a`, and `b`
    return ( 1 <= n && n <= pow ( 10 , 18 ) && 0 <= a && 0 <= b && 0 < a + b && a + b <= pow ( 10 , 18 ) ) ;
}

long calculateK ( long n , long a , long b ) { // Declaring a function `calculateK` that takes three long integer arguments `n`, `a`, and `b`
    return n / ( a + b ) ;
}

bool remainingPartGreaterThanA ( long n , long k , long a ) { // Declaring a function `remainingPartGreaterThanA` that takes three long integer arguments `n`, `k`, and `a`
    return ( n - k * ( a + b ) ) > a ;
}

void printResult ( long n , long k , long a ) { // Declaring a function `printResult` that takes three long integer arguments `n`, `k`, and `a`
    long result = 0 ;
    if ( remainingPartGreaterThanA ( n , k , a ) ) {
        result = a * k + ( n - k * ( a + b ) ) - ( n - ( k * ( a + b ) + a ) ) ;
    } else {
        result = a * k + ( n - k * ( a + b ) ) ;
    }
    cout << result << endl ;
}

void printA ( ) { // Declaring a function `printA` that takes no arguments
    cout << A << endl ;
}

void printN ( ) { // Declaring a function `printN` that takes no arguments
    cout << N << endl ;
}

int main ( ) { // Declaring a function `main` that takes no arguments
    cin >> N >> A >> B ; // Reading the first long integer `N` from the standard input, the second long integer `A` from the standard input, and the third long integer `B` from the standard input

    long k = 0 ; // Initializing a long variable `k` with the value 0

    if ( isValidInput ( N , A , B ) ) { // Checking if the input values are valid
        if ( A + B <= N ) { // Checking if the sum of `A` and `B` is less than or equal to `N`
            k = calculateK ( N , A , B ) ; // Calculating the number of times `A + B` can be added to `N` and storing the result in `k`

            if ( remainingPartGreaterThanA ( N , k , A ) ) { // Checking if the remaining part of `N` after subtracting `k * (A + B)` is greater than `A`
                printResult ( N , k , A ) ; // Printing the result of the expression `A * k + (N - k * (A + B)) - (N - (k * (A + B) + A))`
            } else {
                printResult ( N , k , A ) ; // Printing the result of the expression `A * k + (N - k * (A + B))`
            }
        } else if ( A + B > N && A <= N ) { // Checking if the sum of `A` and `B` is greater than `N`, but `A` is less than or equal to `N`
            printA ( ) ; // Printing the value of `A`
        } else { // If neither of the above conditions is true
            printN ( ) ; // Printing the value of `N`
        }
    }

    return 0 ; // Returning 0 to indicate that the program executed successfully
}

