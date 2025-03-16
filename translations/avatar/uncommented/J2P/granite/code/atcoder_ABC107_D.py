
import sys
import io
import os
import math
import heapq
import copy
import time
import collections
import itertools
import bisect
import string
import re
import random
import queue
from decimal import *

def main():
    start_time = time.time()
    # Write your code here
    N = int(input())
    arr = list(map(int, input().split()))
    tsk = Task()
    print(tsk.solve(arr))
    # Write your code here
    elapsed_time = time.time() - start_time
    print("elapsed_time:{0}".format(elapsed_time) + "[sec]")

class Task:
    def solve(self, arr):
        n = len(arr)
        sorted = arr[:]
        sorted.sort()
        total = n * (n + 1) // 2
        l = 0
        r = n - 1
        while l < r:
            mid = l + (r - l) // 2
            target = sorted[mid]
            cur = 0
            cnt = 0
            bit = [0] * (2 * n + 2)
            for i in range(n):
                cur += 1 if arr[i] <= target else -1
                for x in range(cur + n + 1, 2 * n + 2, x & -x):
                    bit[x] += 1
                for x in range(cur + n, 0, -x & x):
                    cnt += bit[x]
            if cnt >= total // 2 + 1:
                r = mid
            else:
                l = mid + 1
        return sorted[l]

if __name__ == "__main__":
    main()
