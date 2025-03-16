
import sys
import math
import bisect
def read(): return sys.stdin.readline().strip()
def readlist(): return list(map(int, read().split()))
def readmap(): return map(int, read().split())
def readstring(): return read().split()

def solve():
    a = readlist()
    ans = max(a[0]*a[2], a[1]*a[3], a[0]*a[3], a[1]*a[2])
    print(ans)

solve()
# END-OF-CODE