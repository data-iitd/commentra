# The code starts by including necessary headers for input/output operations, string manipulation, and memory management.
import sys

# Macros are defined to set the maximum sizes for arrays and other constants.
NUM_MAX = 1000
NUM2_MAX = NUM_MAX*NUM_MAX
RANK_MAX = 3000

# This function reads four integers from the standard input and stores them in the provided variables.
def get_int4(a1, a2, a3, a4):
    a1, a2, a3, a4 = map(int, input().split())
    return 0

# This function reads an array of integers from the standard input.
def fget_array(arr, size):
    for i in range(size):
        arr[i] = int(input())
    return 0

# These functions are used to compare integers for sorting in ascending and descending order.
def asc(a1, a2):
    aa1 = a1
    aa2 = a2
    if(aa1 > aa2): return 1
    if(aa1 == aa2): return 0
    return -1

def desc(a1, a2):
    aa1 = a1
    aa2 = a2
    if(aa1 > aa2): return -1
    if(aa1 == aa2): return 0
    return 1

# Constants are defined for the maximum values of various quantities.
VAL_MAX = 1e+10
SUM_MAX = VAL_MAX*3

# A structure is defined to represent a range of indices.

class range:
    def __init__(self, start, end):
        self.start = start
        self.end = end

# This function finds the lower bound of a key in a sorted array within a given range.
def lower_bound(arr, r, key):
    low = r.start
    high = r.end
    while(low + 1 < high):
        mid = (low + high) / 2
        if(arr[mid] < key):
            low = mid
        else:
            high = mid
    return low + 1

# The main function reads input, processes data, and outputs the result based on the given rank.

def main():
    x, y, z, rank = map(int, input().split())
    xrr = [0]*x
    yrr = [0]*y
    zrr = [0]*z
    fget_array(xrr, x)
    fget_array(yrr, y)
    fget_array(zrr, z)
    min_sum = VAL_MAX+1
    max_sum = 0
    for i in range(z): min_sum = min(min_sum, zrr[i])
    for i in range(z): max_sum = max(max_sum, zrr[i])

    pair = [0]*NUM2_MAX
    idx = 0
    for i in range(x):
        for j in range(y):
            pair[idx] = xrr[i] + yrr[j]
            idx += 1
    pair.sort(key=int, reverse=False)
    min_sum += pair[0]
    max_sum += pair[idx-1]

    cache = [0]*z
    cnt_map = [0]*z
    ans = [0]*RANK_MAX
    size = x*y*z
    prev = min_sum
    r = rank
    for r in range(rank, 0, -1):
        low = prev-1
        high = max_sum+1
        while(low + 1 < high):
            mid = (low + high)/2
            cnt = 0
            for i in range(z):
                pivot = zrr[i]
                r = range(cache[i]-1, idx)
                tmp = lower_bound(pair, r, mid-pivot)
                cnt_map[i] = tmp
                cnt += tmp
            if(cnt <= size-r):
                cache = cnt_map[:]
                low = mid
            else:
                high = mid
        ans[r-1] = low
        if(low == max_sum): break
        prev = low
    for i in range(rank):
        print(ans[i] if ans[i]!= 0 else max_sum)

    return 0

# 