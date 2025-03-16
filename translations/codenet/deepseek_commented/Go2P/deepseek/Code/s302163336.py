import sys
import re

def input():
    return sys.stdin.readline().strip()

def next_int():
    return int(input())

def main():
    n = next_int()
    m = next_int()
    h = list(map(int, input().split()))
    good = [True] * n
    for _ in range(m):
        ai, bi = map(int, input().split())
        if h[ai - 1] > h[bi - 1]:
            good[bi - 1] = False
        elif h[ai - 1] < h[bi - 1]:
            good[ai - 1] = False
        else:
            good[ai - 1] = False
            good[bi - 1] = False
    ans = sum(good)
    print(ans)

main()
