
# Class representing an edge in the graph
class Edge:
    def __init__(self, from, to, weight):
        self.from = from
        self.to = to
        self.weight = weight

    def __str__(self):
        return str(self.from) + " - " + str(self.to) + " : " + str(self.weight)

# Class implementing the Union-Find (Disjoint Set Union) data structure
class UnionFind:
    def __init__(self, size):
        self.parent = [i for i in range(size)]
        self.rank = [0 for i in range(size)]

    def find(self, x):
        if self.parent[x] != x:
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

# Method to perform Main's algorithm to find the Minimum Spanning Tree (MST)
def kruskal(edges, vertices):
    # Sort edges based on their weights in ascending order
    edges.sort(key=lambda edge: edge.weight)
    uf = UnionFind(vertices)  # Initialize Union-Find structure
    mst = []  # List to store the edges of the MST

    # Iterate through the sorted edges
    for edge in edges:
        # If the edge connects two different components, add it to the MST
        if uf.union(edge.from, edge.to):
            mst.append(edge)
        # Stop if we have added enough edges to the MST
        if len(mst) == vertices - 1:
            break
    return mst  # Return the resulting MST

# Main method to execute the program
def main():
    vertices = int(input())  # Read the number of vertices
    edges = int(input())  # Read the number of edges
    edgeList = []  # List to store all edges

    # Read edges from input
    for i in range(edges):
        from = int(input())  # Read starting vertex
        to = int(input())  # Read ending vertex
        weight = int(input())  # Read weight of the edge
        edgeList.append(Edge(from, to, weight))  # Add edge to the list

    # Compute the Minimum Spanning Tree using Main's algorithm
    mst = kruskal(edgeList, vertices)
    print("Minimum Spanning Tree (MST):")
    # Print the edges in the MST
    for edge in mst:
        print(edge)

if __name__ == "__main__":
    main()
