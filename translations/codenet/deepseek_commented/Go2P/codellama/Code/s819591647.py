
import sys
import math

def solve():
    n, m = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))

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

solve()

