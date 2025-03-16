

import sys

S = input()
x, y = map(int, input().split())

F = []
cur = 0
for i in range(len(S)):
    if S[i] == 'F':
        cur += 1
    else:
        F.append(cur)
        cur = 0
F.append(cur)

dpx = [[False] * 20001 for _ in range(len(F) + 1)]
dpy = [[False] * 20001 for _ in range(len(F) + 1)]
dpx[0][10000] = True
dpy[0][10000] = True

for i in range(len(F)):
    val = F[i]
    for j in range(20000):
        if j + val <= 20000:
            dpx[i + 1][j + val] |= dpx[i][j]
        if j - val >= 0:
            dpx[i + 1][j - val] |= dpx[i][j]

for i in range(len(F)):
    val = F[i]
    for j in range(20000):
        if j + val <= 20000:
            dpy[i + 1][j + val] |= dpy[i][j]
        if j - val >= 0:
            dpy[i + 1][j - val] |= dpy[i][j]

if dpx[len(F)][x + 10000] and dpy[len(F)][y + 10000]:
    print("Yes")
else:
    print("No")

