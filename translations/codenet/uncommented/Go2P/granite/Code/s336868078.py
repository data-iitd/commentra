
import sys

def solve(a, b, c):
    temp_ = 0
    if c == a + b:
        temp_ = b + c
    elif c - 1 > a + b:
        temp = (c - 1) - (a + b)
        temp_ = b + c - temp
    else:
        temp_ = b + c
    return temp_

def main():
    a, b, c = map(int, sys.stdin.readline().split())
    ans = solve(a, b, c)
    print(ans)

