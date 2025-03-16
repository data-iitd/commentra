

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

class Task:
    def solve(self, arr):
        n = len(arr)
        sorted_arr = sorted(arr)
        total = n * (n + 1) // 2
        l, r = 0, n - 1
        bit = [0] * (2 * n + 2)

        while l < r:
            mid = l + (r - l) // 2
            target = sorted_arr[mid]
            cur, cnt = 0, 0

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

        return sorted_arr[l]

# Read input from stdin and provide input before running code

def main():
    t = int(input().strip())
    for a0 in range(t):
        n = int(input().strip())
        arr = list(map(int, input().strip().split(' ')))
        res = Task().solve(arr)
        print(res)

if __name__ == '__main__':
    main()

