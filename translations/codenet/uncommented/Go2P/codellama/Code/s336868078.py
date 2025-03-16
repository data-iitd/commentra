
import sys

def solve(a, b, c):
    if c == a + b:
        temp = b + c
    elif c - 1 > a + b:
        temp = b + c - (c - 1 - (a + b))
    else:
        temp = b + c
    return temp

a, b, c = map(int, sys.stdin.readline().split())
ans = solve(a, b, c)
print(ans)

