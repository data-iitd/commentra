
# -*- coding: utf-8 -*-

# <START-OF-CODE>

import sys

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

S = input()
x, y = [int(i) for i in input().split()]

F = []
cur = 0

for i in range(len(S)):
    if S[i] == 'F':
        cur += 1
    else:
        F.append(cur)
        cur = 0

F.append(cur)

evens, odds = [], []

for i in range(len(F)):
    if i % 2 == 0:
        evens.append(F[i])
    else:
        odds.append(F[i])

dpx = [[False for i in range(18000)] for j in range(len(evens)+1)]
dpy = [[False for i in range(18000)] for j in range(len(odds)+1)]

dpx[0][10000] = True
dpy[0][10000] = True

for i in range(len(evens)):
    val = evens[i]
    for j in range(2000, 18000):
        if j+val <= 18000:
            dpx[i+1][j+val] = dpx[i+1][j+val] or dpx[i][j]
        if j-val >= 2000 and i!= 0:
            dpx[i+1][j-val] = dpx[i+1][j-val] or dpx[i][j]

for i in range(len(odds)):
    val = odds[i]
    for j in range(2000, 18000):
        if j+val <= 18000:
            dpy[i+1][j+val] = dpy[i+1][j+val] or dpy[i][j]
        if j-val >= 2000:
            dpy[i+1][j-val] = dpy[i+1][j-val] or dpy[i][j]

if dpx[len(evens)][x+10000] and dpy[len(odds)][y+10000]:
    print("Yes")
else:
    print("No")

# 