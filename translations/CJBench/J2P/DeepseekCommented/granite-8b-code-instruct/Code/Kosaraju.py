
import sys
sys.setrecursionlimit(10**6)

def kosaraju(v, list):
    vis = [0] * v
    stack = []
    for i in range(v):
        if vis[i] == 0:
            dfs(i, vis, list)
    sccsList = []
    while stack:
        node = stack.pop()
        if vis[node] == 0:
            dfs2(node, vis, list)
            sccsList.append(scc)
            scc = []
    return sccsList

def dfs(node, vis, list):
    vis[node] = 1
    for neighbour in list[node]:
        if vis[neighbour] == 0:
            dfs(neighbour, vis, list)
    stack.append(node)

def dfs2(node, vis, list):
    vis[node] = 1
    for neighbour in list[node]:
        if vis[neighbour] == 0:
            dfs2(neighbour, vis, list)
    scc.append(node)

if __name__ == "__main__":
    vertices, edges = map(int, input().split())
    adjacencyList = [[] for _ in range(vertices)]
    for _ in range(edges):
        u, v = map(int, input().split())
        adjacencyList[u].append(v)
    kosaraju = Main()
    sccs = kosaraju.kosaraju(vertices, adjacencyList)
    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc)

