
import sys
from bisect import bisect_left

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    xs = [a[i] - i + 1 for i in range(n)]
    xs.sort()
    b = xs[n // 2]
    ans = sum(abs(x - b) for x in xs)
    print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()

