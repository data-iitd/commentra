MOD = 10**9 + 7  # Define a constant for modulo operation

# Function to calculate a^n % mod
def mod_pow(a, n, mod):
    res = 1  # Initialize result
    while n > 0:  # Loop until n becomes 0
        if n & 1:
            res = res * a % mod  # If n is odd, multiply result by a modulo mod
        a = a * a % mod  # Square a modulo mod
        n >>= 1  # Divide n by 2
    return res  # Return the result

# Function to calculate a^(-1) % mod (only if a % mod != 0)
def mod_inv(a, mod):
    return mod_pow(a, mod - 2, mod)  # Use Fermat's little theorem

# Function to calculate nCk % mod
def mod_nCk(n, k, mod):
    if n == 0 or k == 0:
        return 1  # Base case: nCk is 1 if n or k is 0
    p = 1  # Initialize numerator
    q = 1  # Initialize denominator
    for i in range(n - k + 1, n + 1):  # Calculate numerator
        p = (p * i) % mod
    for i in range(2, k + 1):  # Calculate denominator
        q = (q * i) % mod
    q = mod_inv(q, mod)  # Calculate inverse of denominator
    return (p * q) % mod  # Return the result

if __name__ == "__main__":
    n, k = map(int, input().split())  # Read values of n and k
    print(mod_nCk(k, n, MOD))  # Calculate and print nCk % MOD
