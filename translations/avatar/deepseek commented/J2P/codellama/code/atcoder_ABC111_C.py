
import sys

n = int(sys.stdin.readline())
v = [0] * 100010
vo = [0] * 100010
ve = [0] * 100010
vt = [0] * 100010

for i in range(n):
    v[i] = int(sys.stdin.readline())
    vt[v[i]] += 1
    if i % 2 == 0:
        ve[v[i]] += 1
    else:
        vo[v[i]] += 1

for i in range(100010):
    vo[i] = vo[i] + vo[i-1]
    ve[i] = ve[i] + ve[i-1]
    vt[i] = vt[i] + vt[i-1]

ans = 0
if vo[0] + ve[0] == vt[0]:
    ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0])
else:
    ans = n - vo[0] - ve[0]

print(ans)

# 