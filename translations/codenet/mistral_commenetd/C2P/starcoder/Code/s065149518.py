
#include <stdio.h>
#include <string.h>
#define MAX 21

def init(i):
    global x, y
    x = y = 10
    fld = [[0 for i in range(MAX)] for j in range(MAX)]

def move(i):
    global x, y
    while i:
        buf = raw_input().split()
        a = int(buf[1])
        d = {'N': 0, 'E': 1, 'S': 2, 'W': 3}[buf[0]]
        while a:
            if d % 2:
                d % 2 and x-- or x++
            else:
                d and y-- or y++
                x += d / 2
            if fld[y][x]:
                fld[y][x] = 0
                i--
        i--

while 1:
    n = int(raw_input())
    if n < 0:
        break
    init(n)
    m = int(raw_input())
    move(m)
    print n and "No" or "Yes"

