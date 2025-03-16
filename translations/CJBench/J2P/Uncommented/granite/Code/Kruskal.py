
import sys
sys.setrecursionlimit(10**6)

class Edge:
    def __init__(self, from_, to, weight):
        self.from_ = from_
        self.to = to
        self.weight = weight
    def __str__(self):
        return f"{self.from_} - {self.to} : {self.weight}"

class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size
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
        elif self.rank[rootX] < self.rank[rootY]:
            self.parent[rootX] = rootY
        else:
            self.parent[rootY] = rootX
            self.rank[rootX] += 1
        return True

def kruskal(edges, vertices):
    edges.sort(key=lambda edge: edge.weight) 
    uf = UnionFind(vertices)
    mst = []
    for edge in edges:
        if uf.union(edge.from_, edge.to):
            mst.append(edge)
        if len(mst) == vertices - 1:
            break
    return mst

if __name__ == "__main__":
    vertices, edges = map(int, input().split())
    edgeList = []
    for _ in range(edges):
        from_, to, weight = map(int, input().split())
        edgeList.append(Edge(from_, to, weight))
    mst = kruskal(edgeList, vertices)
    print("Minimum Spanning Tree (MST):")
    for edge in mst:
        print(edge)

