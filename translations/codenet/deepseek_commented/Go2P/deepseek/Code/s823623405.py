MOD = 1000000007

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

def pow(n, k):
    if k == 0:
        return 1
    elif k % 2 == 1:
        return pow(n, k - 1) * n % MOD
    else:
        t = pow(n, k // 2)
        return t * t % MOD

def add(a, b):
    return (a + b) % MOD

def sub(a, b):
    return (a + MOD - b) % MOD

def mul(a, b):
    return a % MOD * b % MOD % MOD

def div(a, b):
    return mul(a, pow(b, MOD - 2))

def main():
    n = int(input())
    as_ = list(map(int, input().split()))
    ps = {}

    for a in as_:
        ns = prime_factorize(a)
        for k, v in ns.items():
            ps[k] = max(ps.get(k, 0), v)

    x = 1
    for k, v in ps.items():
        for _ in range(1, v + 1):
            x = mul(x, k)

    ans = 0
    for a in as_:
        ans = add(ans, div(x, a))

    print(ans)

main()
