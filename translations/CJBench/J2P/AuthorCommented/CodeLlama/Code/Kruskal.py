
import sys

class Edge:
    def __init__(self, from, to, weight):
        self.from = from
        self.to = to
        self.weight = weight

    def __str__(self):
        return str(self.from) + " - " + str(self.to) + " : " + str(self.weight)

class UnionFind:
    def __init__(self, size):
        self.parent = [i for i in range(size)]
        self.rank = [0 for i in range(size)]

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x]) # Path compression
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX == rootY:
            return False

        # Union by rank
        if self.rank[rootX] > self.rank[rootY]:
            self.parent[rootY] = rootX
        elif self.rank[rootX] < self.rank[rootY]:
            self.parent[rootX] = rootY
        else:
            self.parent[rootY] = rootX
            self.rank[rootX] += 1

        return True

def kruskal(edges, vertices):
    edges.sort(key=lambda edge: edge.weight) # Sort edges by weight
    uf = UnionFind(vertices)
    mst = []

    for edge in edges:
        if uf.union(edge.from, edge.to): # Add edge if it connects two separate components
            mst.append(edge)
        if len(mst) == vertices - 1: # Stop when MST is complete
            break

    return mst

if __name__ == "__main__":
    vertices, edges = map(int, sys.stdin.readline().split())

    edgeList = []
    for i in range(edges):
        from, to, weight = map(int, sys.stdin.readline().split())
        edgeList.append(Edge(from, to, weight))

    mst = kruskal(edgeList, vertices)

    print("Minimum Spanning Tree (MST):")
    for edge in mst:
        print(edge)

