# thx Ebi-chan!

import sys
import math
from collections import deque
from heapq import heappush, heappop
from itertools import permutations, product

# sys.setrecursionlimit(10**6)

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
    l = left[0]
    r = right[0]
    if l < r:
        return -1
    if l > r:
        return 1
    return 0

def prevcomp(left, right):
    l = left[0]
    r = right[0]
    if l < r:
        return 1
    if l > r:
        return -1
    return 0

def psllcomp(left, right):
    l = left[0]
    r = right[0]
    if l < r:
        return -1
    if l > r:
        return 1
    return 0

def pcharcomp(left, right):
    l = left[0]
    r = right[0]
    if l < r:
        return -1
    if l > r:
        return 1
    return 0

def pdoublecomp(left, right):
    l = left[0]
    r = right[0]
    if l < r:
        return -1
    if l > r:
        return 1
    return 0

def pstrcomp(left, right):
    l = left[0]
    r = right[0]
    return cmp(l, r)

def phwllABcomp(left, right):
    l = left[0]
    r = right[0]
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
    l = left[0]
    r = right[0]
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
    l = left[0]
    r = right[0]
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
    l = left[0]
    r = right[0]
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
    l = left[0]
    r = right[0]
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
    l = left[0]
    r = right[0]
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
    l = left[0]
    r = right[0]
    ac = phwllABcomp(l.a, r.a)
    if ac != 0: return ac
    bc = phwllABcomp(l.b, r.b)
    if bc != 0: return bc
    return 0

def pfracomp(left, right):
    l = left[0]
    r = right[0]
    return -1 if l.a * r.b < l.b * r.a else 1 if l.a * r.b > l.b * r.a else 0

def isinrange(left, x, right):
    return left <= x <= right

def isinrange_soft(left, x, right):
    return (left <= x <= right) or (left >= x >= right)

def sw(l, r):
    if l == r: return
    l, r = r, l

def ncr(n, r, m):
    if n < 0 or r < 0 or n < r: return 0
    return frac[n] * (invf[r] * invf[n - r] % m) % m

# Here we go

n = 4
m = 0

# m = int(input())
# h, w = map(int, input().split())
n, m = map(int, input().split())
# k, n, m = map(int, input().split())
# h, w = map(int, input().split())
# q = int(input())
# va, vb, vc, vd, ve, vf = map(int, input().split())
# ua, ub, uc, ud, ue, uf = map(int, input().split())
s = input()
# t = input()
# u = input()
# k = int(input())
# m = int(input())
# a = [int(input()) for _ in range(n)]
# b = [int(input()) for _ in range(n)]
# c = [int(input()) for _ in range(n)]
# d = [int(input()) for _ in range(n)]
# xy = [tuple(map(int, input().split())) for _ in range(n)]
# tup = [tuple(map(int, input().split())) for _ in range(n)]
# c = [int(input()) for _ in range(q)]

# for i in range(n):
#     a[i], b[i] = map(int, input().split())
#     a[i] -= 1
#     b[i] -= 1
#     c[i] -= 1
#     d[i] -= 1
#     xy[i] = (xy[i][0] - 1, xy[i][1] - 1)
#     tup[i] = (tup[i][0] - 1, tup[i][1] - 1, tup[i][2] - 1)

# for i in range(q):
#     c[i] = int(input())
#     c[i] -= 1

# for i in range(h):
#     s[i] = input()

def solve():
    i, j, ki, li = 0, 0, 0, 0
    result = 1
    pcnt = 0
    cnt = [0, 0, 0]

    for i in range(n * 3):
        v = 0
        if s[i] == 'R':
            v = 0
        elif s[i] == 'G':
            v = 1
        elif s[i] == 'B':
            v = 2

        if cnt[(v + 1) % 3] and cnt[(v + 2) % 3]:
            result = (result * pcnt) % FOD
            pcnt -= 1
            result %= FOD
            cnt[(v + 1) % 3] -= 1
            cnt[(v + 2) % 3] -= 1
        else:
            if (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]:
                result = (result * ((cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v])) % FOD
                pcnt += 1
            cnt[v] += 1

    result = (result * math.factorial(n)) % FOD
    print(result)

solve()

