
#!/usr/bin/env python3

import sys

def solve(a, b, c):
    if c == a + b:
        temp_ = b + c
    elif c - 1 > a + b:
        temp = (c - 1) - (a + b)
        temp_ = b + c - temp
    else:
        temp_ = b + c
    return temp_

if __name__ == "__main__":
    a, b, c = map(int, sys.stdin.readline().split())
    ans = solve(a, b, c)
    print(ans)

