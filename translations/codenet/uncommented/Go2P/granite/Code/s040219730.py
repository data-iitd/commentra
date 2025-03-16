

import sys
import io
import os
import math
import heapq
import queue
import bisect
import collections
import itertools
import decimal
import statistics
import operator

# Read functions
def read_str():
    return input()

def read_int():
    return int(input())

def read_int_n():
    return list(map(int, input().split()))

def read_float():
    return float(input())

def read_float_n():
    return list(map(float, input().split()))

def read_str_n():
    return input().split()

def read_str_list():
    return list(input())

def error_exit(message=""):
    print(message)
    sys.exit()

# Write functions
def write_str(s):
    sys.stdout.write(s)

def write_int(n):
    sys.stdout.write(str(n))

def write_int_n(A):
    sys.stdout.write(" ".join(map(str, A)))

def write_float(f):
    sys.stdout.write("%.15f" % f)

def write_float_n(A):
    sys.stdout.write(" ".join(map(str, A)))

def write_str_n(A):
    sys.stdout.write("".join(A))

# Constants
MOD = 1000000000 + 7
INF = float('inf')

# Python port of the given Go code

# Initialize
n, q = read_int_n()
C = read_int_n()
Q = []
for _ in range(q):
    l, r = read_int_n()
    Q.append((l, r))

# Binary indexed tree (Fenwick tree)
class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.data = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.data[i]
            i -= i & (-i)
        return s

    def add(self, i, x):
        while i <= self.n:
            self.data[i] += x
            i += i & (-i)

# Initialize
ft = FenwickTree(500000 + 50)
P = [-1] * (n + 1)
answers = [0] * q

# Main
k = 0
for l, r in Q:
    while k < r:
        if P[C[k]]!= -1:
            ft.add(P[C[k]] + 1, -1)
        P[C[k]] = k
        ft.add(k + 1, 1)
        k += 1

    answers[l - 1] = ft.sum(r) - ft.sum(l - 1)

# Output
for a in answers:
    write_int(a)
    write_str("\n")

sys.stdout.flush()

