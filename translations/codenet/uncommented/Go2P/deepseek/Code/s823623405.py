def max(a, b):
    return a if a > b else b

def prime_factorize(n):
    res = {}
    i = 2
    while i * i <= n:
        while n % i == 0:
            n //= i
            res[i] = res.get(i, 0) + 1
        i += 1
    if n != 1:
        res[n] = 1
    return res

mod = 1000000007

def pow(n, k):
    if k == 0:
        return 1
    elif k % 2 == 1:
        return pow(n, k - 1) * n % mod
    else:
        t = pow(n, k // 2)
        return t * t % mod

def add(a, b):
    return (a + b) % mod

def sub(a, b):
    return (a + mod - b) % mod

def mul(a, b):
    return a % mod * b % mod % mod

def div(a, b):
    return mul(a, pow(b, mod - 2))

def main():
    n = int(input())
    as_ = [int(input()) for _ in range(n)]
    ps = {}

    for a in as_:
        ns = prime_factorize(a)
        for k, v in ns.items():
            ps[k] = max(ps.get(k, 0), v)

    x = 1
    for k, v in ps.items():
        for _ in range(v):
            x = mul(x, k)

    ans = 0
    for a in as_:
        ans = add(ans, div(x, a))

    print(ans)

main()
