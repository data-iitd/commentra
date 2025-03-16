import sys

def get_int4():
    x, y, z, rank = map(int, sys.stdin.readline().split())
    xrr = list(map(int, sys.stdin.readline().split()))
    yrr = list(map(int, sys.stdin.readline().split()))
    zrr = list(map(int, sys.stdin.readline().split()))
    return x, y, z, rank, xrr, yrr, zrr

def fget_array(size):
    return list(map(int, sys.stdin.readline().split()))

def asc(a1, a2):
    return (a1 > a2) - (a1 < a2)

def desc(a1, a2):
    return (a1 < a2) - (a1 > a2)

def lower_bound(arr, r, key):
    low, high = r.start, r.end
    while low + 1 < high:
        mid = (low + high) // 2
        if arr[mid] < key:
            low = mid
        else:
            high = mid
    return low + 1

x, y, z, rank, xrr, yrr, zrr = get_int4()

min_sum = VAL_MAX + 1
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
        for i in range(z):
            pivot = zrr[i]
            rng = range(cache[i] - 1, len(pair))
            tmp = lower_bound(pair, rng, mid - pivot)
            cnt_map[i] = tmp
        if sum(cnt_map) >= size - r:
            low = mid
        else:
            high = mid
    ans[r - 1] = low
    if low == max_sum:
        break
    prev = low

for i in range(rank):
    print(ans[i] if ans[i] != 0 else max_sum)

