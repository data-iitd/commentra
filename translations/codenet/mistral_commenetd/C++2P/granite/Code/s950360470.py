
# Python code

# Constants
MOD = 1000000007 # Modulus value

# Helper functions
# a^n
def pow(a, n):
    res = 1 # Initialize result
    while n > 0: # While n is greater than 0
        if n & 1: res *= a # If n is odd, multiply result with base
        a *= a # Square the base
        n >>= 1 # Divide n by 2
    return res # Return the final result

# a^n % mod
def mod_pow(a, n, mod):
    res = 1 # Initialize result
    while n > 0: # While n is greater than 0
        if n & 1: res = (res * a) % MOD # If n is odd, multiply result with base and take modulo
        a = (a * a) % MOD # Square the base and take modulo
        n >>= 1 # Divide n by 2
    return res # Return the final result

# a^(-1) % mod (only if : a % p!= 0)
def mod_inv(a, mod):
    return mod_pow(a, mod - 2, mod) # Calculate the modular inverse of 'a'

# nCk % mod
def mod_nCk(n, k, mod):
    if n == 0 or k == 0: return 1 # Base case: nC0 = kC0 = 1

    p = 1 # Initialize p
    for i in range(n - k + 1, n + 1): # Calculate p = nC(n-k+1)
        p = (p * i) % MOD

    q = 1 # Initialize q
    for i in range(2, k + 1): # Calculate q = k!
        q = (q * i) % MOD

    q = mod_inv(q, MOD) # Calculate q^(-1) modulo'mod'
    return (p * q) % MOD # Return the final result: nCk = p * q

# Read input values for n and k from the standard input
n = int(input()) # Read n
k = int(input()) # Read k

print(mod_nCk(k, n, MOD)) # Print the result of nCk modulo 'MOD'

