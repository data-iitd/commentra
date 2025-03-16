
import sys

n = int(input())
a = list(map(int, input().split()))
pre = [0] * (n + 1)
last = [0] * (n + 1)

sumpre = 0
sumlast = 0
for i in range(1, n):
    sumpre += a[i]
    pre[i] = sumpre
for i in range(n - 1, 0, -1):
    sumlast += a[i]
    last[i] = sumlast

d = 2 ** 60
for i in range(1, n):
    d = min(d, abs(pre[i] - last[i + 1]))

print(d)

