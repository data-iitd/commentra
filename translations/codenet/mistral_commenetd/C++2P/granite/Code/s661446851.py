
# Bismillahir Rahmanir Rahim
# Created by Abdul Aziz

import sys
import math
import bisect
import heapq
from collections import deque
from collections import defaultdict
from collections import Counter
from itertools import combinations
from itertools import permutations

input = lambda: sys.stdin.readline().rstrip("\r\n")
intput = lambda: int(input())
ints = lambda: list(map(int, input().split()))

def solve():
    n = intput()
    if n <= 0:
        print(0)
    else:
        print(1)

t = 1
t = intput()
for _ in range(t):
    solve()

# 