import sys
import math
from collections import defaultdict, deque

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

def solve():
    ans = 0
    n = int(input())
    # Contribution of The Nodes.
    for i in range(1, n + 1):
        ans += i * (n - i + 1)
    for _ in range(n - 1):
        u, v = map(int, input().split())
        a = max(u, v)
        b = min(u, v)
        ans -= b * (n - a + 1)
    print(ans)

# t = int(input())
t = 1
while t:
    solve()
    t -= 1
