#include <stdio.h>
#include <stdbool.h>
#include <string.h>

def main():
    n, m = map(int, input().split())
    r0 = [False] * n
    r1 = []
    for i in range(m):
        a, b = map(int, input().split())
        if a > b:
            a, b = b, a
        if a == 1:
            r0[b - 1] = True
        if b == n:
            r1.append(a - 1)
    res = False
    for i in range(len(r1)):
        if r0[r1[i]]:
            res = True
    print("POSSIBLE" if res else "IMPOSSIBLE")


