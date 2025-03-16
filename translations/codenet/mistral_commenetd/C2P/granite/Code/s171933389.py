

import sys
import bisect

def get_int4(a1, a2, a3, a4):
    # Read 4 integers from the standard input and store them in the given pointers
    a1, a2, a3, a4 = map(int, sys.stdin.readline().split())
    return a1, a2, a3, a4

def fget_array(arr, size):
    for i in range(size):
        arr[i] = int(sys.stdin.readline())
    return arr

def asc(a1, a2):
    # Compare two 64-bit integers and return 1 if aa1 is greater than aa2, 0 if they are equal, and -1 if aa1 is less than aa2
    if a1 > a2: return 1
    if a1 == a2: return 0
    return -1

def desc(a1, a2):
    # Compare two 64-bit integers and return -1 if aa1 is less than aa2, 0 if they are equal, and 1 if aa1 is greater than aa2
    if a1 > a2: return -1
    if a1 == a2: return 0
    return 1

def lower_bound(arr, key):
    # Binary search to find the index of the first element greater than or equal to the given key in the sorted array arr
    low = 0
    high = len(arr)
    while low + 1 < high:
        mid = (low + high) // 2
        if arr[mid] < key:
            low = mid
        else:
            high = mid
    return low + 1

def main():
    x, y, z, rank = get_int4(0, 0, 0, 0)
    xrr = [0] * x
    yrr = [0] * y
    zrr = [0] * z
    fget_array(xrr, x)
    fget_array(yrr, y)
    fget_array(zrr, z)
    min_sum = 10**10 + 1
    max_sum = 0
    for i in range(z):
        min_sum = min(min_sum, zrr[i])
        max_sum += zrr[i]
    pair = []
    for i in range(x):
        for j in range(y):
            pair.append(xrr[i] + yrr[j])
    pair.sort()
    min_sum += pair[0]
    max_sum += pair[-1]
    cache = [0] * z
    cnt_map = [0] * z
    ans = [0] * rank
    size = x * y * z
    prev = min_sum
    r = rank - 1
    while r >= 0:
        low = prev - 1
        high = max_sum + 1
        while low + 1 < high:
            mid = (low + high) // 2
            for i in range(z):
                pivot = zrr[i]
                cache[i] = bisect.bisect_left(pair, mid - pivot)
                cnt_map[i] = cache[i]
            if sum(cnt_map) >= size - r:
                low = mid
            else:
                high = mid
        ans[r] = low
        if low == max_sum:
            break
        prev = low
        r -= 1
    for i in range(rank):
        print(ans[i] if ans[i]!= 0 else max_sum)

if __name__ == "__main__":
    main()

