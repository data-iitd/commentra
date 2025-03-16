
import sys

def solve():
    x = int(sys.stdin.readline())
    t = int(sys.stdin.readline())
    a = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    da = int(sys.stdin.readline())
    db = int(sys.stdin.readline())
    first = 0
    second = 0
    ok = False
    for i in range(t):
        first = a - (da * i)
        for j in range(t):
            second = b - (db * j)
            if (second + first == x or second == x or first == x or x == 0):
                ok = True
                break
        if ok:
            break
    if ok:
        print("YES")
    else:
        print("NO")

solve()

