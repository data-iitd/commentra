import sys

def get_int4():
    x, y, z, rank = map(int, sys.stdin.readline().split())
    return x, y, z, rank

def fget_array(size):
    return list(map(int, sys.stdin.readline().split()))

def asc(a1, a2):
    if a1 > a2:
        return 1
    elif a1 == a2:
        return 0
    else:
        return -1

def desc(a1, a2):
    if a1 > a2:
        return -1
    elif a1 == a2:
        return 0
    else:
        return 1

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

x, y, z, rank = get_int4()
xrr = fget_array(x)
yrr = fget_array(y)
zrr = fget_array(z)

min_sum = min(min(zrr), min(xrr) + min(yrr))
max_sum = max(max(zrr), max(xrr) + max(yrr))

pair = []
for i in range(x):
    for j in range(y):
        pair.append(xrr[i] + yrr[j])

pair.sort()

cache = [0] * x
cnt_map = [0] * x
ans = [0] * rank
prev = min_sum

for r in range(rank, 0, -1):
    low = prev - 1
    high = max_sum + 1
    while low + 1 < high:
        mid = (low + high) // 2
        cnt = 0
        for i in range(z):
            pivot = zrr[i]
            r = {'start': cache[i] - 1, 'end': len(pair)}
            tmp = lower_bound(pair, r, mid - pivot)
            cnt_map[i] = tmp
            cnt += tmp
        if cnt <= (x * y * z) - r:
            cache = cnt_map[:]
            low = mid
        else:
            high = mid
    ans[r - 1] = low
    if low == max_sum:
        break
    prev = low

for i in range(rank):
    print(ans[i] if ans[i] != 0 else max_sum)

