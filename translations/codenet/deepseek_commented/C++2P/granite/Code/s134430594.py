
import sys
import io
import os

def main():
    n = int(input())
    a = list(map(int, input().split()))
    dl = [i - a[i] for i in range(n)]
    ans = 0
    bans = []
    for i in range(n):
        r = i
        while r + 1 < n and a[r] + 1 == a[r + 1]:
            r += 1
        ans += a[r]
        i = r
        bans.append((r - a[r], r, r - a[r]))
    mn = [0] * n
    for i in range(n):
        mn[i] = dl[i]
    for i in range(1, n):
        j = 2 * i
        while j < n:
            mn[j] = min(mn[j], mn[i])
            j += i
    for t in bans:
        l, r, val = t
        if mn[r - l] > val:
            print(-1)
            return
    print(ans)

if __name__ == "__main__":
    main()

