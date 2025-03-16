# thx Ebi-chan!

import sys
import math
import heapq
import bisect
import array
from collections import deque, Counter, OrderedDict, defaultdict

# sys.setrecursionlimit(100000)

input = sys.stdin.readline

BIG = 2000000007
VERYBIG = 20000000000000007

MOD = 1000000007
FOD = 998244353

N_MAX = 1048576

def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x % y)

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

def udiff(a, b):
    return a - b if a >= b else b - a

def sdiff(a, b):
    return a - b if a >= b else b - a

def bitcount(n):
    result = 0
    while n:
        if n & 1: result += 1
        n //= 2
    return result

def pullcomp(left, right):
    l = left
    r = right
    if l < r:
        return -1
    if l > r:
        return 1
    return 0

def prevcomp(left, right):
    l = left
    r = right
    if l < r:
        return -1
    if l > r:
        return 1
    return 0

def psllcomp(left, right):
    l = left
    r = right
    if l < r:
        return -1
    if l > r:
        return 1
    return 0

def pcharcomp(left, right):
    l = left
    r = right
    if l < r:
        return -1
    if l > r:
        return 1
    return 0

def pdoublecomp(left, right):
    l = left
    r = right
    if l < r:
        return -1
    if l > r:
        return 1
    return 0

def pstrcomp(left, right):
    l = left
    r = right
    return cmp(l, r)

def phwllABcomp(left, right):
    l = left
    r = right
    if l.a < r.a:
        return -1
    if l.a > r.a:
        return 1
    if l.b < r.b:
        return -1
    if l.b > r.b:
        return 1
    return 0

def phwllREVcomp(left, right):
    l = left
    r = right
    if l.b < r.b:
        return -1
    if l.b > r.b:
        return 1
    if l.a < r.a:
        return -1
    if l.a > r.a:
        return 1
    return 0

def ptriplecomp(left, right):
    l = left
    r = right
    if l.a < r.a:
        return -1
    if l.a > r.a:
        return 1
    if l.b < r.b:
        return -1
    if l.b > r.b:
        return 1
    if l.c < r.c:
        return -1
    if l.c > r.c:
        return 1
    return 0

def ptripleREVcomp(left, right):
    l = left
    r = right
    if l.b < r.b:
        return -1
    if l.b > r.b:
        return 1
    if l.a < r.a:
        return -1
    if l.a > r.a:
        return 1
    if l.c < r.c:
        return -1
    if l.c > r.c:
        return 1
    return 0

def ptripleCABcomp(left, right):
    l = left
    r = right
    if l.c < r.c:
        return -1
    if l.c > r.c:
        return 1
    if l.a < r.a:
        return -1
    if l.a > r.a:
        return 1
    if l.b < r.b:
        return -1
    if l.b > r.b:
        return 1
    return 0

def phwrealcomp(left, right):
    l = left
    r = right
    if l.a < r.a:
        return -1
    if l.a > r.a:
        return 1
    if l.b < r.b:
        return -1
    if l.b > r.b:
        return 1
    return 0

def pquadcomp(left, right):
    l = left
    r = right
    ac = phwllABcomp(&l.a, &r.a)
    if ac: return ac
    bc = phwllABcomp(&l.b, &r.b)
    if bc: return bc
    return 0

def pfracomp(left, right):
    l = left
    r = right
    return sdiff(l.a * r.b, l.b * r.a)

def isinrange(left, x, right):
    return left <= x <= right

def isinrange_soft(left, x, right):
    return (left <= x <= right) or (left >= x >= right)

def sw(l, r):
    if l == r: return
    t = l
    l = r
    r = t

frac = [0] * (N_MAX * 3)
invf = [0] * (N_MAX * 3)

def ncr(n, r, m):
    if n < 0 or r < 0 or n < r: return 0
    return frac[n] * (invf[r] * invf[n - r] % m) % m

a = [0] * (N_MAX + 5)
b = [0] * (N_MAX + 5)
c = [0] * (N_MAX + 5)
d = [0] * (N_MAX + 5)
e = [0] * (N_MAX * 4)
s = [0] * (N_MAX + 1)
t = [0] * (N_MAX + 1)
u = [0] * (N_MAX + 1)
xy = [0] * (N_MAX + 5)
tup = [0] * (N_MAX + 5)
table = [[0] * 3005 for _ in range(3005)]
gin = [0] * N_MAX

def solve():
    i, j, ki, li = 0, 0, 0, 0
    result = 0
    maybe = 0
    sum = 0
    item = 0
    dpcell = None

    result = 1
    for i in range(n * 3):
        v = 0
        if s[i] == 'R':
            v = 0
        elif s[i] == 'G':
            v = 1
        elif s[i] == 'B':
            v = 2

        if cnt[(v + 1) % 3] and cnt[(v + 2) % 3]:
            result *= pcnt
            result %= FOD
            pcnt -= 1
            cnt[(v + 1) % 3] -= 1
            cnt[(v + 2) % 3] -= 1
        else:
            if (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]:
                result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v]
                result %= FOD
                pcnt += 1
            cnt[v] += 1

    for i in range(1, n + 1):
        result = (result * i) % FOD

    print(result)

n = 4
m = 0

# m = int(input().strip())
# h, w = map(int, input().strip().split())
n, m = map(int, input().strip().split())
# k, n, m = map(int, input().strip().split())
# h, w = map(int, input().strip().split())
# q = int(input().strip())
# va, vb, vc, vd, ve, vf = map(int, input().strip().split())
# ua, ub, uc, ud, ue, uf = map(int, input().strip())
s = input().strip()
# t = input().strip()
# u = input().strip()
# k = int(input().strip())
# m = int(input().strip())
# for i in range(n):
#     a[i] = int(input().strip())
#     b[i] = int(input().strip())
#     c[i] = int(input().strip())
#     d[i] = int(input().strip())
#     a[i] -= 1
#     b[i] -= 1
#     c[i] -= 1
#     d[i] -= 1
#     xy[i].a -= 1
#     xy[i].b -= 1
#     tup[i].a -= 1
#     tup[i].b -= 1
# m = int(input().strip())
# q = int(input().strip())
# for i in range(q):
#     xy[i].a = int(input().strip())
#     xy[i].b = int(input().strip())
#     xy[i].a -= 1
#     xy[i].b -= 1
# for i in range(h):
#     for j in range(w):
#         table[i][j] = int(input().strip())
#         table[i][j] -= 1
# for i in range(h):
#     s[i] = input().strip()
# q = int(input().strip())

solve()
