

import sys
sys.setrecursionlimit(10**6) # Increase the recursion limit to handle large inputs

mod = 10**9+7 # Modulus value for modular arithmetic
NMAX = 10**6+10 # Maximum size of the arrays

fac = [1]*NMAX # Arrays for storing factorials, their inverses, and fast inverse
finv = [1]*NMAX # Arrays for storing factorials, their inverses, and fast inverse
inv = [1]*NMAX # Arrays for storing factorials, their inverses, and fast inverse

# Initialize the arrays with factorials, inverses, and fast inverse values
def init():
    for i in range(2, NMAX): # Iterate from 2 to NMAX-1
        fac[i] = fac[i-1]*i % mod # Multiply the current number with the previous factorial
        inv[i] = mod - inv[mod%i]*(mod//i) % mod # Calculate the inverse of the current number using extended Euclidean algorithm
        finv[i] = finv[i-1]*inv[i] % mod # Multiply the previous fast inverse with the current inverse to get the fast inverse

# Calculate the binomial coefficient C(n, k) using the precomputed values
def C(n, k):
    if n < k: return 0 # Return 0 if n is less than k
    if n < 0 or k < 0: return 0 # Return 0 if n or k is negative
    return fac[n]*(finv[k]*finv[n-k] % mod) % mod # Multiply the factorial of n with the product of the fast inverse of k and the fast inverse of n-k, then take the modulo

if __name__ == "__main__":
    init() # Initialize the arrays
    X, Y = map(int, input().split()) # Read input values for X and Y
    if (X+Y) % 3!= 0: # Check if the sum of X and Y is not divisible by 3
        print(0) # If not, print 0 and exit
        exit()
    n = (X+Y) // 3+1 # Calculate the value of n = (X+Y)/3 + 1
    k = 2*(n-1) - Y + 1 # Calculate the value of k = 2*(n-1) - Y + 1
    print(C(n-1, k-1)) # Print the binomial coefficient C(n-1, k-1)

