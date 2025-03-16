import sys

def stronglyConnectedComponents(v, graph):
    lowTime = [-1] * v
    insertionTime = [-1] * v
    isInStack = [False] * v
    stack = []
    sccList = []
    time = 0

    # Perform DFS for each unvisited node
    for i in range(v):
        if insertionTime[i] == -1:
            dfs(i, lowTime, insertionTime, isInStack, stack, graph)

    return sccList

def dfs(u, lowTime, insertionTime, isInStack, stack, graph):
    global time
    insertionTime[u] = time
    lowTime[u] = time
    time += 1
    stack.append(u)
    isInStack[u] = True

    # Visit all adjacent nodes
    for v in graph[u]:
        if insertionTime[v] == -1:
            dfs(v, lowTime, insertionTime, isInStack, stack, graph)
            lowTime[u] = min(lowTime[u], lowTime[v])
        elif isInStack[v]:
            lowTime[u] = min(lowTime[u], insertionTime[v])

    # If the current node is the root of an SCC
    if lowTime[u] == insertionTime[u]:
        scc = []
        while stack[-1] != u:
            w = stack.pop()
            scc.append(w)
            isInStack[w] = False
        scc.append(u)
        sccList.append(scc)

if __name__ == "__main__":
    v, e = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(v)]
    for _ in range(e):
        from_, to = map(int, sys.stdin.readline().split())
        graph[from_].append(to)

    sccs = stronglyConnectedComponents(v, graph)
    for scc in sccs:
        print(scc)

