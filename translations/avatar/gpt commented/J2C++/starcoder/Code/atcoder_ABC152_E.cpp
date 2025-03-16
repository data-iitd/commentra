#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the number of elements N
    int N;
    cin >> N;
    
    // Initialize an array A to hold N integers
    int A[N];
    
    // Read N integers into the array A
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Initialize BigInteger to calculate the least common multiple (LCM)
    BigInteger lcm = BigInteger("1");
    
    // Calculate the LCM of all elements in the array A
    for (int ai : A) {
        BigInteger a = BigInteger(to_string(ai));
        lcm = lcm.divide(lcm.gcd(a)).multiply(a);
    }
    
    // Define the modulus value
    long long mod = 1000000007;
    
    // Calculate the LCM modulo mod
    long long modLcm = lcm.remainder(BigInteger(to_string(mod))).to_string().to_long();
    
    // Initialize the answer variable to accumulate results
    long long ans = 0;
    
    // Calculate the sum of modDiv for each element in A
    for (int ai : A)
        ans = (ans + modDiv(modLcm, ai, mod)) % mod;
    
    // Print the final result
    cout << ans << endl;
}

// Method to perform modular division
long long modDiv(long long a, long long b, long long mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

// Method to compute modular inverse using Fermat's Little Theorem
long long modInv(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}

// Method to perform modular exponentiation
long long modPow(long long b, long long e, long long mod) {
    long long ans = 1;
    long long x = b % mod;
    
    // Loop to calculate b^e % mod using exponentiation by squaring
    for (long long y = e; y!= 0; y >>= 1) {
        if ((y & 1) == 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
    }
    
    // Return the final result of b^e % mod
    return ans;
}

