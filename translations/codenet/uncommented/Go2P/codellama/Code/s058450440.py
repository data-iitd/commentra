
import sys

def dfs(left, i, res):
    if left == 0:
        global ans
        ans += res
        return
    for j in range(i, len(a)):
        dfs(left-1, j+1, res*a[j])

def main():
    io = sys.stdin
    n = int(io.readline().strip())
    dic = {}

    for _ in range(n):
        c = io.readline().strip()[0]
        if c in 'MARC':
            dic[c] = dic.get(c, 0) + 1

    a = []
    for k, v in dic.items():
        a.append(v)

    dfs(3, 0, 1)
    print(ans)


