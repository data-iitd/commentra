
import sys
from collections import defaultdict

def stronglyConnectedComponents(v, graph):
    lowTime = [0] * v
    insertionTime = [0] * v
    isInStack = [False] * v
    stack = []
    for i in range(v):
        if insertionTime[i] == 0:
            dfs(i, lowTime, insertionTime, isInStack, stack, graph)
    return sccList

def dfs(u, lowTime, insertionTime, isInStack, stack, graph):
    insertionTime[u] = time
    lowTime[u] = time
    global time
    time += 1
    stack.append(u)
    isInStack[u] = True
    for v in graph[u]:
        if insertionTime[v] == 0:
            dfs(v, lowTime, insertionTime, isInStack, stack, graph)
            lowTime[u] = min(lowTime[u], lowTime[v])
        elif isInStack[v]:
            lowTime[u] = min(lowTime[u], insertionTime[v])
    if lowTime[u] == insertionTime[u]:
        scc = []
        while stack[-1] != u:
            w = stack.pop()
            scc.append(w)
            isInStack[w] = False
        w = stack.pop()
        scc.append(w)
        isInStack[w] = False
        sccList.append(scc)

if __name__ == "__main__":
    v, e = map(int, sys.stdin.readline().split())
    graph = defaultdict(list)
    for i in range(e):
        from_, to = map(int, sys.stdin.readline().split())
        graph[from_].append(to)
    time = 1
    sccList = []
    sccs = stronglyConnectedComponents(v, graph)
    for scc in sccs:
        print(scc)
    # 