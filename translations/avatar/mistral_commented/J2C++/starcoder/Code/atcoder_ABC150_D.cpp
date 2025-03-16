
#include <bits/stdc++.h> // Importing the standard library

using namespace std ; // Using the standard namespace

int main ( ) { // Starting the main method
    int n, m ; // Declaring two variables n and m
    cin >> n >> m ; // Reading the first integer n and the second integer m from the standard input

    int a [ n ] ; // Declaring an integer array a of size n

    // Initializing the array a with input values
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> a [ i ] ; // Reading an integer value and storing it in the array
    }

    long gcd, lcd = 1 ; // Declaring two variables gcd and lcm to store the greatest common divisor and the least common multiple

    // Finding the least common multiple of all array elements
    for ( int i = 0 ; i < n ; i ++ ) {
        gcd = __gcd ( lcd, a [ i ] ) ; // Finding the greatest common divisor of lcm and the current array element
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
}

// A helper method to find the greatest common divisor of two numbers
long __gcd ( long a, long b ) {
    if ( b == 0 ) { // Base case: if b is 0, return a as the gcd
        return a ;
    } else {
        return __gcd ( b, a % b ) ; // Recursive call: finding the gcd of b and the remainder of a divided by b
    }
}

