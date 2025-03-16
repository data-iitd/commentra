
import sys
from bisect import bisect_left

def main():
    N = int(input())
    points = []
    for _ in range(N):
        x, L = map(int, input().split())
        points.append((x - L, x + L))
    points.sort(key=lambda x: x[1])
    ans = 1
    prev = points[0][1]
    for l, r in points:
        if l < prev:
            continue
        ans += 1
        prev = r
    print(ans)

if __name__ == "__main__":
    main()

