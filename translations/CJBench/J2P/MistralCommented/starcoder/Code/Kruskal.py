
import sys

# Define a custom Edge class to store edge information (from, to, weight)
class Edge:
    def __init__(self, from, to, weight):
        self.from = from
        self.to = to
        self.weight = weight

    # Override toString method to print edge information in a readable format
    def __str__(self):
        return str(self.from) + " - " + str(self.to) + " : " + str(self.weight)

# Define a custom UnionFind data structure for handling disjoint sets
class UnionFind:
    def __init__(self, size):
        self.parent = [i for i in range(size)]
        self.rank = [0 for i in range(size)]

    # Find the root of the set containing the given element
    def find(self, x):
        if self.parent[x]!= x:
            # Path compression and union by rank to improve performance
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    # Union two sets containing the given elements
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        # If the given elements are already in the same set, return false
        if rootX == rootY:
            return False

        # Connect the smaller rank set to the larger rank set to maintain a forest
        if self.rank[rootX] > self.rank[rootY]:
            self.parent[rootY] = rootX
        elif self.rank[rootX] < self.rank[rootY]:
            self.parent[rootX] = rootY
        else:
            self.parent[rootY] = rootX
            self.rank[rootX] += 1

        # Return true to indicate successful union
        return True

# Main's algorithm implementation to find the minimum spanning tree (MST)
def kruskal(edges, vertices):
    # Sort the given edges in non-decreasing order of their weights
    edges.sort(key=lambda edge: edge.weight)

    # Initialize UnionFind data structure with the given number of vertices
    uf = UnionFind(vertices)

    # Initialize an empty list to store the MST edges
    mst = []

    # Iterate through the sorted edges and add them to the MST if they don't form a cycle
    for edge in edges:
        if uf.union(edge.from, edge.to):
            mst.append(edge)

        # Once the MST contains (V-1) edges, break the loop
        if len(mst) == vertices - 1:
            break

    # Return the computed MST
    return mst

# Main method to read input and call the kruskal algorithm
def main():
    # Read the number of vertices and edges from the input
    vertices = int(input())
    edges = int(input())

    # Initialize an empty list to store the edges
    edgeList = []

    # Read the edges from the input and add them to the list
    for i in range(edges):
        fromVertex = int(input())
        toVertex = int(input())
        weight = int(input())
        edgeList.append(Edge(fromVertex, toVertex, weight))

    # Call the kruskal algorithm to find the minimum spanning tree (MST)
    mst = kruskal(edgeList, vertices)

    # Print the computed MST
    print("Minimum Spanning Tree (MST):")
    for edge in mst:
        print(edge)

if __name__ == "__main__":
    main()

