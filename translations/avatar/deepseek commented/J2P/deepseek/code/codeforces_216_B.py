def dfs(child, par, graph, seen, count, path, cycle):
    if seen[child]:
        return cycle
    seen[child] = True
    for i in graph[child]:
        if i != par:
            count += 1
            if dfs(i, child, graph, seen, count, path, cycle) == cycle:
                return cycle
    return path

def main():
    m = int(input())
    n = int(input())
    graph = [[] for _ in range(m + 1)]
    seen = [False] * (m + 1)
    for _ in range(n):
        x, y = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)
    toremove = 0
    for i in range(1, m + 1):
        if not seen[i]:
            count = 0
            if dfs(i, 0, graph, seen, count, 0, 1) == 1:
                if count % 2 == 1:
                    toremove += 1
    if (m - toremove) % 2 == 1:
        toremove += 1
    print(toremove)

