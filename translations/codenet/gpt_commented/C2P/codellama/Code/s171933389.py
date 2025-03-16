#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

def get_int4(a1, a2, a3, a4):
    a1, a2, a3, a4 = map(int, input().split())
    return a1, a2, a3, a4

def fget_array(arr, size):
    for i in range(size):
        arr[i] = int(input())
    return arr

NUM_MAX = 1000
NUM2_MAX = NUM_MAX * NUM_MAX
RANK_MAX = 3000

def asc(a1, a2):
    aa1 = a1
    aa2 = a2
    if aa1 > aa2:
        return 1
    if aa1 == aa2:
        return 0
    return -1

def desc(a1, a2):
    aa1 = a1
    aa2 = a2
    if aa1 > aa2:
        return -1
    if aa1 == aa2:
        return 0
    return 1

VAL_MAX = 1000000000
SUM_MAX = VAL_MAX * 3

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

def main():
    x, y, z, rank = get_int4(0, 0, 0, 0)
    xrr = [0] * NUM_MAX
    yrr = [0] * NUM_MAX
    zrr = [0] * NUM_MAX
    fget_array(xrr, x)
    fget_array(yrr, y)
    fget_array(zrr, z)
    min_sum = VAL_MAX + 1
    max_sum = 0
    for i in range(z):
        min_sum = min(min_sum, zrr[i])
    for i in range(z):
        max_sum = max(max_sum, zrr[i])
    pair = [0] * NUM2_MAX
    idx = 0
    for i in range(x):
        for j in range(y):
            pair[idx] = xrr[i] + yrr[j]
            idx += 1
    pair.sort(key=asc)
    min_sum += pair[0]
    max_sum += pair[idx - 1]
    cache = [0] * NUM_MAX
    cnt_map = [0] * NUM_MAX
    ans = [0] * RANK_MAX
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
                r = struct.StructRange(cache[i] - 1, idx)
                tmp = lower_bound(pair, r, mid - pivot)
                cnt_map[i] = tmp
                cnt += tmp
            if cnt <= size - r:
                cache = cnt_map
                low = mid
            else:
                high = mid
        ans[r - 1] = low
        if low == max_sum:
            break
        prev = low
    for i in range(rank):
        print(ans[i])

if __name__ == "__main__":
    main()

