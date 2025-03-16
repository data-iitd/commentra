
# Python code

# Including necessary libraries
import sys

# Defining some constants and variables
MOD2 = 1000000007
MOD = 998244353
INF = ((1<<30)-1)
LINF = (1<<60)
EPS = (1e-10)

# Function to calculate factorial
def factorial(n):
    fact = [1] * (n+1)
    for i in range(1, n+1):
        fact[i] = fact[i-1] * i % MOD
    return fact

# Function to calculate inverse factorial
def inv_factorial(n):
    revfact = [1] * (n+1)
    rev = [0] * (n+1)
    rev[0] = 0
    rev[1] = 1
    for i in range(1, n+1):
        rev[i] = MOD // i * (MOD-rev[MOD % i]) % MOD
    revfact[n] = revfact[n-1] * rev[n] % MOD
    for i in range(n-1, 0, -1):
        revfact[i] = revfact[i+1] * rev[i+1] % MOD
    return revfact

# Function to calculate binomial coefficient
def binom(n, k):
    if n < k:
        return 0
    return fact[n] * revfact[n-k] % MOD * revfact[k] % MOD

# Function to calculate modular power
def mod_pow(x, a, m=MOD):
    if a == 0:
        return 1
    res = mod_pow(x, a // 2, m)
    res = res * res % m
    if a % 2:
        res *= x
    return res % m

# Function to calculate modular inverse
def inv(x, m=MOD):
    return mod_pow(x, m-2, m)

# Main function
def main():
    # Initialize factorial and inverse factorial arrays
    fact = factorial(1100000)
    revfact = inv_factorial(1100000)

    # Read input from the user
    n = int(input())
    a = [0] * n
    b = [0] * n
    aall = 0
    ball = 0
    for i in range(n):
        a[i], b[i] = map(int, input().split())
        aall += a[i]
        ball += b[i]

    # Calculate the answer using dynamic programming
    dp = [[[[0, 0] for _ in range(2)] for _ in range(ball+1)] for _ in range(aall+1)]
    dp[0][0][0][0] = 1
    for i in range(1, n+1):
        id = i % 2
        for asum in range(aall, -1, -1):
            for cnt in range(ball, -1, -1):
                for p in range(2):
                    if asum-a[i-1] < 0:
                        continue
                    pw = 1
                    for use in range(b[i-1]):
                        if cnt-use >= 0:
                            tmp = binom(cnt, use) * pw % MOD
                            dp[asum][cnt][p][0] += dp[asum-a[i-1]][cnt-use][p^1][0] * tmp % MOD
                            dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-use][p^1][1] * tmp % MOD
                        else:
                            break
                        pw = pw * a[i-1] % MOD
                    if cnt-b[i-1]+1 >= 0:
                        dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-b[i-1]+1][p^1][0] * binom(cnt, b[i-1]-1) * pw % MOD
                    dp[asum][cnt][p][0] %= MOD
                    dp[asum][cnt][p][1] %= MOD

    ans = 0
    for asum in range(aall+1):
        rev_asum_pow = 1
        for cnt in range(ball+1):
            rev_asum_pow = rev_asum_pow * inv(asum) % MOD
            for p in range(2):
                x = dp[asum][cnt][p][1] * rev_asum_pow  % MOD * (cnt+1) % MOD * aall % MOD * inv(asum) % MOD
                if p == 1:
                    ans += x
                else:
                    ans -= x
                ans %= MOD

    # Output the answer
    print(ans)

if __name__ == "__main__":
    main()

Translate the above Python code to C++ and end with comment "