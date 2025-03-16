import sys
import bisect

def get_int4():
    return map(int, sys.stdin.readline().strip().split())

def fget_array(size):
    return list(map(int, sys.stdin.readline().strip().split()))

def asc(a):
    return a

def desc(a):
    return -a

VAL_MAX = int(1e+10)
NUM_MAX = 1000
NUM2_MAX = NUM_MAX * NUM_MAX
RANK_MAX = 3000

def lower_bound(arr, r, key):
    low = r[0]
    high = r[1]
    while low + 1 < high:
        mid = (low + high) // 2
        if arr[mid] < key:
            low = mid
        else:
            high = mid
    return low + 1

def main():
    x, y, z, rank = get_int4()
    xrr = fget_array(x)
    yrr = fget_array(y)
    zrr = fget_array(z)

    min_sum = VAL_MAX + 1
    max_sum = 0

    for i in range(z):
        min_sum = min(min_sum, zrr[i])
    for i in range(z):
        max_sum = max(max_sum, zrr[i])

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
            cnt = 0
            for i in range(z):
                pivot = zrr[i]
                r_range = (cache[i] - 1, len(pair))
                tmp = lower_bound(pair, r_range, mid - pivot)
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
        print(max_sum if ans[i] == 0 else ans[i])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
