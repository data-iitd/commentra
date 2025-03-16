n, m = map(int, input().split())
e = [[] for i in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    e[a] += [b]
    e[b] += [a]

def dfs(v, visited):
    visited[v] = True
    # print(v, visited)

    comp = True
    for i in range(1, n+1):
        if not visited[i]:
            comp = False
    if comp:
        return 1

    count = 0
    for ne in e[v]:
        # print(ne)
        if visited[ne]:
            continue
        visited[ne] = True
        # if cmp, _ := dfs(ne, visited, count); cmp:
        #     count += 1
        # else:
        #     count += dfs(ne, visited)
        count += dfs(ne, visited)
        visited[ne] = False
    return count

visited = [False for i in range(n+1)]
visited[1] = True
count = dfs(1, visited)
print(count)

