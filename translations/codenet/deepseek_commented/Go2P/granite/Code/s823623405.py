
import sys

def main():
    n = int(input())
    a = list(map(int, input().split()))
    ps = {}
    for i in range(n):
        ns = prime_factorize(a[i])
        for k, v in ns.items():
            ps[k] = max(ps.get(k, 0), v)
    x = 1
    for k, v in ps.items():
        x = mul(x, pow(k, v))
    ans = 0
    for i in range(n):
        ans = add(ans, div(x, a[i]))
    print(ans)

def max(a, b):
    if a > b:
        return a
    return b

def prime_factorize(n):
    res = {}
    for i in range(2, int(n**0.5)+1):
        while n % i == 0:
            n //= i
            res[i] = res.get(i, 0) + 1
    if n!= 1:
        res[n] = res.get(n, 0) + 1
    return res

mod = 1000000007

def pow(n, k):
    if k == 0:
        return 1
    elif k % 2 == 1:
        return pow(n, k-1) * n % mod
    else:
        t = pow(n, k//2)
        return t * t % mod

def add(a, b):
    return (a + b) % mod

def sub(a, b):
    return (a + mod - b) % mod

def mul(a, b):
    return a % mod * b % mod % mod

def div(a, b):
    return mul(a, pow(b, mod-2))

if __name__ == "__main__":
    main()

