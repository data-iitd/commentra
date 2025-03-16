
import sys

e = []
n, m = map(int, sys.stdin.readline().split())

def printEdge(e):
    for i in range(1, n+1):
        print(i, end=' ')
        for v in e[i]:
            print(v, end=' ')
        print()

def dfs(v, visited):
    # visited[v] = True
    # print(v, visited)

    comp = True
    for i in range(1, n+1):
        if not visited[i]:
            comp = False
    if comp:
        return 1

    count = 0
    for ne in e[v]:
        # print("ne=", ne)
        if visited[ne]:
            continue
        visited[ne] = True
        # if cmp, _ := dfs(ne, visited, count); cmp:
        #     count += 1
        count += dfs(ne, visited)
        visited[ne] = False
    return count

visited = [False] * (n+1)
visited[1] = True
count = dfs(1, visited)
print(count)

