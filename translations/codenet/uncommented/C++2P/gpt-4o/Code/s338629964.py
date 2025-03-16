import sys
from functools import lru_cache

MOD = 998244353
MAXN = 1100000
MAXK = 440

fact = [0] * MAXN
revfact = [0] * MAXN
rev = [0] * MAXN

def init():
    global fact, revfact, rev
    m = MOD
    fact[0] = 1
    revfact[0] = 1
    rev[0] = 0
    rev[1] = 1
    for i in range(1, MAXN):
        fact[i] = fact[i - 1] * i % m
        if i > 1:
            rev[i] = m // i * (m - rev[m % i]) % m
        revfact[i] = revfact[i - 1] * rev[i] % m

comb = [[0] * MAXK for _ in range(MAXK)]

def nCk(n, k):
    if n < k:
        return 0
    if comb[n][k] != 0:
        return comb[n][k]
    res = fact[n] * revfact[n - k] % MOD * revfact[k] % MOD
    comb[n][k] = res
    return res

def mod_pow(x, a, m=MOD):
    if a == 0:
        return 1
    res = mod_pow(x, a // 2, m)
    res = res * res % m
    if a % 2:
        res = res * x % m
    return res

def inv(x, m=MOD):
    return mod_pow(x, m - 2, m)

aall, ball = 0, 0
n = int(input())
a = [0] * MAXK
b = [0] * MAXK
dp = [[[[0 for _ in range(2)] for _ in range(2)] for _ in range(MAXK)] for _ in range(MAXK)]]

init()

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
                if asum - a[i - 1] < 0:
                    continue
                pw = 1
                for use in range(b[i - 1]):
                    if cnt - use >= 0:
                        tmp = nCk(cnt, use) % MOD * pw % MOD
                        dp[asum][cnt][p][0] += dp[asum - a[i - 1]][cnt - use][p ^ 1][0] * tmp % MOD
                        dp[asum][cnt][p][1] += dp[asum - a[i - 1]][cnt - use][p ^ 1][1] * tmp % MOD
                    else:
                        break
                    pw = pw * a[i - 1] % MOD
                if cnt - b[i - 1] + 1 >= 0:
                    dp[asum][cnt][p][1] += dp[asum - a[i - 1]][cnt - b[i - 1] + 1][p ^ 1][0] * nCk(cnt, b[i - 1] - 1) % MOD * pw % MOD
                dp[asum][cnt][p][0] %= MOD
                dp[asum][cnt][p][1] %= MOD

ans = 0
for asum in range(aall + 1):
    rev_asum_pow = 1
    for cnt in range(ball + 1):
        rev_asum_pow = rev_asum_pow * rev[asum] % MOD
        for p in range(2):
            x = dp[asum][cnt][p][1] * rev_asum_pow % MOD * (cnt + 1) % MOD * aall % MOD * rev[asum] % MOD
            if p == 1:
                ans += x
            else:
                ans -= x
            ans %= MOD

if ans < 0:
    ans += MOD

print(ans)

# <END-OF-CODE>
