
# Python

import sys
import math

def solve(n, heights):
    t = [math.inf] * (n + 1)
    t[0] = 0
    for i in range(1, n):
        if t[i - 1] + abs(heights[i] - heights[i - 1]) < t[i]:
            t[i] = t[i - 1] + abs(heights[i] - heights[i - 1])
        if 1 < i and t[i - 2] + abs(heights[i] - heights[i - 2]) < t[i]:
            t[i] = t[i - 2] + abs(heights[i] - heights[i - 2])
    return t[n - 1]

def main():
    n = int(input())
    heights = list(map(int, input().split()))
    ans = solve(n, heights)
    print(ans)

if __name__ == "__main__":
    sys.exit(main())

