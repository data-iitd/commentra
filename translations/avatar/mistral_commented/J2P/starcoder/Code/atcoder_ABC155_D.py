
import sys

# <START-OF-CODE>

mod = 1000000007

DX = [-1, 0, 1, 0]
DY = [0, -1, 0, 1]

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())
a = [int(x) for x in sys.stdin.readline().split()]

a.sort()

INF = 1000000000000000000 + 1
l = -INF
r = INF

while l + 1 < r:
    c = (l + r) // 2
    if check(c):
        l = c
    else:
        r = c

print(l)

def check(x):
    tot = 0
    for i in range(n):
        now = a[i]
        l = 0
        r = n
        if now >= 0:
            while l < r:
                c = (l + r) // 2
                if now * a[c] < x:
                    l = c + 1
                else:
                    r = c
            tot += l
        else:
            while l < r:
                c = (l + r) // 2
                if now * a[c] >= x:
                    l = c + 1
                else:
                    r = c
            tot += (n - l)
        if a[i] * a[i] < x:
            tot -= 1
        if tot // 2 < k:
            return True
    return False

# 