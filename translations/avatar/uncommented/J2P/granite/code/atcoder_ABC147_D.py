
import sys
import math
import bisect
import random
import re
import time

sys.setrecursionlimit(10 ** 7)
from fractions import Fraction
from collections import defaultdict
import copy
import heapq
from functools import *

def main():
    startTime = time.time()

    n = int(input())
    mod = 10 ** 9 + 7
    a = list(map(int, input().split()))

    ans = 0
    for i in range(60):
        count1 = 0
        for j in range(n):
            if (a[j] >> i) & 1:
                count1 += 1
        a = [a[j] << 1 % mod for j in range(n)]
        ans += count1 * (n - count1)
        ans %= mod

    print(ans)

    endTime = time.time()

if __name__ == "__main__":
    main()

