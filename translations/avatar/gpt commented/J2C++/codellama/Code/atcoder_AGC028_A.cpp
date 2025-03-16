#include <iostream> 
#include <string> 
#include <cmath> 

using namespace std; 

int main() { 
    // Read two integers n and m from input
    int n, m; 
    cin >> n >> m; 
    
    // Calculate the greatest common divisor (gcd) of n and m
    int gcd = gcd(n, m); 
    
    // Read two strings s and t from input
    string s, t; 
    cin >> s >> t; 
    
    // Check for mismatches in the characters of the two strings based on the gcd
    // If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
    cout << (
        any_of(
            // Filter indices where characters differ
            // Map to -1 for mismatches
            // Find any mismatch
            // Calculate lcm if no mismatch
            // Return -1 if mismatch found, lcm otherwise
            gcd,
            [&](int k) {
                return s[k * n / gcd] != t[k * m / gcd] ? -1 : BigInteger(n).multiply(BigInteger(m)).divide(BigInteger(gcd)).longValue();
            }
        )
    ) << endl; 
    
    return 0; 
} 


