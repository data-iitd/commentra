

import sys
sys.setrecursionlimit(10**6)

def dfs(a, pre):
    h = 0
    for i in lists[a]:
        h = max(h, dfs(i, a))
    if 0 < pre and h == k - 1:
        h = 0
        answer += 1
    else:
        h += 1
    return h

n, k = map(int, input().split())
as = list(map(int, input().split()))
answer = 0
lists = [[] for _ in range(n)]
for i in range(n):
    j = as[i]
    if i > 0:
        lists[j].append(i)
    elif j > 0:
        answer += 1
dfs(0, -1)
print(answer)

These comments should provide a clear understanding of the code logic for each block. Let me know if you need any further clarification.