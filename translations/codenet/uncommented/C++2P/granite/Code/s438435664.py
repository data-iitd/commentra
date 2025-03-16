
import sys

def gcd(x, y):
    tmp = 0
    if x < y:
        tmp = x
        x = y
        y = tmp
    while y > 0:
        r = x % y
        x = y
        y = r
    return x

def lcm(x, y):
    return x // gcd(x, y) * y

def kaijo(k):
    sum = 1
    for i in range(1, k + 1):
        sum *= i
        sum %= 1000000000 + 7
    return sum

def lmax(s, t):
    if s > t:
        return s
    else:
        return t

def lmin(s, t):
    if s < t:
        return s
    else:
        return t

n, k = map(int, sys.stdin.readline().split())
sum = 0
for b in range(1, n + 1):
    cnt = (n + 1) // b
    md = (n + 1) % b
    sum += cnt * max(b - k, 0) + max(md - k, 0)
    if k == 0:
        sum -= 1
print(sum)

