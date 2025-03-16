
import sys

n = int(raw_input().strip())
a = map(int, raw_input().strip().split(' '))

curr = 0
for i in range(n):
    if a[i] == curr+1:
        curr += 1

if curr > 0:
    print n-curr
else:
    print -1

