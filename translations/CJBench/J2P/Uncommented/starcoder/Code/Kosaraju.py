
import sys
import collections

class Main:
    def __init__(self):
        self.stack = []
        self.scc = []
        self.sccsList = []

    def kosaraju(self, v, list):
        self.sortEdgesByLowestFinishTime(v, list)
        transposeGraph = self.createTransposeMatrix(v, list)
        self.findStronglyConnectedComponents(v, transposeGraph)
        return self.sccsList

    def sortEdgesByLowestFinishTime(self, v, list):
        vis = [0] * v
        for i in range(v):
            if vis[i] == 0:
                self.dfs(i, vis, list)

    def createTransposeMatrix(self, v, list):
        transposeGraph = []
        for i in range(v):
            transposeGraph.append([])
        for i in range(v):
            for neigh in list[i]:
                transposeGraph[neigh].append(i)
        return transposeGraph

    def findStronglyConnectedComponents(self, v, transposeGraph):
        vis = [0] * v
        while len(self.stack) > 0:
            node = self.stack.pop()
            if vis[node] == 0:
                self.dfs2(node, vis, transposeGraph)
                self.sccsList.append(self.scc)
                self.scc = []

    def dfs(self, node, vis, list):
        vis[node] = 1
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs(neighbour, vis, list)
        self.stack.append(node)

    def dfs2(self, node, vis, list):
        vis[node] = 1
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs2(neighbour, vis, list)
        self.scc.append(node)

if __name__ == "__main__":
    v = int(sys.stdin.readline().strip())
    e = int(sys.stdin.readline().strip())
    list = []
    for i in range(v):
        list.append([])
    for i in range(e):
        u, v = map(int, sys.stdin.readline().strip().split())
        list[u].append(v)
    kosaraju = Main()
    sccs = kosaraju.kosaraju(v, list)
    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc)

