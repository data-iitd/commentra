
#include <iostream>
#include <cstdlib>

using namespace std ;

int main ( ) {
    int n , m ; // Declaring and initializing the variables n and m
    cin >> n >> m ; // Reading the values of n and m from the standard input
    int a [ n ] ; // Creating an integer array a of size n

    // Initializing the array a with input values
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> a [ i ] ; // Reading an integer value and storing it in the array
        a [ i ] /= 2 ; // Dividing the current array element by 2
    }

    long gcd ; // Declaring a variable gcd to store the greatest common divisor
    long lcd = 1 ; // Declaring and initializing a variable lcm to store the least common multiple

    // Finding the least common multiple of all array elements
    for ( int i = 0 ; i < n ; i ++ ) {
        gcd = getGCD ( lcd , a [ i ] ) ; // Finding the greatest common divisor of lcm and the current array element
        lcd = lcd * a [ i ] / gcd ; // Updating the value of lcm

        // Checking if lcm is greater than m
        if ( lcd > m ) {
            cout << 0 << endl ; // If true, printing 0 and returning from the method
            return 0 ;
        }
    }

    // Checking if any array element is a factor of lcm
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( ( lcd / a [ i ] ) % 2 == 0 ) { // Checking if the remainder of lcm divided by the current array element is 0 and even
            cout << 0 << endl ; // If true, printing 0 and returning from the method
            return 0 ;
        }
    }

    // Printing the result
    cout << ( m / lcd + 1 ) / 2 << endl ;
    return 0 ;
}

// A helper method to find the greatest common divisor of two numbers
long getGCD ( long a , long b ) {
    if ( b == 0 ) { // Base case: if b is 0, return a as the gcd
        return a ;
    } else {
        return getGCD ( b , a % b ) ; // Recursive call: finding the gcd of b and the remainder of a divided by b
    }
}

