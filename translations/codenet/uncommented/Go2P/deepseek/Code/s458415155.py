import sys
import math

def read_int():
    return int(sys.stdin.readline().strip())

def read_int_list():
    return list(map(int, sys.stdin.readline().strip().split()))

def iabs(x):
    return abs(x)

def solve(n, heights):
    t = [math.inf] * (n + 1)
    t[0] = 0
    for i in range(1, n):
        if t[i] > t[i - 1] + iabs(heights[i] - heights[i - 1]):
            t[i] = t[i - 1] + iabs(heights[i] - heights[i - 1])
        if i > 1:
            if t[i] > t[i - 2] + iabs(heights[i] - heights[i - 2]):
                t[i] = t[i - 2] + iabs(heights[i] - heights[i - 2])
    return t[n - 1]

def main():
    n = read_int()
    heights = read_int_list()
    ans = solve(n, heights)
    print(ans)

if __name__ == "__main__":
    main()
