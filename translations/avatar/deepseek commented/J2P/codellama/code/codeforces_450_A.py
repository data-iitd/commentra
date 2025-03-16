
import sys

n, m = map(int, input().split())

q1 = []
q2 = []

for i in range(n):
    q1.append(int(input()))
    q2.append(i+1)

ans = 0

while q1:
    if q1[0] <= m:
        q1.pop(0)
        ans = q2.pop(0)
    elif q1[0] > m:
        x = q1.pop(0)
        val = x - m
        q1.append(val)
        val2 = q2.pop(0)
        q2.append(val2)

print(ans)

