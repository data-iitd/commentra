

import sys

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
        transposeGraph = [[] for _ in range(v)]
        for i in range(v):
            for neigh in list[i]:
                transposeGraph[neigh].append(i)
        return transposeGraph

    def findStronglyConnectedComponents(self, v, transposeGraph):
        vis = [0] * v
        while self.stack:
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
    v, edges = map(int, input().split())
    adjacencyList = [[] for _ in range(v)]
    for _ in range(edges):
        u, v = map(int, input().split())
        adjacencyList[u].append(v)
    kosaraju = Main()
    sccs = kosaraju.kosaraju(v, adjacencyList)
    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc)

