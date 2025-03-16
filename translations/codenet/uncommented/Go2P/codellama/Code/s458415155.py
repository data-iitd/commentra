
import sys

def solve(n, heights):
    t = [float('inf')] * (n + 1)
    t[0] = 0
    for i in range(1, n):
        if t[i - 1] + abs(heights[i] - heights[i - 1]) < t[i]:
            t[i] = t[i - 1] + abs(heights[i] - heights[i - 1])
        if i > 1 and t[i - 2] + abs(heights[i] - heights[i - 2]) < t[i]:
            t[i] = t[i - 2] + abs(heights[i] - heights[i - 2])
    return t[n - 1]

def main():
    n = int(sys.stdin.readline().rstrip())
    heights = list(map(int, sys.stdin.readline().rstrip().split()))
    ans = solve(n, heights)
    print(ans)

if __name__ == '__main__':
    main()

