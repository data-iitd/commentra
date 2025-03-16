
# Define a function to compute (x^n) % MOD using modular exponentiation
def mod_pow(x, n):
    ans = 1 # Initialize result
    while(n > 0): # Loop until n becomes 0
        if((n & 1) == 1): # If n is odd
            ans = ans * x % MOD # Multiply ans by x and take modulo
        x = x * x % MOD # Square x and take modulo
        n >>= 1 # Divide n by 2
    return ans # Return the result

# Define a function to compute combination C(n, r) % MOD using modular arithmetic
def comb_s(n, r):
    tmp_n = 1 # Temporary variable for numerator
    tmp_d = 1 # Temporary variable for denominator
    ans = 1 # Variable to store the final answer
    for i in range(1, r + 1): # Loop to calculate numerator and denominator
        tmp_n = (tmp_n * (n + 1 - i)) % MOD # Calculate numerator
        tmp_d = (tmp_d * i) % MOD # Calculate denominator
        ans = tmp_n * mod_pow(tmp_d, MOD - 2) % MOD # Calculate combination using modular inverse
    return ans # Return the combination result

n = int(input()) # Input the total number of elements
a = int(input()) # Input the first subset size
b = int(input()) # Input the second subset size

ans = 1 # Initialize answer variable

# Calculate 2^n - 1 (total subsets excluding the empty set)
ans = mod_pow(2, n)
ans -= 1

tmp_nd = 0 # Temporary variable to store combinations

# Calculate C(n, a) and subtract from ans
tmp_nd = comb_s(n, a)
ans = (ans - tmp_nd) % MOD # Subtract combinations of size a
while(ans < 0): # Ensure ans is non-negative
    ans += MOD
#print(ans, tmp_nd) # Uncomment for debugging

# Calculate C(n, b) and subtract from ans
tmp_nd = comb_s(n, b)
ans = (ans - tmp_nd) % MOD # Subtract combinations of size b
#print(ans, tmp_nd) # Uncomment for debugging
while(ans < 0): # Ensure ans is non-negative
    ans += MOD

# Output the final result
print(ans)

