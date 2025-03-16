

import sys
import bisect

def main():
    n = int(input())
    a = list(map(int, input().split()))
    q = int(input())
    ans = [-1] * n
    for _ in range(q):
        l, r, x = map(int, input().split())
        l -= 1
        r -= 1
        x -= 1
        while True:
            pos = bisect.bisect_left(a, l)
            if pos > r:
                break
            if a[pos] > r:
                break
            if a[pos] == x:
                continue
            ans[a[pos] - 1] = x + 1
            a[pos] = x + 1
    print(*ans)

if __name__ == "__main__":
    main()

