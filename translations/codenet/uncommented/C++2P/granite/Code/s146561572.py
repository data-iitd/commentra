
import sys
import os
import time
import collections
import math
import bisect
import heapq
import decimal
import statistics
import itertools

# import numpy as np

# input = sys.stdin.readline
# flush = sys.stdout.flush

# import resource
# import sys

# resource.setrlimit(resource.RLIMIT_STACK, [0x10000000, resource.RLIM_INFINITY])
# sys.setrecursionlimit(0x100000)

# mod = 10**9 + 7
# inf = 10**18 + 1
# decimal.getcontext().prec = 20

# MAX = 10**3
# MOD = 10**9 + 7
# MOD = 998244353

PI = 3.141592653589793238460

def solve():
    ans = 0
    n = int(input())
    # Contribution of The Nodes.
    for i in range(1, n + 1):
        ans += i * (n - i + 1)
    for i in range(1, n):
        u, v = map(int, input().split())
        a = max(u, v)
        b = min(u, v)
        ans -= b * (n - a + 1)
    print(ans)

t = 1
# t = int(input())
for _ in range(t):
    solve()

print("END-OF-CODE")
