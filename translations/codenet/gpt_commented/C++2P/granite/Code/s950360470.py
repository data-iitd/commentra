
MOD = 1000000007  # Define a constant for modulo operation (1000000007)

# Function to compute a raised to the power n (a^n)
def pow(a, n):
    res = 1  # Initialize result to 1
    while n > 0:  # Loop until n becomes 0
        if n & 1:
            res *= a  # If n is odd, multiply result by a
        a *= a  # Square the base
        n >>= 1  # Divide n by 2
    return res  # Return the computed power

# Function to compute a raised to the power n modulo mod (a^n % mod)
def mod_pow(a, n, mod):
    res = 1  # Initialize result to 1
    while n > 0:  # Loop until n becomes 0
        if n & 1:
            res = (res * a) % mod  # If n is odd, multiply result by a and take modulo
        a = (a * a) % mod  # Square the base and take modulo
        n >>= 1  # Divide n by 2
    return res  # Return the computed power modulo

# Function to compute modular multiplicative inverse of a modulo mod (a^(-1) % mod)
# This function assumes that a is not divisible by mod
def mod_inv(a, mod):
    return mod_pow(a, mod - 2, mod)  # Use Fermat's Little Theorem to compute inverse

# Function to compute n choose k modulo mod (nCk % mod)
def mod_nCk(n, k, mod):
    if n == 0 or k == 0:
        return 1  # Base case: nC0 = 1
    p = 1  # Initialize numerator (p)
    q = 1  # Initialize denominator (q)

    # Calculate the numerator for nCk
    for i in range(n - k + 1, n + 1):
        p = (p * i) % MOD  # Multiply terms from (n-k+1) to n and take modulo

    # Calculate the denominator for nCk
    for i in range(2, k + 1):
        q = (q * i) % MOD  # Multiply terms from 1 to k and take modulo

    q = mod_inv(q, MOD)  # Compute the modular inverse of the denominator
    return (p * q) % MOD  # Return the result of nCk modulo

n = int(input())  # Read value of n from input
k = int(input())  # Read value of k from input
print(mod_nCk(k, n, MOD))  # Compute and print nCk modulo MOD

