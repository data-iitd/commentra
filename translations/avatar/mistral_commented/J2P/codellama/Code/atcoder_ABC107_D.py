
import sys
import math

def solve(arr):
    n = len(arr)
    sorted_arr = sorted(arr)
    total = n * (n + 1) // 2

    l = 0
    r = n - 1

    while l < r:
        mid = l + (r - l) // 2
        target = sorted_arr[mid]

        cur = 0
        cnt = 0
        bit = [0] * (2 * n + 2)

        for i in range(n + 1, len(bit)):
            bit[i] += 1

        for i in range(n):
            cur += 1 if arr[i] <= target else -1
            for i in range(cur + n + 1, len(bit)):
                bit[i] += 1
            for i in range(cur + n, 0, -1):
                cnt += bit[i]

        if cnt >= total // 2 + 1:
            r = mid
        else:
            l = mid + 1

    return sorted_arr[l]

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    print(solve(arr))

