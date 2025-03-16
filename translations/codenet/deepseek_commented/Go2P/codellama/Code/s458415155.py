
#!/usr/bin/env python3

import sys
import math

def solve(n, heights):
    # Initialize the minimum cost array with a large value.
    t = [math.inf] * (n + 1)

    # The cost to reach the first stone is 0.
    t[0] = 0

    # Calculate the minimum cost to reach each stone.
    for i in range(1, n):
        # Cost to reach the current stone from the previous stone.
        if v := t[i - 1] + abs(heights[i] - heights[i - 1]); v < t[i]:
            t[i] = v
        # Cost to reach the current stone from two stones back (if possible).
        if i > 1:
            if v := t[i - 2] + abs(heights[i] - heights[i - 2]); v < t[i]:
                t[i] = v

    # Return the minimum cost to reach the last stone.
    return t[n - 1]

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    heights = list(map(int, sys.stdin.readline().split()))
    ans = solve(n, heights)
    print(ans)

