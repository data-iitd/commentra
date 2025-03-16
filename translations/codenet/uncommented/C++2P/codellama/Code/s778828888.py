#include <cstdio>
#include <algorithm>

def main():
    n, m, x = map(int, input().split())
    a = [0] * 105
    for i in range(m):
        temp = int(input())
        a[temp] = 1

    ansl = 0
    ansr = 0
    for i in range(x, n + 1):
        ansr += a[i]
    for i in range(x - 1, -1, -1):
        ansl += a[i]

    print(min(ansl, ansr))


