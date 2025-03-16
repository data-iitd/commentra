
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 

// Function to perform modular division
long modDiv ( long a , long b , long mod ) { 
    return ( a % mod ) * modInv ( b , mod ) % mod ; 
} 

// Function to calculate modular inverse
long modInv ( long x , long mod ) { 
    return modPow ( x , mod - 2 , mod ) ; 
} 

// Function to perform modular exponentiation
long modPow ( long b , long e , long mod ) { 
    long ans = 1 ; 
    long x = b % mod ; 
    for ( long y = e ; y != 0 ; y >>= 1 ) { 
        if ( ( y & 1 ) == 1 ) 
            ans = ( ans * x ) % mod ; 
        x = ( x * x ) % mod ; 
    } 
    return ans ; 
} 

int main ( ) { 
    // Initialize the scanner
    int N ; 
    scanf ( "%d" , &N ) ; 
    int A [ N ] ; 
    
    // Read N integers into array A
    for ( int i = 0 ; i < N ; i ++ ) { 
        scanf ( "%d" , &A [ i ] ) ; 
    } 
    
    // Initialize LCM to 1
    long lcm = 1 ; 
    
    // Calculate the LCM of all elements in array A
    for ( int ai : A ) { 
        long a = ai ; 
        lcm = lcm / ( lcm / a ) * a ; 
    } 
    
    // Define the modulo value
    long mod = 1000000007 ; 
    
    // Calculate the LCM modulo 10^9 + 7
    long modLcm = lcm % mod ; 
    
    // Initialize the answer to 0
    long ans = 0 ; 
    
    // Calculate the sum of each element in A divided by the LCM, modulo 10^9 + 7
    for ( int ai : A ) 
        ans = ( ans + modDiv ( modLcm , ai , mod ) ) % mod ; 
    
    // Print the final answer
    printf ( "%ld\n" , ans ) ; 
    
    return 0 ; 
} 

// 