
import sys
import math
import bisect
import heapq
from collections import deque
from collections import Counter
from itertools import combinations
from itertools import permutations
import fractions

# ---------------------------------------------------------
def solve():
    n = int(input())
    x = int(input())
    a = list(map(int, input().split()))
    v = a[:]

    ans = float('inf')
    for k in range(n):
        kans = 0
        for i in range(n):
            if i-k < 0:
                v[i] = min(v[i], a[n+i-k])
            else:
                v[i] = min(v[i], a[i-k])
            kans += v[i]
        ans = min(ans, kans+k*x)

    print(ans)

# ---------------------------------------------------------
solve()
# ---------------------------------------------------------
