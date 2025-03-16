MOD = 10**9 + 7

# Function to compute a raised to the power n (a^n)
def pow(a, n):
    res = 1
    while n > 0:
        if n & 1:
            res *= a
        a *= a
        n >>= 1
    return res

# Function to compute a raised to the power n modulo mod (a^n % mod)
def mod_pow(a, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = res * a % mod
        a = a * a % mod
        n >>= 1
    return res

# Function to compute modular multiplicative inverse of a modulo mod (a^(-1) % mod)
# This function assumes that a is not divisible by mod
def mod_inv(a, mod):
    return mod_pow(a, mod - 2, mod)

# Function to compute n choose k modulo mod (nCk % mod)
def mod_nCk(n, k, mod):
    if n == 0 or k == 0:
        return 1
    p = 1
    q = 1
    
    # Calculate the numerator for nCk
    for i in range(n - k + 1, n + 1):
        p = (p * i) % mod
    
    # Calculate the denominator for nCk
    for i in range(2, k + 1):
        q = (q * i) % mod
    
    q = mod_inv(q, mod)
    return (p * q) % mod

# Main function
def main():
    n, k = map(int, input().split())
    print(mod_nCk(k, n, MOD))

# Call the main function
main()
