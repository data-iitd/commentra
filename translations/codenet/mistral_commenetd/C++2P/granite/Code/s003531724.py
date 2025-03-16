
import sys
input = sys.stdin.readline

# Define a function to perform a depth-first search of the graph
def dfs(x, l):
    vis[x] = True
    cnt[l] += 1
    d[x] = l
    for i in range(u[x], u[x + 1]):
        T += 1
        v, ec, pre = e[i]
        if not vis[v]:
            dfs(v, (l + ec) % 3)
        else:
            if (l + ec) % 3!= d[v]:
                ok = False

# Define the main function to read the input and compute the answer
n, m = map(int, input().split())
ans = 0
for i in range(n):
    if not vis[i]:
        T = 0
        for j in range(3):
            cnt[j] = 0
        ok = True
        dfs(i, 0)
        s = cnt[0] + cnt[1] + cnt[2]
        if not ok:
            ans += s * s
        else:
            if cnt[0] and cnt[1] and cnt[2]:
                ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
            else:
                ans += T // 2
print(ans)

