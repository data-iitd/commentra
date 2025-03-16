def print_edge(e, n):
    for i in range(1, n + 1):
        print(f"{i}: ", end="")
        for v in e[i]:
            print(f"{v} ", end="")
        print()

def dfs(v, visited, e, n):
    comp = all(visited[1:n + 1])

    if comp:
        return 1

    count = 0
    for ne in e[v]:
        if visited[ne]:
            continue
        visited[ne] = True
        count += dfs(ne, visited, e, n)
        visited[ne] = False
    return count

def main():
    n, m = map(int, input().split())
    
    e = [[] for _ in range(n + 1)]
    for _ in range(m):
        a, b = map(int, input().split())
        e[a].append(b)
        e[b].append(a)

    # print_edge(e, n)

    visited = [False] * (n + 1)
    visited[1] = True
    count = dfs(1, visited, e, n)
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
