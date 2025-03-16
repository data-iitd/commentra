#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b)? (a) : (b))
#define min(a,b) ((a) > (b)? (b) : (a))

def get_int4(a1, a2, a3, a4):
    scanf("%d %d %d %d", a1, a2, a3, a4)
    return 0

def fget_array(arr, size):
    for i in range(size):
        scanf("%lld", &arr[i])
    return 0

NUM_MAX = 1000
NUM2_MAX = NUM_MAX * NUM_MAX
RANK_MAX = 3000

def asc(a1, a2):
    aa1 = *(int64_t*)a1
    aa2 = *(int64_t*)a2
    if aa1 > aa2: return 1
    if aa1 == aa2: return 0
    return -1

def desc(a1, a2):
    aa1 = *(int64_t*)a1
    aa2 = *(int64_t*)a2
    if aa1 > aa2: return -1
    if aa1 == aa2: return 0
    return 1

VAL_MAX = (int64_t)(1e+10)
SUM_MAX = VAL_MAX * 3

class range:
    def __init__(self, start, end):
        self.start = start
        self.end = end

def lower_bound(arr, r, key):
    low = r.start
    high = r.end
    while low + 1 < high:
        mid = (low + high) / 2
        if arr[mid] < key:
            low = mid
        else:
            high = mid
    return low + 1

def main():
    x, y, z, rank = [0] * 4
    get_int4(x, y, z, rank)
    xrr = [0] * x
    yrr = [0] * y
    zrr = [0] * z
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
    qsort(pair, idx, sizeof(int64_t), asc)
    min_sum += pair[0]
    max_sum += pair[idx - 1]
    size = x * y * z
    prev = min_sum
    ans = [0] * RANK_MAX
    for r in range(rank, 0, -1):
        low = prev - 1
        high = max_sum + 1
        while low + 1 < high:
            mid = (low + high) / 2
            cnt = 0
            for i in range(z):
                pivot = zrr[i]
                r = range(cache[i] - 1, idx)
                tmp = lower_bound(pair, r, mid - pivot)
                cnt_map[i] = tmp
                cnt += tmp
            if cnt <= size - r:
                memcpy(cache, cnt_map, sizeof(int) * z)
                low = mid
            else:
                high = mid
        ans[r - 1] = low
        if low == max_sum: break
        prev = low
    for i in range(rank):
        printf("%lld\n", (ans[i] == 0)? max_sum : ans[i])
    return 0

