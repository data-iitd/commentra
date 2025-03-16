
import sys
import bisect

def solve(arr):
    n = len(arr)
    sorted_arr = sorted(arr)
    total = n * (n + 1) // 2
    l, r = 0, n - 1
    while l < r:
        mid = (l + r) // 2
        target = sorted_arr[mid]
        cur = 0
        cnt = 0
        bit = [0] * (2 * n + 2)
        for i in range(n + 1):
            cur += arr[i] <= target
            bisect.insort(bit, cur + n + 1)
            cnt += bisect.bisect_left(bit, cur + n)
        if cnt >= total // 2 + 1:
            r = mid
        else:
            l = mid + 1
    return sorted_arr[l]

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    print(solve(arr))

