
n = int(input())
m = int(input())
req = []
pre = []
for i in range(n):
    req.append(int(input()))
for i in range(m):
    pre.append(int(input()))
i = n - 1
j = m - 1
ans = 0
while i >= 0 and j >= 0:
    if req[i] > pre[j]:
        ans += 1
    else:
        j -= 1
    i -= 1
print(ans + i + 1)
