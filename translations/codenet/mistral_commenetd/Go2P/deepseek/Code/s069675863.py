import sys
import os
import io
import math
import bisect
import collections
import itertools
import heapq
import random
import time
import copy
import functools
from operator import xor
from bisect import bisect_left, bisect_right
from collections import deque, Counter, defaultdict
from heapq import heappush, heappop
from itertools import permutations, combinations, product, accumulate
from functools import lru_cache, reduce

# fmt.Sprintf("%b\n", 255) 	# binary expression

#str := ReadString()
#i := ReadInt()
#X := ReadIntSlice(n)
#S := ReadRuneSlice()
#a := ReadFloat64()
#A := ReadFloat64Slice(n)

#str := ZeroPaddingRuneSlice(num, 32)
#str := PrintIntsLine(X...)

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = math.inf
INF_BIT60 = 1 << 60
INF_INT32 = math.inf
INF_BIT30 = 1 << 30
NIL = -1

WHITE = 0
GRAY = 1
BLACK = 2

input = sys.stdin.readline

def init():
    global S, x, y
    S = list(input().strip())
    x, y = map(int, input().split())

def make2DBooleanArray(rows, cols):
    dpx = [[False] * cols for _ in range(rows)]
    dpy = [[False] * cols for _ in range(rows)]
    return dpx, dpy

def updateDPX(index, val):
    for j in range(2000, 18000):
        if j + val <= 18000:
            dpx[index + 1][j + val] = dpx[index + 1][j + val] or dpx[index][j]
        if j - val >= 2000 and index != 0:
            dpx[index + 1][j - val] = dpx[index + 1][j - val] or dpx[index][j]

def updateDPY(index, val):
    for j in range(2000, 18000):
        if j + val <= 18000:
            dpy[index + 1][j + val] = dpy[index + 1][j + val] or dpy[index][j]
        if j - val >= 2000:
            dpy[index + 1][j - val] = dpy[index + 1][j - val] or dpy[index][j]

def main():
    init()
    dpx, dpy = make2DBooleanArray(8000, 20000)
    evens = []
    odds = []
    for i in range(len(S)):
        if S[i] == 'T':
            if i % 2 == 0:
                evens.append(i)
            else:
                odds.append(i)
    for i in range(len(evens)):
        updateDPX(i, evens[i])
    for i in range(len(odds)):
        updateDPY(i, odds[i])
    if dpx[len(evens)][x + 10000] and dpy[len(odds)][y + 10000]:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
