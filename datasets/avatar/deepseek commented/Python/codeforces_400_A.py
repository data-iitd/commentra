import collections
import heapq
import sys
import math
import itertools
import bisect
from io import BytesIO, IOBase
import os

# Function to read a single value from input
def value():
    return tuple(map(int, input().split()))

# Function to read multiple values from input
def values():
    return tuple(map(int, sys.stdin.readline().split()))

# Function to read a list of integers from input
def inlst():
    return [int(i) for i in input().split()]

# Function to read a list of integers from stdin
def inlsts():
    return [int(i) for i in sys.stdin.readline().split()]

# Function to read a single integer from input
def inp():
    return int(input())

# Function to read a single integer from stdin
def inps():
    return int(sys.stdin.readline())

# Function to read a single string from input
def instr():
    return input()

# Function to read a list of strings from input
def stlst():
    return [i for i in input().split()]

# Helper function to check if a grid of given dimensions can be formed
def help(a, b, l):
    tot = []
    for i in range(b):
        tot.append(l[i * a : i * a + a])
    for i in zip(*tot):
        if sum(i) == b:
            return True
    return False

# Main solving function
def solve():
    tot = []
    x = instr()
    s = []
    for i in x:
        if i == 'O':
            s.append(0)
        else:
            s.append(1)
    for i in range(1, 13):
        if 12 % i == 0:
            if help(i, 12 // i, s):
                tot.append((12 // i, i))
    print(len(tot), end=' ')
    for a, b in sorted(tot):
        print(f'{a}x{b}', end=' ')
    print()

# Main execution block
if __name__ == "__main__":
    for i in range(inp()):
        solve()
