import sys
import math
from bisect import bisect_left

# ReadString = newReadString(sys.stdin, bufio.ScanWords)
# PrintIntsLine = printIntsLine

# General purpose
MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = math.inf
INF_BIT60 = 1 << 60
INF_INT32 = math.inf
INF_BIT30 = 1 << 30
NIL = -1

# for dijkstra, prim, and so on
WHITE = 0
GRAY = 1
BLACK = 2

# Read input
n, q = map(int, input().split())
C = list(map(int, input().split()))
Q = [tuple(map(int, input().split())) for _ in range(q)]

# Initialize P array and Fenwick Tree
P = [-1] * (500000 + 50)
Answers = [0] * q

class FenwickTree:
    def __init__(self, n):
        self.dat = [0] * (n + 1)
        self.n = n
        self.minPow2 = 1
        while (self.minPow2 << 1) <= n:
            self.minPow2 <<= 1

    # Sum of [1, i](1-based)
    def Sum(self, i):
        s = 0
        while i > 0:
            s += self.dat[i]
            i -= i & (-i)
        return s

    # Add x to i(1-based)
    def Add(self, i, x):
        while i <= self.n:
            self.dat[i] += x
            i += i & (-i)

    # LowerBound returns minimum i such that bit.Sum(i) >= w.
    def LowerBound(self, w):
        if w <= 0:
            return 0
        x = 0
        for k in range(self.minPow2, 0, -1):
            if x + k <= self.n and self.dat[x + k] < w:
                w -= self.dat[x + k]
                x += k
        return x + 1

# Process queries
k = 0
for l, r in Q:
    while k < r:
        if P[C[k]] != -1:
            ft.Add(P[C[k]] + 1, -1)
        P[C[k]] = k
        ft.Add(k + 1, 1)
        k += 1
    Answers[Q.index((l, r))] = ft.Sum(r) - ft.Sum(l - 1)

# Print answers
for answer in Answers:
    print(answer)
