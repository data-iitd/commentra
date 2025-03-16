
import sys
import math

def solve():
    n = int(sys.stdin.readline())
    as = list(map(int, sys.stdin.readline().split()))

    xs = [a - i + 1 for i, a in enumerate(as)]
    xs.sort()

    b = xs[n // 2]
    ans = 0
    for x in xs:
        ans += abs(x - b)

    print(ans)

def abs(n):
    if n < 0:
        return -n
    return n

if __name__ == "__main__":
    solve()

