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
        if d == 0:
            d = 0
        elif d == 1:
            d = 1
        elif d == 2:
            d = 2
        elif d == 3:
            d = 3
        while a:
            if d == 0:
                y -= 1
            elif d == 1:
                x += 1
            elif d == 2:
                y += 1
            elif d == 3:
                x -= 1
            if fld[y][x]:
                fld[y][x] = 0
                n -= 1
            a -= 1
        i -= 1

n = 0
x = 0
y = 0
fld = []

while True:
    n = int(input())
    if n == 0:
        break
    init(n)
    m = int(input())
    move(m)
    print("No" if n else "Yes")

# 