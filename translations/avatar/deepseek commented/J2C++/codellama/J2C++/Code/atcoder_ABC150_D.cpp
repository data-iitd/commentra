
#include <iostream> 
#include <cstdlib> 
#include <cmath> 

using namespace std ; 

int main ( ) { 
    int n , m ; 
    int a [ ] ; 
    
    // Read the first integer n
    cin >> n ; 
    
    // Read the second integer m
    cin >> m ; 
    
    // Initialize array a with size n, where each element is half of the next input
    for ( int i = 0 ; i < n ; i ++ ) { 
        cin >> a [ i ] ; 
        a [ i ] /= 2 ; 
    } 
    
    long gcd ; 
    long lcd = 1 ; 
    
    // Calculate the least common multiple (LCM) of the elements in array a
    for ( int i = 0 ; i < n ; i ++ ) { 
        gcd = getGCD ( lcd , a [ i ] ) ; 
        lcd = lcd * a [ i ] / gcd ; 
        if ( lcd > m ) { // Check if LCM exceeds m
            cout << 0 << endl ; 
            return 0 ; 
        } 
    } 
    
    // Check if the LCM is even for any element in the array
    for ( int i = 0 ; i < n ; i ++ ) { 
        if ( ( lcd / a [ i ] ) % 2 == 0 ) { 
            cout << 0 << endl ; 
            return 0 ; 
        } 
    } 
    
    // Calculate and print the number of integers up to m that are divisible by the LCM
    cout << ( m / lcd + 1 ) / 2 << endl ; 
    
    return 0 ; 
} 

// Helper function to compute the greatest common divisor (GCD) of two numbers
long getGCD ( long a , long b ) { 
    if ( b == 0 ) { 
        return a ; 
    } else { 
        return getGCD ( b , a % b ) ; 
    } 
} 

