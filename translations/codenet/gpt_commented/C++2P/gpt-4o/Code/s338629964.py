import sys
from functools import lru_cache

# Define constants for modular arithmetic
MOD2 = 1000000007
MOD = 998244353
INF = (1 << 30) - 1
LINF = (1 << 60)
EPS = 1e-10

# Type definitions for convenience
Int = int
P = tuple

# Arrays for factorials and their modular inverses
fact = [0] * 1100000
revfact = [0] * 1100000
rev = [0] * 1100000

# Function to initialize factorials and their inverses
def init():
    m = MOD  # Set the modulus
    fact[0] = 1  # Base case for factorial
    revfact[0] = 1  # Base case for inverse factorial
    rev[0] = 0  # Not used
    rev[1] = 1  # Inverse of 1 is 1

    # Precompute factorials and their modular inverses
    for i in range(1, 1100000):
        fact[i] = fact[i - 1] * i % m  # Compute factorial
        if i > 1:
            rev[i] = m // i * (m - rev[m % i]) % m  # Compute modular inverse
        revfact[i] = revfact[i - 1] * rev[i] % m  # Compute inverse factorial

# 2D array for storing combinations
comb = [[0] * 1100 for _ in range(1100)]

# Function to compute n choose k (combinations)
def nCk(n, k):
    if n < k:
        return 0  # If n < k, return 0
    if comb[n][k] != 0:
        return comb[n][k]  # Return cached result if available
    res = fact[n] * revfact[n - k] % MOD * revfact[k] % MOD  # Compute combinations
    comb[n][k] = res
    return res

# Function to compute modular exponentiation
def mod_pow(x, a, m=MOD):
    if a == 0:
        return 1  # Base case
    res = mod_pow(x, a // 2, m)  # Recursive call
    res = res * res % m  # Square the result
    if a % 2:
        res *= x  # If a is odd, multiply by x
    return res % m  # Return result modulo m

# Function to compute modular inverse using Fermat's Little Theorem
def inv(x, m=MOD):
    return mod_pow(x, m - 2, m)  # Inverse is x^(m-2) mod m

# Global variables for input and output
aall, ball = 0, 0  # Total sums of arrays a and b
n, ans = 0, 0  # Number of elements and final answer
a = [0] * 440
b = [0] * 440
dp = [[[[0 for _ in range(2)] for _ in range(2)] for _ in range(440)] for _ in range(440)]]

def main():
    global aall, ball, n, ans
    init()  # Initialize factorials and inverses
    n = int(sys.stdin.readline().strip())  # Read the number of elements

    # Read input arrays and compute their total sums
    for i in range(n):
        a[i], b[i] = map(int, sys.stdin.readline().strip().split())
        aall += a[i]  # Sum of array a
        ball += b[i]  # Sum of array b

    # Initialize the dynamic programming table
    dp[0][0][0][0] = 1  # Base case for DP
    for i in range(1, n + 1):
        id = i % 2  # Current index for alternating DP
        # Iterate over possible sums and counts
        for asum in range(aall, -1, -1):
            for cnt in range(ball + 1):
                for p in range(2):
                    if asum - a[i - 1] < 0:
                        continue  # Skip if sum is not feasible
                    pw = 1  # Power variable for combinations
                    # Iterate over possible uses of b[i-1]
                    for use in range(b[i - 1]):
                        if cnt - use >= 0:
                            tmp = nCk(cnt, use) % MOD * pw % MOD  # Compute combinations
                            # Update DP table based on previous states
                            dp[asum][cnt][p][0] += dp[asum - a[i - 1]][cnt - use][p ^ 1][0] * tmp % MOD
                            dp[asum][cnt][p][1] += dp[asum - a[i - 1]][cnt - use][p ^ 1][1] * tmp % MOD
                        else:
                            break  # Break if not enough count
                        pw = pw * a[i - 1] % MOD  # Update power for next use
                    # Handle the case where we use one more from b[i-1]
                    if cnt - b[i - 1] + 1 >= 0:
                        dp[asum][cnt][p][1] += dp[asum - a[i - 1]][cnt - b[i - 1] + 1][p ^ 1][0] * nCk(cnt, b[i - 1] - 1) % MOD * pw % MOD
                    # Apply modulo to keep values within bounds
                    dp[asum][cnt][p][0] %= MOD
                    dp[asum][cnt][p][1] %= MOD

    # Final computation of the answer
    for asum in range(aall + 1):
        rev_asum_pow = 1  # Initialize power for the current sum
        for cnt in range(ball + 1):
            rev_asum_pow = rev_asum_pow * rev[asum] % MOD  # Update power for the sum
            for p in range(2):
                # Compute contribution to the answer based on DP values
                x = dp[asum][cnt][p][1] * rev_asum_pow % MOD * (cnt + 1) % MOD * aall % MOD * rev[asum] % MOD
                if p == 1:
                    ans += x  # Add if p is 1
                else:
                    ans -= x  # Subtract if p is 0
                ans %= MOD  # Ensure answer is within bounds

    # Adjust answer if negative
    if ans < 0:
        ans += MOD
    print(ans)  # Output the final answer

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
