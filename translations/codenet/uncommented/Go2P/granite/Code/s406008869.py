
n, m = map(int, input().split())

e = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    e[a].append(b)
    e[b].append(a)

def print_edge(e):
    for i in range(1, n+1):
        print(f"{i}: {' '.join(map(str, e[i]))}")

def dfs(v, visited):
    visited[v] = True
    comp = all(visited)
    if comp:
        return 1
    count = 0
    for ne in e[v]:
        if not visited[ne]:
            visited[ne] = True
            count += dfs(ne, visited)
            visited[ne] = False
    return count

visited = [False] * (n+1)
visited[1] = True
count = dfs(1, visited)
print(count)
