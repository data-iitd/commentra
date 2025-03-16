
import sys

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def get_prime_factor(n):
    res = {}
    i = 2
    while i * i <= n:
        while n % i == 0:
            res[i] = res.get(i, 0) + 1
            n //= i
        i += 1
    if n!= 1:
        res[n] = 1
    return res

def is_prime_number(num):
    if num <= 2:
        return True
    elif num % 2 == 0:
        return False
    sqrt_num = int(num ** 0.5) + 1
    for i in range(3, sqrt_num, 2):
        if num % i == 0:
            return False
    return True

def modinv(a, m):
    b, u, v = m, 1, 0
    while b:
        t = a // b
        a -= t * b
        a, b = b, a
        u -= t * v
        u, v = v, u
    u %= m
    if u < 0:
        u += m
    return u

N, K = map(int, input().split())
A = [0] + list(map(int, input().split()))
cur = 1
dic = [-1] * (N + 1)
flg = False

for i in range(1, K + 1):
    if dic[cur] < 0 or flg:
        dic[cur] = i
        cur = A[cur]
    else:
        tmp = K - (dic[cur] - 1)
        tmp %= i - dic[cur]
        i = K - tmp
        flg = True

print(cur)

