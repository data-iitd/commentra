
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#define mod 1000000007 

int main ( ) { 
    // Step 1: Read the input number n and the array elements
    int n ; 
    scanf ( "%d" , &n ) ; 
    int a [ n ] ; 
    for ( int i = 0 ; i < n ; i ++ ) { 
        scanf ( "%d" , &a [ i ] ) ; 
    } 

    // Step 2: Calculate the factorial of n modulo 10^9 + 7
    long p = 1 ; 
    for ( int i = 2 ; i <= n ; i ++ ) { 
        p = ( p * i ) % mod ; 
    } 

    // Step 3: Calculate the inverse modulo for each number from 2 to n
    long q [ n ] ; 
    q [ 0 ] = 1 ; 
    for ( int i = 1 ; i < n ; i ++ ) { 
        q [ i ] = ( q [ i - 1 ] + modinv ( i + 1 , mod ) ) % mod ; 
    } 

    // Step 4: Calculate the answer using the given formula
    long ans = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) { 
        long val = q [ i ] + q [ n - i - 1 ] - 1 ; 
        val *= a [ i ] ; 
        val %= mod ; 
        val *= p ; 
        val %= mod ; 
        ans += val ; 
        ans %= mod ; 
    } 

    // Step 5: Print the final answer
    printf ( "%ld\n" , ans ) ; 
    return 0 ; 
} 

// Function to calculate the modular inverse
long modinv ( long a , int m ) { 
    long b = m ; 
    long u = 1 ; 
    long v = 0 ; 
    long tmp = 0 ; 
    while ( b > 0 ) { 
        long t = a / b ; 
        a -= t * b ; 
        tmp = a ; 
        a = b ; 
        b = tmp ; 
        u -= t * v ; 
        tmp = u ; 
        u = v ; 
        v = tmp ; 
    } 
    u %= m ; 
    if ( u < 0 ) u += m ; 
    return u ; 
} 

