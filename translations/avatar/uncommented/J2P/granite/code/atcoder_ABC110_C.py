
import sys

S = input()
T = input()

A = [ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" ]

res = True

for s in A:
    sIdx = S.find(s)
    if sIdx < 0:
        continue
    t = str(T[sIdx])
    idx = 0
    while True:
        if S.find(s, idx) >= 0:
            if S.find(s, idx)!= T.find(t, idx):
                res = False
                break
            else:
                idx = S.find(s, idx) + 1
        else:
            if T.find(t, idx) >= 0:
                res = False
                break
            else:
                break

if res:
    print("Yes")
else:
    print("No")

