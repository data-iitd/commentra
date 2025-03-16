
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

def ri(flag=0):
    if flag==0:
        return [int(i) for i in input().split()]
    else:
        return int(input())

def rl(flag=0):
    if flag==0:
        return [int(i) for i in input().split()]
    else:
        return list(map(int, input().split()))

def srl(flag=0):
    if flag==0:
        return [str(i) for i in input().split()]
    else:
        return list(map(str, input().split()))

def mi(flag=0):
    if flag==0:
        return map(int, input().split())
    else:
        return list(map(int, input().split()))

def main():
    n = ri(1)
    a = ri()
    a.sort()
    min_a = a[0]
    max_a = a[-1]
    min_count = a.count(min_a)
    max_count = a.count(max_a)
    if min_a == max_a:
        print(0, min_count * (min_count - 1) // 2)
    else:
        print(max_a - min_a, min_count * max_count)

if __name__ == "__main__":
    main()

