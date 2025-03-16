
import sys
from collections import defaultdict

# Represents an edge in the graph with 'from', 'to', and 'weight' attributes.
class Edge:
    def __init__(self, from_node, to_node, weight):
        self.from_node = from_node
        self.to_node = to_node
        self.weight = weight

    def __str__(self):
        return f"{self.from_node} - {self.to_node} : {self.weight}"

# Implements the Union-Find (Disjoint Set Union) data structure for tracking connected components.
class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size

    def find(self, x):
        if self.parent[x]!= x:
            self.parent[x] = self.find(self.parent[x]) # Path compression.
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x == root_y:
            return False # They are already in the same set.
        if self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x # Attach smaller rank tree under root of higher rank tree.
        elif self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1 # If ranks are same, then make one as root and increment its rank.
        return True

# Implements Main's algorithm to find the Minimum Spanning Tree (MST) of the graph.
def kruskal(edges, vertices):
    edges.sort(key=lambda edge: edge.weight) # Sort edges by weight.
    uf = UnionFind(vertices)
    mst = []
    for edge in edges:
        if uf.union(edge.from_node, edge.to_node): # Add edge to MST if it doesn't form a cycle.
            mst.append(edge)
        if len(mst) == vertices - 1: # Stop if MST has'vertices - 1' edges.
            break
    return mst

# Main method to read input, compute MST, and print the result.
def main():
    vertices, edges = map(int, input().split()) # Read number of vertices and edges.
    edge_list = []
    for _ in range(edges):
        from_node, to_node, weight = map(int, input().split()) # Read 'from' node, 'to' node, and weight of the edge.
        edge_list.append(Edge(from_node, to_node, weight)) # Add edge to the list.
    mst = kruskal(edge_list, vertices)
    print("Minimum Spanning Tree (MST):")
    for edge in mst:
        print(edge) # Print each edge in the MST.

if __name__ == "__main__":
    main()

