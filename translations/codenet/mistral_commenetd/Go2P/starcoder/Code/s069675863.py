
import sys

S = sys.stdin.readline().rstrip()
x, y = map(int, sys.stdin.readline().split())

evens = [int(S[i]) for i in range(0, len(S), 2)]
odds = [int(S[i]) for i in range(1, len(S), 2)]

dpx = [[False] * 20000 for _ in range(8000)]
dpy = [[False] * 20000 for _ in range(8000)]

for i in range(len(evens)):
    updateDPX(i, evens[i])

for i in range(len(odds)):
    updateDPY(i, odds[i])

if dpx[len(evens)][x+10000] and dpy[len(odds)][y+10000]:
    print("Yes")
else:
    print("No")

