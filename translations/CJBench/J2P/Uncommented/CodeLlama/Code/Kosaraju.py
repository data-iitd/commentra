
import sys
from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.graph = defaultdict(list)
        self.V = vertices

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def sortEdgesByLowestFinishTime(self, v, list):
        vis = [0] * v
        for i in range(v):
            if vis[i] == 0:
                self.dfs(i, vis, list)

    def createTransposeMatrix(self, v, list):
        transposeGraph = defaultdict(list)
        for i in range(v):
            transposeGraph[i] = []
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

    def kosaraju(self, v, list):
        self.sortEdgesByLowestFinishTime(v, list)
        transposeGraph = self.createTransposeMatrix(v, list)
        self.findStronglyConnectedComponents(v, transposeGraph)
        return self.sccsList

def main():
    vertices = int(sys.stdin.readline().strip())
    edges = int(sys.stdin.readline().strip())
    graph = Graph(vertices)
    for i in range(edges):
        u, v = map(int, sys.stdin.readline().strip().split())
        graph.addEdge(u, v)
    sccs = graph.kosaraju(vertices, graph.graph)
    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc)

if __name__ == "__main__":
    main()

