
import sys
import math
import bisect
import numpy as np
from decimal import Decimal
from numba import njit, i8, u1, b1
from collections import defaultdict as dd, deque as dq, Counter as dc
from itertools import permutations as perm, combinations as comb
from fractions import Fraction as fr

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    for i in range(n - 1):
        if a[i] == a[i + 1]:
            print("NO")
            return
    print("YES")

def main():
    solve()

if __name__ == "__main__":
    main()

