
import array
import sys

n = int(input())
a = array.array('i', [int(x) for x in input().split()])
a.sort()
min = a[0]
for value in a:
    if value % min != 0:
        print(-1)
        break
else:
    print(min)

