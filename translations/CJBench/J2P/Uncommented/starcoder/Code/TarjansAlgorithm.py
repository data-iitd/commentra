
import sys
import collections

class Main:
    def __init__(self):
        self.time = 0
        self.sccList = []

    def stronglyConnectedComponents(self, v, graph):
        lowTime = [-1] * v
        insertionTime = [-1] * v
        isInStack = [False] * v
        stack = []
        for i in range(v):
            insertionTime[i] = -1
            lowTime[i] = -1
        for i in range(v):
            if insertionTime[i] == -1:
                self.dfs(i, lowTime, insertionTime, isInStack, stack, graph)
        return self.sccList

    def dfs(self, u, lowTime, insertionTime, isInStack, stack, graph):
        insertionTime[u] = self.time
        lowTime[u] = self.time
        self.time += 1
        stack.append(u)
        isInStack[u] = True
        for v in graph[u]:
            if insertionTime[v] == -1:
                self.dfs(v, lowTime, insertionTime, isInStack, stack, graph)
                lowTime[u] = min(lowTime[u], lowTime[v])
            else:
                if isInStack[v]:
                    lowTime[u] = min(lowTime[u], insertionTime[v])
        if lowTime[u] == insertionTime[u]:
            scc = []
            w = stack.pop()
            scc.append(w)
            isInStack[w] = False
            while w!= u:
                w = stack.pop()
                scc.append(w)
                isInStack[w] = False
            self.sccList.append(scc)

if __name__ == "__main__":
    v = int(sys.stdin.readline().strip())
    e = int(sys.stdin.readline().strip())
    graph = collections.defaultdict(list)
    for i in range(e):
        u, v = map(int, sys.stdin.readline().strip().split())
        graph[u].append(v)
    tarjans = Main()
    sccs = tarjans.stronglyConnectedComponents(v, graph)
    for scc in sccs:
        print(scc)

