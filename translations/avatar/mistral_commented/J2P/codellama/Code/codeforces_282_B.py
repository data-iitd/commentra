import math
import sys

n = int(input())
s1 = 0
s2 = 0
ch = []

for i in range(n):
    x = int(input())
    y = int(input())
    temp1 = s1 + x
    temp2 = s2 + y
    if abs(temp1 - temp2) <= 500:
        s1 += x
        ch.append('A')
        continue
    if abs(temp1 - s2) <= 500:
        s2 += y
        ch.append('G')
        continue
    flag = 1
    break

if flag == 1:
    print(-1)
else:
    ans = ''.join(ch)
    print(ans)

