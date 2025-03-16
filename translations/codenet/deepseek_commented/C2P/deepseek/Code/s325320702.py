# Utility Functions
def swap(a, b):
    return b, a

def cin(n):
    *n = map(int, input().split())

def max2(a, b):
    return a if a >= b else b

def min2(a, b):
    return b if a >= b else a

def min3(a, b, c):
    return a if a <= b and a <= c else b if b <= c else c

def max3(a, b, c):
    return a if a >= b and a >= c else b if b >= c else c

def minn(n, a):
    b = float('inf')
    for i in range(n):
        b = min(b, a[i])
    return b

def maxn(n, a):
    b = -float('inf')
    for i in range(n):
        b = max(b, a[i])
    return b

def POW(a, b):
    c = 1
    for _ in range(b):
        c *= a
    return c

def POW_d(a, b):
    c = 1.0
    for _ in range(b):
        c *= a
    return c

def gcd(a, b):
    return gcd(b, a % b) if b else a

def lcm(a, b):
    return a // gcd(a, b) * b

def mod_MOD1(n):
    n = (n + (-n // MOD1 + 1) * MOD1) % MOD1
    return n

def mod_p(n, p):
    n = (n + (-n // p + 1) * p) % p
    return n

def change_into_num(s, len, p):
    return 0 if p == 0 else (ord(s[len - p]) - ord('0')) * POW(10, p - 1) + change_into_num(s, len, p - 1)

def digits(a, b):
    return 1 if a < b else 1 + digits(a // b, b)

def base(n, a, i):
    return base(n // a, a, i - 1) if i == 1 else n % a

def is_inArr1(x, n):
    return 0 if x < 0 or x >= n else 1

def is_inArr2(y, x, h, w):
    return 0 if y < 0 or y >= h or x < 0 or x >= w else 1

# Main Function
l, r, d = map(int, input().split())
ans = 0
for i in range(l, r + 1):
    if i % d == 0:
        ans += 1
print(ans)
