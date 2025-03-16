
MOD = 1000000007

# Function to calculate x^n % MOD using bitwise operations
def mod_pow(x, n):
    ans = 1
    while n > 0:
        if n & 1 == 1: # Check if the least significant bit is 1
            ans = ans * x % MOD # Update ans if the bit is set
        x = x * x % MOD # Square x and take modulo MOD
        n >>= 1 # Shift n right by 1 bit (divide by 2)
    return ans

# Function to calculate combination C(n, r) % MOD
def comb_s(n, r):
    tmp_n = 1
    tmp_d = 1
    ans = 1
    for i in range(1, r + 1):
        tmp_n = (tmp_n * (n + 1 - i)) % MOD # Compute the numerator
        tmp_d = (tmp_d * i) % MOD # Compute the denominator
        ans = tmp_n * pow(tmp_d, MOD - 2, MOD) # Compute the combination
    return ans

n = int(input()) # Read input value for n
a = int(input()) # Read input value for a
b = int(input()) # Read input value for b
ans = pow(2, n, MOD) # Calculate 2^n % MOD
ans -= 1 # Subtract 1 from ans
tmp_nd = comb_s(n, a) # Calculate C(n, a) % MOD
ans = (ans - tmp_nd) % MOD # Subtract the combination from ans
while ans < 0: # Handle negative results
    ans += MOD

tmp_nd = comb_s(n, b) # Calculate C(n, b) % MOD
ans = (ans - tmp_nd) % MOD # Subtract the combination from ans
while ans < 0: # Handle negative results
    ans += MOD

print(ans) # Output the final result

