
MOD2 = 1000000007
MOD = 998244353
INF = (1<<30)-1
LINF = (1<<60)
EPS = 1e-10

fact = [1]*1100000
revfact = [1]*1100000
rev = [0]*1100000
rev[1] = 1

def init():
    m = MOD
    fact[0] = 1
    revfact[0] = 1
    for i in range(1, 1100000):
        fact[i] = fact[i-1]*i%m
        if i > 1:
            rev[i] = m//i*(m-rev[m%i])%m
        revfact[i] = revfact[i-1]*rev[i]%m

comb = [[0]*1100 for _ in range(1100)]

def nCk(n, k):
    if n < k: return 0
    if comb[n][k]!= 0: return comb[n][k]
    res = comb[n][k] = fact[n]*revfact[n-k]%MOD*revfact[k]%MOD
    return res

def mod_pow(x, a, m=MOD):
    if a == 0: return 1
    res = mod_pow(x, a//2, m)
    res = res*res%m
    if a % 2: res *= x
    return res % m

def inv(x, m=MOD):
    return mod_pow(x, m-2, m)

aall, ball = 0, 0
n, ans = 0, 0
a, b = [], []
dp = [[[[0]*2 for _ in range(2)] for _ in range(440)] for _ in range(440)]

init()
n = int(input())
for i in range(n):
    a_i, b_i = map(int, input().split())
    a.append(a_i)
    b.append(b_i)
    aall += a_i
    ball += b_i

dp[0][0][0][0] = 1
for i in range(1, n+1):
    id = i % 2
    for asum in range(aall, -1, -1):
        for cnt in range(ball+1):
            for p in range(2):
                if asum - a[i-1] < 0: continue
                pw = 1
                for use in range(b[i-1]):
                    if cnt - use >= 0:
                        tmp = nCk(cnt, use)
                        dp[asum][cnt][p][0] += dp[asum - a[i-1]][cnt - use][p^1][0]*tmp
                        dp[asum][cnt][p][1] += dp[asum - a[i-1]][cnt - use][p^1][1]*tmp
                    else: break
                    pw = pw * a[i-1] % MOD
                if cnt - b[i-1] + 1 >= 0:
                    dp[asum][cnt][p][1] += dp[asum - a[i-1]][cnt - b[i-1] + 1][p^1][0]*nCk(cnt, b[i-1]-1)*pw
                dp[asum][cnt][p][0] %= MOD
                dp[asum][cnt][p][1] %= MOD

for asum in range(aall+1):
    rev_asum_pow = 1
    for cnt in range(ball+1):
        rev_asum_pow = rev_asum_pow * rev[asum] % MOD
        for p in range(2):
            x = dp[asum][cnt][p][1]*rev_asum_pow*(cnt+1)*aall*rev[asum] % MOD
            if p == 1: ans += x
            else: ans -= x
            ans %= MOD

if ans < 0: ans += MOD
print(ans)

