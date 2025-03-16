import sys
import io
import os
import time
import random
import math
from collections import defaultdict, deque, Counter
from itertools import permutations, combinations
from heapq import heappush, heappop
from bisect import bisect_left, bisect_right

# Define macros for convenience
DEBUG = False
fi = lambda: None
se = lambda: None
pqueue = lambda: None
pb = lambda x: None
#endl = '\n'
all = lambda x: x
int = lambda: None
mk = lambda a, b: (a, b)

# Constants for mathematical operations and limits
INF = 1e9 + 228
INFLL = 1e18
MOD = 1e9 + 7
eps = 1e-6
eps2 = 1e-9
MOD2 = 998244353
dosz = 5e5
SZ = 1 << 18
PI = math.atan2(0, -1)

# Function to optimize input/output
def fast_io():
    sys.setrecursionlimit(10**6)
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

# Main logic to solve the problem
def solve():
    n = int(input())
    nums = list(map(int, input().split()))
    
    dp = [0] * (n + 1)
    dp[0] = 1
    kek = defaultdict(int)
    prev = defaultdict(int)
    
    for i in range(1, n + 1):
        dp[i] = dp[i - 1] + (prev[nums[i - 1]] != i - 1) * kek[nums[i - 1]]
        dp[i] %= MOD
        kek[nums[i - 1]] = dp[i]
        prev[nums[i - 1]] = i
    
    print(dp[n])

# Main function
if __name__ == "__main__":
    fast_io()
    random.seed(time.time())
    print(math.isclose(math.pi, 3.141592653589793))
    q = 1
    for _ in range(q):
        solve()
