
import sys
import math
import bisect
import re
import itertools
import statistics
import functools
import collections
import operator
import string

def ria():
    return [int(i) for i in input().split()]

def ri():
    return int(input())

def rfa():
    return [float(i) for i in input().split()]

def rfft():
    return map(float, input().split())

def rs():
    return input()

def rsf():
    return input().split()

def main():
    n, s = ria()
    max_sum = 0
    for _ in range(n):
        f, t = ria()
        max_sum = max(max_sum, f + t)
    print(max(max_sum, s))

if __name__ == "__main__":
    main()

