

def print_edge(e):
    for i in range(1, n+1):
        print(f"{i}: ", end="")
        for v in e[i]:
            print(f"{v} ", end="")
        print()

def dfs(v, visited):
    # Mark the current node as visited
    # print(v, visited)

    # Check if all nodes are visited
    comp = True
    for i in range(1, n+1):
        if not visited[i]:
            comp = False
    if comp:
        return 1

    count = 0
    for ne in e[v]:
        if visited[ne]:
            continue
        visited[ne] = True
        # if cmp, _ := dfs(ne, visited, count); cmp:
        #     count += 1
        # else:
        #     visited[ne] = False
        rst = dfs(ne, visited)
        count += rst
        visited[ne] = False
    return count

if __name__ == "__main__":
    n, m = map(int, input().split())

    # Initialize the graph edges
    e = [[] for _ in range(n+1)]

    # Read the edges and populate the graph
    for _ in range(m):
        a, b = map(int, input().split())
        e[a].append(b)
        e[b].append(a)
    # print_edge(e)

    # Initialize visited slice and start DFS from node 1
    visited = [False] * (n+1)
    visited[1] = True
    count = dfs(1, visited)
    print(count)

