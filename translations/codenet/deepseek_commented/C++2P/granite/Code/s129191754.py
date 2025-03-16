
import sys
import math
import bisect
import numpy as np
from decimal import Decimal
from numba import njit, i8, u1, b1
from collections import defaultdict as dd, deque as dq, Counter as dc
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect
from heapq import heappush as hpush, heappop as hpop
from math import factorial

# Constants
MOD = 10**9 + 7
INF = float('inf')

# Read input
def read(): return sys.stdin.readline().strip()
def read_int(): return int(sys.stdin.readline().strip())
def read_arr(): return list(map(int, sys.stdin.readline().strip().split()))
def read_str(): return sys.stdin.readline().strip()
def read_str_arr(): return sys.stdin.readline().strip().split()

def solve():
    n = read_int()
    a = read_arr()
    a.sort()
    for i in range(n - 1):
        if a[i] == a[i + 1]:
            print("NO")
            return
    print("YES")

# Main
if __name__ == "__main__":
    solve()

