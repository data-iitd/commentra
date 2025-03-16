
import sys
import math
import bisect
from sys import stdin, stdout
from math import gcd, floor, sqrt, log2, ceil
from collections import defaultdict as dd
from bisect import bisect_left as bl, bisect_right as br
from bisect import insort
from collections import Counter
from collections import deque
from heapq import heappush,heappop,heapify
from itertools import permutations,combinations
mod = int(1e9)+7

# Fast IO
def input(): return stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def mod(): return 10**9+7

# Your code goes here
n = INT()
m = INT()

bannedRows = set()
bannedCols = set()

for i in range(m):
    r = INT()
    c = INT()
    if r > 1 and r < n:
        bannedRows.add(r)
    if c > 1 and c < n:
        bannedCols.add(c)

ans = (n-2)*2
ans -= len(bannedRows)
ans -= len(bannedCols)

if n % 2!= 0:
    mid = (n+1)//2
    if mid not in bannedRows and mid not in bannedCols:
        ans -= 1

print(ans)

# End of code