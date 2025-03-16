MOD2 = 1000000007
MOD = 998244353
INF = (1 << 30) - 1
LINF = 1LL << 60
EPS = 1e-10

# Type definitions for convenience
Int = int
P = tuple[Int, Int]

# Arrays for factorials and their modular inverses
fact = [0] * 1100000
revfact = [0] * 1100000
rev = [0] * 1100000

# Function to initialize factorials and their inverses
def init():
    m = MOD
    fact[0] = 1
    revfact[0] = 1
    rev[0] = 0
    rev[1] = 1
    
    for i in range(1, 1100000):
        fact[i] = fact[i-1] * i % m
        if i > 1:
            rev[i] = MOD // i * (MOD - rev[MOD % i]) % MOD
        revfact[i] = revfact[i-1] * rev[i] % MOD

# 2D array for storing combinations
comb = [[0] * 1100 for _ in range(1100)]

# Function to compute n choose k (combinations)
def nCk(n: Int, k: Int) -> Int:
    if n < k: return 0
    if comb[n][k] != 0: return comb[n][k]
    res = comb[n][k]
    return res % MOD

# Function to compute modular exponentiation
def mod_pow(x: Int, a: Int, m: Int = MOD) -> Int:
    if a == 0: return 1
    res = mod_pow(x, a // 2, m)
    res = res * res % m
    if a % 2: res *= x
    return res % m

# Function to compute modular inverse using Fermat's Little Theorem
def inv(x: Int, m: Int = MOD) -> Int:
    return mod_pow(x, m-2, m)

# Global variables for input and output
aall = 0
ball = 0
n = 0
ans = 0
a = [0] * 440
b = [0] * 440
dp = [[[[0 for _ in range(2)] for _ in range(2)] for _ in range(440)] for _ in range(440)]

# Main function
def main():
    init()
    n = int(input())
    
    for i in range(n):
        a[i], b[i] = map(int, input().split())
        aall += a[i]
        ball += b[i]

    dp[0][0][0][0] = 1
    for i in range(1, n + 1):
        id = i % 2
        for asum in range(aall, -1, -1):
            for cnt in range(ball + 1):
                for p in range(2):
                    if asum - a[i-1] < 0: continue
                    pw = 1
                    for use in range(b[i-1]):
                        if cnt - use >= 0:
                            tmp = nCk(cnt, use) % MOD * pw % MOD
                            dp[asum][cnt][p][0] += dp[asum - a[i-1]][cnt - use][p^1][0] * tmp % MOD
                            dp[asum][cnt][p][1] += dp[asum - a[i-1]][cnt - use][p^1][1] * tmp % MOD
                        else: break
                        pw = pw * a[i-1] % MOD
                    if cnt - b[i-1] + 1 >= 0:
                        dp[asum][cnt][p][1] += dp[asum - a[i-1]][cnt - b[i-1] + 1][p^1][0] * nCk(cnt, b[i-1] - 1) % MOD * pw % MOD
                    dp[asum][cnt][p][0] %= MOD
                    dp[asum][cnt][p][1] %= MOD

    for asum in range(aall + 1):
        rev_asum_pow = 1
        for cnt in range(ball + 1):
            rev_asum_pow = rev_asum_pow * rev[asum] % MOD
            for p in range(2):
                x = dp[asum][cnt][p][1] * rev_asum_pow % MOD * (cnt + 1) % MOD * aall % MOD * rev[asum] % MOD
                if p == 1: ans += x
                else: ans -= x
                ans %= MOD

    if ans < 0: ans += MOD
    print(ans)

main()
