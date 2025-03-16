
import sys
import math
import itertools
import collections
import bisect
import heapq
import time
import random
import re
import copy
import functools
import operator
import string
import bisect

# <START-OF-CODE>

def main():
    n = int(input())
    a = list(map(int, input().split()))
    dp = [-1] * (n + 1)
    dp[n - 1] = a[n - 1]
    for i in range(n - 1, -1, -1):
        dp[i] = max(dp[i + 1], a[i])
    for i in range(n):
        if a[i] > dp[i + 1]:
            print(0, end=' ')
        else:
            print((dp[i + 1] - a[i] + 1), end=' ')
    print()

main()

# 