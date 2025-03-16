import sys

# Constants are defined for the maximum values of various quantities.
NUM_MAX = 1000
NUM2_MAX = NUM_MAX * NUM_MAX
RANK_MAX = 3000
VAL_MAX = 10**10
SUM_MAX = VAL_MAX * 3

# This function reads four integers from the standard input and stores them in the provided variables.
def get_int4(a1, a2, a3, a4):
    a1.append(int(input()))
    a2.append(int(input()))
    a3.append(int(input()))
    a4.append(int(input()))

# This function reads an array of integers from the standard input.
def fget_array(arr, size):
    for i in range(size):
        arr.append(int(input()))

# These functions are used to compare integers for sorting in ascending and descending order.
def asc(a1, a2):
    return (a1 > a2) - (a1 < a2)

def desc(a1, a2):
    return (a1 < a2) - (a1 > a2)

# A structure is defined to represent a range of indices.
class Range:
    def __init__(self, start, end):
        self.start = start
        self.end = end

# This function finds the lower bound of a key in a sorted array within a given range.
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

# The main function reads input, processes data, and outputs the result based on the given rank.
def main():
    x, y, z, rank = [], [], [], []
    get_int4(x, y, z, rank)
    xrr = []
    fget_array(xrr, x[0])
    yrr = []
    fget_array(yrr, y[0])
    zrr = []
    fget_array(zrr, z[0])
    min_sum = min(min(zrr), VAL_MAX + 1)
    max_sum = max(max(zrr), 0)
    idx = 0
    pair = []
    for i in range(x[0]):
        for j in range(y[0]):
            pair.append(xrr[i] + yrr[j])
    pair.sort()
    min_sum = min(min_sum, pair[0])
    max_sum = max(max_sum, pair[-1])
    cache = [0] * NUM_MAX
    cnt_map = [0] * NUM_MAX
    ans = [0] * RANK_MAX
    size = x[0] * y[0] * z[0]
    prev = min_sum
    for r in range(rank[0], 0, -1):
        low = prev - 1
        high = max_sum + 1
        while low + 1 < high:
            mid = (low + high) // 2
            cnt = 0
            for i in range(z[0]):
                pivot = zrr[i]
                r = Range(cache[i] - 1, idx)
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
    for i in range(rank[0]):
        print(ans[i] if ans[i] != 0 else max_sum)

if __name__ == "__main__":
    main()
