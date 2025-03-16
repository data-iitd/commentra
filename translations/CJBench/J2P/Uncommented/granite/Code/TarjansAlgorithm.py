

import sys
sys.setrecursionlimit(100000)

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
            elif isInStack[v]:
                lowTime[u] = min(lowTime[u], insertionTime[v])
        if lowTime[u] == insertionTime[u]:
            scc = []
            while stack[-1]!= u:
                w = stack.pop()
                isInStack[w] = False
                scc.append(w)
            scc.append(u)
            isInStack[u] = False
            self.sccList.append(scc)

    def main(self):
        vertices, edges = map(int, input().split())
        graph = [[] for _ in range(vertices)]
        for _ in range(edges):
            from_v, to_v = map(int, input().split())
            graph[from_v].append(to_v)
        tarjans = Main()
        sccs = tarjans.stronglyConnectedComponents(vertices, graph)
        for scc in sccs:
            print(scc)

if __name__ == "__main__":
    Main().main()

