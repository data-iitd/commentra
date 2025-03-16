
#include <stdio.h>
#include <string.h>
#define MAX 21

def init(i):
    global n, x, y
    x = y = 10
    fld = [[0] * MAX for _ in range(MAX)]
    while i:
        a, b = map(int, input().split())
        fld[b][a] = 1
        i -= 1

def move(i):
    global n, x, y
    while i:
        a, d = map(int, input().split())
        if d % 2:
            if d % 2:
                if d < 0:
                    x -= 1
                else:
                    x += 1
            else:
                if d < 0:
                    y -= 1
                else:
                    y += 1
        else:
            if d < 0:
                y -= 1
            else:
                y += 1
            x += d // 2
        if fld[y][x]:
            fld[y][x] = 0
            n -= 1
        i -= 1

while True:
    n = int(input())
    if n <= 0:
        break
    init(n)
    m = int(input())
    move(m)
    print("No" if n else "Yes")

