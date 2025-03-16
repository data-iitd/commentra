
import sys
import math
import bisect
import numpy as np
from decimal import Decimal
from numba import njit, i8, u1

# Macros for convenience
MOD = 10 ** 9 + 7
INF = float('inf')
PI = acos(-1.0)
EPS = 1e-9

# Read input from file or stdin
def read_int():
    return int(input())

def read_ints():
    return list(map(int, input().split()))

def read_str():
    return input().strip()

def read_strs():
    return input().strip().split()

# Write output to file or stdout
def write(*args, end='\n'):
    x = ''
    for a in args:
        x += str(a)
    sys.stdout.write(x + end)

# Debug print, only works on local machine
LOCAL = False

def dprint(*args, end='\n'):
    if LOCAL:
        write(*args, end=end)

# Functions for input/output
def solve():
    k, a, b = read_ints()
    for i in range(a, b + 1):
        if i % k == 0:
            write('OK')
            return
    write('NG')

# Main function
def main():
    t = 1
    # t = read_int()
    for i in range(t):
        solve()

if __name__ == "__main__":
    main()

Translate the above Python code to Java and end with comment "