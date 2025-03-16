import sys

# Represents an edge in the graph with 'from', 'to', and 'weight' attributes.
class Edge:
    def __init__(self, from, to, weight):
        self.from = from
        self.to = to
        self.weight = weight
    def __str__(self):
        return str(self.from) + " - " + str(self.to) + " : " + str(self.weight)

# Implements the Union-Find (Disjoint Set Union) data structure for tracking connected components.
class UnionFind:
    def __init__(self, size):
        self.parent = [i for i in range(size)]
        self.rank = [0 for i in range(size)]
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x]) # Path compression.
        return self.parent[x]
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX == rootY:
            return False # They are already in the same set.
        if self.rank[rootX] > self.rank[rootY]:
            self.parent[rootY] = rootX # Attach smaller rank tree under root of higher rank tree.
        elif self.rank[rootX] < self.rank[rootY]:
            self.parent[rootX] = rootY
        else:
            self.parent[rootY] = rootX
            self.rank[rootX] += 1 # If ranks are same, then make one as root and increment its rank.
        return True

# Implements Main's algorithm to find the Minimum Spanning Tree (MST) of the graph.
def kruskal(edges, vertices):
    edges.sort(key=lambda edge: edge.weight) # Sort edges by weight.
    uf = UnionFind(vertices)
    mst = []
    for edge in edges:
        if uf.union(edge.from, edge.to): # Add edge to MST if it doesn't form a cycle.
            mst.append(edge)
        if len(mst) == vertices - 1: # Stop if MST has 'vertices - 1' edges.
            break
    return mst

# Main method to read input, compute MST, and print the result.
def main():
    vertices, edges = map(int, sys.stdin.readline().split())
    edgeList = []
    for i in range(edges):
        from, to, weight = map(int, sys.stdin.readline().split())
        edgeList.append(Edge(from, to, weight))
    mst = kruskal(edgeList, vertices)
    print("Minimum Spanning Tree (MST):")
    for edge in mst:
        print(edge) # Print each edge in the MST.

if __name__ == "__main__":
    main()
