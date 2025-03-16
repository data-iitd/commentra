
#include <stdio.h>
#include <string.h>
#define MAX 21

def init(i):
    global x, y
    x = y = 10
    fld = [[0 for i in range(MAX)] for j in range(MAX)]
    while i:
        a, b = map(int, raw_input().split())
        fld[b][a] = 1
        i -= 1

def move(i):
    global x, y
    while i:
        buf, a = raw_input().split()
        a = int(a)
        d = {'N': 0, 'E': 1, 'S': 2, 'W': 3}[buf[0]]
        while a:
            d % 2 and (d and x-- or x++) or (d and y-- or y++)
            if fld[y][x]:
                fld[y][x] = 0
                i -= 1
            a -= 1

if __name__ == '__main__':
    while True:
        n = int(raw_input())
        if not n:
            break
        init(n)
        m = int(raw_input())
        move(m)
        print n and 'No' or 'Yes'

