
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

# Define necessary aliases for common data types and containers

def read(): return sys.stdin.readline().strip()
def getInt(): return int(read())
def getlist(): return list(map(int, read().split()))
def getlist2(n): return[list(map(int, read().split())) for i in range(n)]
def getlist3(n): return[list(map(int, read().split())) for j in range(n) for i in range(n)]
def is_prime(n):
    if n <= 1: return False
    if n == 2: return True
    if n % 2 == 0: return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0: return False
    return True

# Define helper functions for input reading and prime number checking

def main():
    N, K = getlist()
    A = getlist()
    cur = 1
    dic = [-1] * (N + 1)
    flg = False
    for i in range(1, K + 1):
        if dic[cur] < 0 or flg:
            dic[cur] = i
            cur = A[cur - 1]
        else:
            tmp = K - (dic[cur] - 1)
            tmp %= i - dic[cur]
            i = K - tmp
            flg = True
    print(cur)

if __name__ == "__main__":
    main()

Translate the above Python code to C++ and end with comment "