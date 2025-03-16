
import sys
from bisect import bisect_left

def main():
    n = int(input())
    arms = []
    for _ in range(n):
        x, l = map(int, input().split())
        arms.append((x - l, x + l))
    arms.sort(key=lambda x: x[1])
    ans = 1
    r = arms[0][1]
    for i in range(1, n):
        if arms[i][0] >= r:
            ans += 1
            r = arms[i][1]
    print(ans)

if __name__ == "__main__":
    main()

