
import sys

def solve():
    x, t, a, b, da, db = map(int, sys.stdin.readline().split())
    first = 0
    second = 0
    ok = False

    for i in range(t):
        first = a - (da * i)
        for j in range(t):
            second = b - (db * j)

            if second + first == x or second == x or first == x or x == 0:
                ok = True
                break

    if ok:
        print("YES")
    else:
        print("NO")

solve()

