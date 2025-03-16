# <START-OF-CODE>
import sys

def solve(n, heights):
    t = [math.inf] * (n+1)
    t[0] = 0
    for i in range(1, n):
        if v := t[i-1] + abs(heights[i]-heights[i-1]):
            t[i] = v
        if 1 < i:
            if v := t[i-2] + abs(heights[i]-heights[i-2]):
                t[i] = v
    return t[n-1]

def main():
    n = int(input())
    heights = [int(x) for x in input().split()]
    ans = solve(n, heights)
    print(ans)

if __name__ == '__main__':
    main()
# 