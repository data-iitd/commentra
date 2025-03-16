def print_edge(e):
    for i in range(1, len(e)):
        print(f"{i}: ", end="")
        for v in e[i]:
            print(f"{v} ", end="")
        print()

def dfs(v, visited):
    visited[v] = True
    count = 1
    for ne in e[v]:
        if not visited[ne]:
            count += dfs(ne, visited)
    return count

def main():
    global e
    n, m = map(int, input().split())
    e = [[] for _ in range(n+1)]
    for _ in range(m):
        a, b = map(int, input().split())
        e[a].append(b)
        e[b].append(a)
    # print_edge(e)
    visited = [False] * (n+1)
    visited[1] = True
    count = dfs(1, visited)
    print(count)

