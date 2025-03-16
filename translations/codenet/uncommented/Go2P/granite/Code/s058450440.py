
import sys

n = int(input())
dic = {}

for _ in range(n):
    c = input()[0]
    if c in ['M', 'A', 'R', 'C', 'H']:
        dic[c] = dic.get(c, 0) + 1

a = list(dic.values())
ans = 0

def dfs(left, i, res):
    global ans
    if left == 0:
        ans += res
        return
    for j in range(i, len(a)):
        dfs(left-1, j+1, res*a[j])

dfs(3, 0, 1)
print(ans)

