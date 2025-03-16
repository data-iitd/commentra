
import sys

h, w = map(int, input().split())
s = "snuke"
for i in range(h):
    for j in range(w):
        t = input()
        if t == s:
            print(chr(ord('A') + j) + str(i + 1))
            sys.exit()

