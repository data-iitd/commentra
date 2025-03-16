
import sys

n, m, q = map(int, sys.stdin.readline().split())
a = [0] * q
b = [0] * q
c = [0] * q
d = [0] * q

for i in range(q):
    a[i], b[i], c[i], d[i] = map(int, sys.stdin.readline().split())
    a[i] -= 1
    b[i] -= 1

def dfs(list):
    if len(list) == n:
        score = 0
        for i in range(q):
            score += d[i] if list[b[i]] - list[a[i]] == c[i] else 0
        global ans
        ans = max(ans, score)
        return

    if list:
        for num in range(list[-1] + 1, m + 1):
            list.append(num)
            dfs(list)
            list.pop()
    else:
        for num in range(1, m + 1):
            list.append(num)
            dfs(list)
            list.pop()

ans = -100
dfs([])
print(ans)

