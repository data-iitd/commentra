
import sys
import math
import bisect
import numpy as np
import fractions
import re
import itertools
import collections
import copy
import heapq
from functools import reduce
from decimal import Decimal, getcontext
from operator import itemgetter
from itertools import accumulate, count, cycle
from fractions import gcd
from bisect import bisect_left, bisect_right
from collections import deque, defaultdict, Counter
from heapq import heappush, heappop, heapify
from operator import itemgetter

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N, M = map(int, readline().split())

ans = 0

# Calculate the number of ways to choose 2 items from n items (n choose 2)
ans += N * (N - 1) // 2

# The formula for n choose 2 is n * (n - 1) // 2
# Add this value to the answer

# Calculate the number of ways to choose 2 items from m items (m choose 2)
ans += M * (M - 1) // 2

# The formula for m choose 2 is m * (m - 1) // 2
# Add this value to the answer

# Output the final answer, which is the sum of combinations from n and m
print(ans)

