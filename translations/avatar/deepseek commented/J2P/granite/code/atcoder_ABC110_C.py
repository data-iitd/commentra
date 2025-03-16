
import sys

S = input()
T = input()

A = "abcdefghijklmnopqrstuvwxyz"

res = True

for s in A:
    sIdx = S.find(s)
    if sIdx == -1:
        continue
    t = T[sIdx]

    idx = 0
    while idx < len(S):
        if S.find(s, idx)!= -1:
            if S.find(s, idx)!= T.find(t, idx):
                res = False
                break
            else:
                idx = S.find(s, idx) + 1
        elif T.find(t, idx)!= -1:
            res = False
            break
        else:
            break

if res:
    print("Yes")
else:
    print("No")

