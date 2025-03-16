

import sys
from collections import defaultdict

# Define a custom Edge class to store edge information (from, to, weight)
class Edge:
    def __init__(self, from_node, to_node, weight):
        self.from_node = from_node
        self.to_node = to_node
        self.weight = weight

    def __str__(self):
        return f"{self.from_node} - {self.to_node} : {self.weight}"

# Define a custom UnionFind data structure for handling disjoint sets
class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size

    def find(self, x):
        if self.parent[x]!= x:
            # Path compression and union by rank to improve performance
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        # If the given elements are already in the same set, return false
        if root_x == root_y:
            return False

        # Connect the smaller rank set to the larger rank set to maintain a forest
        if self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        elif self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1

        # Return true to indicate successful union
        return True

# Main's algorithm implementation to find the minimum spanning tree (MST)
def kruskal(edges, vertices):
    # Sort the given edges in non-decreasing order of their weights
    sorted_edges = sorted(edges, key=lambda edge: edge.weight)

    # Initialize UnionFind data structure with the given number of vertices
    uf = UnionFind(vertices)

    # Initialize an empty list to store the MST edges
    mst = []

    # Iterate through the sorted edges and add them to the MST if they don't form a cycle
    for edge in sorted_edges:
        if uf.union(edge.from_node, edge.to_node):
            mst.append(edge)

        # Once the MST contains (V-1) edges, break the loop
        if len(mst) == vertices - 1:
            break

    # Return the computed MST
    return mst

# Main method to read input and call the kruskal algorithm
def main():
    # Read the number of vertices and edges from the input
    vertices, edges = map(int, input().split())

    # Initialize an empty list to store the edges
    edge_list = []

    # Read the edges from the input and add them to the list
    for _ in range(edges):
        from_node, to_node, weight = map(int, input().split())
        edge_list.append(Edge(from_node, to_node, weight))

    # Call the kruskal algorithm to find the minimum spanning tree (MST)
    mst = kruskal(edge_list, vertices)

    # Print the computed MST
    print("Minimum Spanning Tree (MST):")
    for edge in mst:
        print(edge)

if __name__ == "__main__":
    main()

Translate the above Python code to C++ and end with comment "