import sys
from math import *
from collections import deque, defaultdict, Counter
from itertools import accumulate, permutations, combinations
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop
from string import ascii_lowercase
from functools import lru_cache

# 定数
_USE_MATH_DEFINES = True
EPS = 1e-7
INF = 1e9
PI = acos(-1)

# 便利関数
def input(): return sys.stdin.readline().strip()
def debug(x): print(f"[DEBUG] {x}", file=sys.stderr)
def end_of_code(): print("<END-OF-CODE>")