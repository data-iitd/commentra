
import sys
from collections import defaultdict

# Class representing an edge in the graph
class Edge:
    def __init__(self, from_vertex, to_vertex, weight):
        self.from_vertex = from_vertex
        self.to_vertex = to_vertex
        self.weight = weight

    def __str__(self):
        return f"{self.from_vertex} - {self.to_vertex} : {self.weight}"

# Class implementing the Union-Find (Disjoint Set Union) data structure
class UnionFind:
    def __init__(self, vertices):
        self.parent = list(range(vertices)) # Array to track the parent of each node
        self.rank = [0] * vertices # Array to track the rank (depth) of each tree

    # Find the root of the set containing 'x' with path compression
    def find(self, x):
        if self.parent[x]!= x:
            self.parent[x] = self.find(self.parent[x]) # Path compression
        return self.parent[x]

    # Union the sets containing 'x' and 'y'
    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        # If they are already in the same set, return false
        if root_x == root_y:
            return False
        # Union by rank to keep the tree flat
        if self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        elif self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1
        return True # Successfully unioned

# Method to perform Main's algorithm to find the Minimum Spanning Tree (MST)
def kruskal(edges, vertices):
    # Sort edges based on their weights in ascending order
    edges.sort(key=lambda edge: edge.weight)
    uf = UnionFind(vertices) # Initialize Union-Find structure
    mst = [] # List to store the edges of the MST

    # Iterate through the sorted edges
    for edge in edges:
        # If the edge connects two different components, add it to the MST
        if uf.union(edge.from_vertex, edge.to_vertex):
            mst.append(edge)
        # Stop if we have added enough edges to the MST
        if len(mst) == vertices - 1:
            break
    return mst # Return the resulting MST

# Main method to execute the program
def main():
    vertices, edges = map(int, input().split()) # Read the number of vertices and edges
    edge_list = [] # List to store all edges

    # Read edges from input
    for _ in range(edges):
        from_vertex, to_vertex, weight = map(int, input().split()) # Read starting vertex, ending vertex, and weight of the edge
        edge_list.append(Edge(from_vertex, to_vertex, weight)) # Add edge to the list

    # Compute the Minimum Spanning Tree using Main's algorithm
    mst = kruskal(edge_list, vertices)
    print("Minimum Spanning Tree (MST):")
    # Print the edges in the MST
    for edge in mst:
        print(edge)

if __name__ == "__main__":
    main()

