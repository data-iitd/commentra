
#problem_b.py

import sys
import math

constMod = 1000000007

def getInt():
    return int(sys.stdin.readline())

def getIntSlice(n):
    ns = []
    for i in range(n):
        ns.append(getInt())
    return ns

def getString():
    return sys.stdin.readline().strip()

def getStringSlice(n):
    ss = []
    for i in range(n):
        ss.append(getString())
    return ss

def solve():

    n, m = getInt(), getInt()
    a = getIntSlice(n)

    sum = 0
    for v in a:
        sum += v

    count = 0
    for v in a:
        rate = sum / (4 * m)
        if v >= rate:
            count += 1

    if count >= m:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    solve()