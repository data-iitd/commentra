
import sys

def get_int4():
    return list(map(int, input().split()))

def fget_array(size):
    return list(map(int, input().split()))

def asc(a1, a2):
    if a1 > a2: return 1
    if a1 == a2: return 0
    return -1

def desc(a1, a2):
    if a1 > a2: return -1
    if a1 == a2: return 0
    return 1

NUM_MAX = 1000
NUM2_MAX = NUM_MAX*NUM_MAX
RANK_MAX = 3000

VAL_MAX = 10**10
SUM_MAX = VAL_MAX*3

x, y, z, rank = get_int4()
xrr = fget_array(x)
yrr = fget_array(y)
zrr = fget_array(z)
min_sum = VAL_MAX+1
max_sum = 0
for i in range(z):
    min_sum = min(min_sum, zrr[i])
    max_sum = max(max_sum, zrr[i])

pair = []
for i in range(x):
    for j in range(y):
        pair.append(xrr[i] + yrr[j])
pair.sort()
min_sum += pair[0]
max_sum += pair[-1]

cache = [0]*NUM_MAX
cnt_map = [0]*NUM_MAX
ans = [0]*RANK_MAX
size = x*y*z
prev = min_sum
for r in range(rank, 0, -1):
    low = prev-1
    high = max_sum+1
    while low + 1 < high:
        mid = (low + high)//2
        cnt = 0
        for i in range(z):
            pivot = zrr[i]
            cache[i] = cnt_map[i]
            low_bound = cache[i]-1
            high_bound = len(pair)
            while low_bound + 1 < high_bound:
                mid_bound = (low_bound + high_bound)//2
                if pair[mid_bound] < mid-pivot:
                    low_bound = mid_bound
                else:
                    high_bound = mid_bound
            cnt_map[i] = high_bound
            cnt += high_bound
        if cnt <= size-r:
            low = mid
        else:
            high = mid
    ans[r-1] = low
    if low == max_sum: break
    prev = low

for i in range(rank):
    print(ans[i])

