

import sys
import array
import bisect

# Read input
x, y, z, rank = map(int, sys.stdin.readline().split())
xrr = array.array('q', map(int, sys.stdin.read().split()))
yrr = array.array('q', map(int, sys.stdin.read().split()))
zrr = array.array('q', map(int, sys.stdin.read().split()))

# Define constants
VAL_MAX = 10**10
SUM_MAX = VAL_MAX * 3

# Define a structure to represent a range of indices
class Range:
    def __init__(self, start, end):
        self.start = start
        self.end = end

# Define a function to find the lower bound of a key in a sorted array within a given range
def lower_bound(arr, r, key):
    low = r.start
    high = r.end
    while low + 1 < high:
        mid = (low + high) // 2
        if arr[mid] < key:
            low = mid
        else:
            high = mid
    return low + 1

# Process data and output the result based on the given rank
min_sum = VAL_MAX + 1
max_sum = 0
for i in range(z):
    min_sum = min(min_sum, zrr[i])
    max_sum = max(max_sum, zrr[i])

pair = [xrr[i] + yrr[j] for i in range(x) for j in range(y)]
pair.sort()
min_sum += pair[0]
max_sum += pair[-1]

cache = [0] * z
cnt_map = [0] * z
ans = [0] * rank
size = x * y * z
prev = min_sum

for r in range(rank, 0, -1):
    low = prev - 1
    high = max_sum + 1
    while low + 1 < high:
        mid = (low + high) // 2
        cnt = 0
        for i in range(z):
            pivot = zrr[i]
            r = Range(cache[i] - 1, len(pair))
            tmp = lower_bound(pair, r, mid - pivot)
            cnt_map[i] = tmp
            cnt += tmp
        if cnt <= size - r:
            cache = cnt_map[:]
            low = mid
        else:
            high = mid
    ans[r - 1] = low
    if low == max_sum:
        break
    prev = low

for i in range(rank):
    print(ans[i] if ans[i] > 0 else max_sum)

print("