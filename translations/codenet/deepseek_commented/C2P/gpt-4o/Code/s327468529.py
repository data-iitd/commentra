import sys
from collections import defaultdict

MOD = 998244353

def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

def bitpow(a, x, modulo):
    result = 1
    while x:
        if x & 1:
            result = (result * a) % modulo
        x //= 2
        a = (a * a) % modulo
    return result

def divide(a, b, modulo):
    return (a * bitpow(b, modulo - 2, modulo)) % modulo

def ncr(n, r, m):
    if n < 0 or r < 0 or n < r:
        return 0
    return (frac[n] * (invf[r] * invf[n - r] % m)) % m

def solve(n, s):
    cnt = [0, 0, 0]
    pcnt = 0
    result = 1

    for i in range(n * 3):
        if s[i] == 'R':
            v = 0
        elif s[i] == 'G':
            v = 1
        elif s[i] == 'B':
            v = 2

        if cnt[(v + 1) % 3] and cnt[(v + 2) % 3]:
            result *= pcnt
            pcnt -= 1
            result %= MOD
            cnt[(v + 1) % 3] -= 1
            cnt[(v + 2) % 3] -= 1
        else:
            if (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]:
                result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v]
                result %= MOD
                pcnt += 1

            cnt[v] += 1

    for i in range(1, n + 1):
        result = (result * i) % MOD

    print(result)

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    m = 0
    s = sys.stdin.readline().strip()

    solve(n, s)

# <END-OF-CODE>
