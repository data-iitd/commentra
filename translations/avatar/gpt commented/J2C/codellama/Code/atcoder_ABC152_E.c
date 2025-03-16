#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 

// Define the modulus value
long mod = 1000000007; 

// Define the number of elements in the array A
int N; 

// Define the array A to hold N integers
int A[100000]; 

// Define the BigInteger to calculate the least common multiple (LCM)
BigInteger lcm = BigInteger.ONE; 

// Define the answer variable to accumulate results
long ans = 0; 

// Define the modulus value
long mod = 1000000007; 

// Define the modular inverse using Fermat's Little Theorem
long modInv(long x, long mod) { 
    return modPow(x, mod - 2, mod); 
} 

// Define the modular exponentiation
long modPow(long b, long e, long mod) { 
    long ans = 1; 
    long x = b % mod; 
    
    // Loop to calculate b^e % mod using exponentiation by squaring
    for (long y = e; y != 0; y >>= 1) { 
        if ((y & 1) == 1) 
            ans = (ans * x) % mod; 
        x = (x * x) % mod; 
    } 
    
    // Return the final result of b^e % mod
    return ans; 
} 

// Define the method to perform modular division
long modDiv(long a, long b, long mod) { 
    return (a % mod) * modInv(b, mod) % mod; 
} 

// Define the main method
int main() { 
    // Read the number of elements N
    scanf("%d", &N); 
    
    // Read N integers into the array A
    for (int i = 0; i < N; i++) { 
        scanf("%d", &A[i]); 
    } 
    
    // Calculate the LCM of all elements in the array A
    for (int ai : A) { 
        BigInteger a = BigInteger.valueOf(ai); 
        lcm = lcm.divide(lcm.gcd(a)).multiply(a); 
    } 
    
    // Calculate the LCM modulo mod
    long modLcm = lcm.remainder(BigInteger.valueOf(mod)).longValue(); 
    
    // Calculate the sum of modDiv for each element in A
    for (int ai : A) 
        ans = (ans + modDiv(modLcm, ai, mod)) % mod; 
    
    // Print the final result
    printf("%ld\n", ans); 
    
    // End of code
    return 0; 
} 


