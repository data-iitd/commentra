

import sys
sys.setrecursionlimit(10**6)
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
def kosaraju(v, list):
    vis = [0]*v
    for i in range(v):
        if vis[i] == 0:
            dfs(i, vis, list)
    vis = [0]*v
    sccsList = []
    while stack:
        node = stack.pop()
        if vis[node] == 0:
            scc = []
            dfs2(node, vis, list)
            sccsList.append(scc)
    return sccsList
if __name__ == "__main__":
    vertices, edges = map(int, input().split())
    list = [[] for _ in range(vertices)]
    for _ in range(edges):
        u, v = map(int, input().split())
        list[u].append(v)
    stack = []
    scc = []
    sccsList = kosaraju(vertices, list)
    print("Strongly Connected Components:")
    for scc in sccsList:
        print(scc)
