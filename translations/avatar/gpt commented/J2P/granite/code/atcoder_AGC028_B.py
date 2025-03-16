
import sys

def modinv(a, m):
    b = m
    u = 1
    v = 0
    while b:
        t = a // b
        a -= t * b
        tmp = a
        a = b
        b = tmp
        u -= t * v
        tmp = u
        u = v
        v = tmp
    u %= m
    return u

def main():
    n = int(input())
    a = list(map(int, input().split()))
    mod = 1000000007
    p = 1
    for i in range(2, n + 1):
        p = p * i % mod
    q = [1] * n
    for i in range(1, n):
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod
    ans = 0
    for i in range(n):
        val = q[i] + q[n - i - 1] - 1
        val = val * a[i] % mod
        val = val * p % mod
        ans = (ans + val) % mod
    print(ans)

if __name__ == "__main__":
    sys.exit(main())

