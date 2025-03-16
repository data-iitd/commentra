
import sys
import math

def solve():
    N, D, A = map(int, sys.stdin.readline().split())
    M = []
    for _ in range(N):
        x, h = map(int, sys.stdin.readline().split())
        M.append((x, h))
    M.sort()
    q = []
    ans = 0
    total = 0
    for i in range(N):
        m = M[i]
        while q and q[0][0] < m[0]:
            total -= q.pop(0)[1]
        if total < m[1]:
            m[1] -= total
            count = math.ceil(m[1] / A)
            ans += count
            damage = count * A
            q.append((m[0] + 2 * D, damage))
            total += damage
    print(ans)

solve()

