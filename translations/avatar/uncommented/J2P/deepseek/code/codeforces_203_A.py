import sys
import io
import os
import re

input = sys.stdin.readline

def solve():
    x = int(input().strip())
    t = int(input().strip())
    a = int(input().strip())
    b = int(input().strip())
    da = int(input().strip())
    db = int(input().strip())
    
    ok = False
    for i in range(t):
        first = a - (da * i)
        for j in range(t):
            second = b - (db * j)
            if second + first == x or second == x or first == x or x == 0:
                ok = True
                break
        if ok:
            break
    
    print("YES" if ok else "NO")

if __name__ == "__main__":
    solve()
