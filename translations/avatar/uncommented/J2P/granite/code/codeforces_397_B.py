
import sys
import math
import bisect
import heapq
from collections import deque
from collections import Counter
from itertools import combinations
from itertools import permutations
input = lambda: sys.stdin.readline().rstrip("\r\n")
read = lambda: list(map(int, input().strip().split(" ")))
def solve():
    for _ in range(int(input())):
        n, a, b = read()
        if n < a:
            print("No")
            continue
        if a == b:
            if n % a == 0:
                print("Yes")
            else:
                print("No")
            continue
        x = b // (b - a)
        if n > x * a:
            print("Yes")
            continue
        low = 1
        high = x + 1
        ans = 1
        while low <= high:
            mid = (low + high) // 2
            if mid * a < n:
                low = mid + 1
            else:
                ans = mid
                high = mid - 1
        if n > (ans - 1) * b and n < ans * a:
            print("No")
        else:
            print("Yes")
solve()
