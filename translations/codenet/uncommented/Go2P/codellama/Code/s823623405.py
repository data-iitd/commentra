
import sys

def main():
    n = int(sys.stdin.readline())
    as = list(map(int, sys.stdin.readline().split()))
    ps = {}
    for i in range(n):
        ns = prime_factorize(as[i])
        for k, v in ns.items():
            ps[k] = max(ps.get(k, 0), v)

    x = 1
    for k, v in ps.items():
        for i in range(v):
            x = mul(x, k)

    ans = 0
    for i in range(n):
        ans = add(ans, div(x, as[i]))
    print(ans)

def prime_factorize(n):
    res = {}
    for i in range(2, int(n**0.5)+1):
        while n % i == 0:
            n //= i
            res[i] = res.get(i, 0) + 1
    if n != 1:
        res[n] = res.get(n, 0) + 1
    return res

def max(a, b):
    if a > b:
        return a
    return b

def mul(a, b):
    return a % mod * b % mod % mod

def add(a, b):
    return (a + b) % mod

def sub(a, b):
    return (a + mod - b) % mod

def div(a, b):
    return mul(a, pow(b, mod-2))

def pow(n, k):
    if k == 0:
        return 1
    elif k % 2 == 1:
        return pow(n, k-1) * n % mod
    else:
        t = pow(n, k//2)
        return t * t % mod

if __name__ == '__main__':
    main()

