
import sys

n = int(raw_input())
a = [int(raw_input()) for i in range(n)]
a.sort()
min = a[0]
for value in a:
    if value % min!= 0:
        print -1
        sys.exit()
print min

