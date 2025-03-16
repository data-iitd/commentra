
import sys
input = sys.stdin.readline

mod = 10**9+7
NMAX = 10**6+10

fac = [0]*NMAX
finv = [0]*NMAX
inv = [0]*NMAX

def init():
    fac[0] = fac[1] = 1
    finv[0] = finv[1] = 1
    inv[1] = 1
    for i in range(2, NMAX):
        fac[i] = fac[i-1] * i % mod
        inv[i] = mod - inv[mod%i] * (mod//i) % mod
        finv[i] = finv[i-1] * inv[i] % mod

def C(n, k):
    if n < k: return 0
    if n < 0 or k < 0: return 0
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod

init()
X, Y = map(int, input().split())
if (X+Y) % 3!= 0:
    print(0)
    exit()
n = (X+Y) // 3+1
k = 2*(n-1) - Y + 1 # y = 2xより最も上にくる点からどれだけ離れているか。
print(C(n-1, k-1))

