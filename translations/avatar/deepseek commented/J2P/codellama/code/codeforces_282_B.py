
import sys

n = int(input())
ch = []
s1 = 0
s2 = 0

for i in range(n):
    x, y = map(int, input().split())
    temp1 = s1 + x
    temp2 = s2 + y

    if abs(temp1 - s2) <= 500:
        s1 += x
        ch.append('A')
    elif abs(temp2 - s1) <= 500:
        s2 += y
        ch.append('G')
    else:
        print(-1)
        break

ans = ''.join(ch)
print(ans)

