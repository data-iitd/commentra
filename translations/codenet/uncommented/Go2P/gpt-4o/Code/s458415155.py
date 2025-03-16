# https://atcoder.jp/contests/dp/tasks/dp_a

import sys
import math

def iabs(x):
    return -x if x < 0 else x

def solve(n, heights):
    t = [math.inf] * (n + 1)
    t[0] = 0
    
    for i in range(1, n):
        t[i] = min(t[i], t[i - 1] + iabs(heights[i] - heights[i - 1]))
        if i > 1:
            t[i] = min(t[i], t[i - 2] + iabs(heights[i] - heights[i - 2]))

    return t[n - 1]

def main():
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    heights = list(map(int, data[1:n + 1]))
    ans = solve(n, heights)
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
