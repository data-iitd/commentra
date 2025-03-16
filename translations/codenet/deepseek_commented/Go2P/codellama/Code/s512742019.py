
import sys
from collections import deque

def solve():
    N, D, A = map(int, sys.stdin.readline().split())
    M = []
    for _ in range(N):
        M.append(list(map(int, sys.stdin.readline().split())))
    M.sort(key=lambda x: x[0])
    q = deque()
    ans = 0
    total = 0
    for i in range(N):
        m = M[i]
        while q and q[0][0] < m[0]:
            total -= q.popleft()[1]
        if total < m[1]:
            m[1] -= total
            count = (m[1] + A - 1) // A
            ans += count
            damage = count * A
            q.append([m[0] + 2*D, damage])
            total += damage
    print(ans)

solve()

