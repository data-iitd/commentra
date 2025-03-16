import sys
import heapq

class Edge:
    def __init__(self, from, to, weight):
        self.from = from
        self.to = to
        self.weight = weight
    def __lt__(self, other):
        return self.weight < other.weight
    def __str__(self):
        return str(self.from) + " - " + str(self.to) + " : " + str(self.weight)

class UnionFind:
    def __init__(self, size):
        self.parent = [i for i in range(size)]
        self.rank = [0 for i in range(size)]
    def find(self, x):
        if self.parent[x]!= x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX == rootY:
            return False
        if self.rank[rootX] > self.rank[rootY]:
            self.parent[rootY] = rootX
        else:
            self.parent[rootX] = rootY
            if self.rank[rootX] == self.rank[rootY]:
                self.rank[rootY] += 1
        return True

def kruskal(edges, vertices):
    edges.sort()
    uf = UnionFind(vertices)
    mst = []
    for edge in edges:
        if uf.union(edge.from, edge.to):
            mst.append(edge)
        if len(mst) == vertices - 1:
            break
    return mst

if __name__ == "__main__":
    vertices = int(sys.stdin.readline().strip())
    edges = int(sys.stdin.readline().strip())
    edgeList = []
    for i in range(edges):
        fromVertex, toVertex, weight = map(int, sys.stdin.readline().strip().split())
        edgeList.append(Edge(fromVertex, toVertex, weight))
    mst = kruskal(edgeList, vertices)
    print("Minimum Spanning Tree (MST):")
    for edge in mst:
        print(edge)

