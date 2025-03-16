
import sys

def dfs(left, i, res):
    global ans
    if left == 0:
        ans += res
        return
    for j in range(i, len(a)):
        dfs(left - 1, j + 1, res * a[j])

n = int(input())
dic = {}

for _ in range(n):
    c = input()[0]
    if c in dic:
        dic[c] += 1
    else:
        dic[c] = 1

a = []
for k, v in dic.items():
    if k in 'MARCH':
        a.append(v)

ans = 0
dfs(3, 0, 1)
print(ans)

