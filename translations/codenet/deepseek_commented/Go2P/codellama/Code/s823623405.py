
import sys

def main():
    n = int(sys.stdin.readline())
    as = [int(sys.stdin.readline()) for _ in range(n)]
    ps = {}
    for a in as:
        ns = prime_factorize(a)
        for k, v in ns.items():
            ps[k] = max(ps.get(k, 0), v)
    x = 1
    for k, v in ps.items():
        for i in range(1, v+1):
            x = mul(x, k)
    ans = 0
    for a in as:
        ans = add(ans, div(x, a))
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
    if n != 1:
        res[n] = res.get(n, 0) + 1
    return res

def pow(n, k):
    if k == 0:
        return 1
    elif k % 2 == 1:
        return pow(n, k-1) * n % 1000000007
    else:
        t = pow(n, k//2)
        return t * t % 1000000007

def add(a, b):
    return (a + b) % 1000000007

def sub(a, b):
    return (a + 1000000007 - b) % 1000000007

def mul(a, b):
    return a % 1000000007 * b % 1000000007 % 1000000007

def div(a, b):
    return mul(a, pow(b, 1000000006))


