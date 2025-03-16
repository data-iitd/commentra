
import sys
import math
import bisect
import heapq
from collections import deque
from decimal import *

#...

def solve():
    n = int(input())
    as = list(map(int, input().split()))

    xs = [a - i + 1 for i, a in enumerate(as)]
    xs.sort()

    b = xs[n // 2]
    ans = 0
    for x in xs:
        ans += abs(x - b)
    print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()

