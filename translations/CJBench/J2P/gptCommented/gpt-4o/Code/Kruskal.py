class Edge:
    def __init__(self, from_vertex, to_vertex, weight):
        self.from_vertex = from_vertex  # Starting vertex of the edge
        self.to_vertex = to_vertex      # Ending vertex of the edge
        self.weight = weight            # Weight of the edge

    def __str__(self):
        return f"{self.from_vertex} - {self.to_vertex} : {self.weight}"


class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))  # Array to track the parent of each node
        self.rank = [0] * size            # Array to track the rank (depth) of each tree

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX == rootY:
            return False  # They are already in the same set
        # Union by rank
        if self.rank[rootX] > self.rank[rootY]:
            self.parent[rootY] = rootX
        elif self.rank[rootX] < self.rank[rootY]:
            self.parent[rootX] = rootY
        else:
            self.parent[rootY] = rootX
            self.rank[rootX] += 1
        return True  # Successfully unioned


def kruskal(edges, vertices):
    edges.sort(key=lambda edge: edge.weight)  # Sort edges based on their weights
    uf = UnionFind(vertices)  # Initialize Union-Find structure
    mst = []  # List to store the edges of the MST

    for edge in edges:
        if uf.union(edge.from_vertex, edge.to_vertex):
            mst.append(edge)
        if len(mst) == vertices - 1:  # Stop if we have enough edges
            break
    return mst  # Return the resulting MST


if __name__ == "__main__":
    import sys

    input = sys.stdin.read
    data = input().splitlines()
    vertices = int(data[0])  # Read the number of vertices
    edges_count = int(data[1])  # Read the number of edges
    edge_list = []  # List to store all edges

    # Read edges from input
    for i in range(2, 2 + edges_count):
        from_vertex, to_vertex, weight = map(int, data[i].split())
        edge_list.append(Edge(from_vertex, to_vertex, weight))  # Add edge to the list

    # Compute the Minimum Spanning Tree using Kruskal's algorithm
    mst = kruskal(edge_list, vertices)
    print("Minimum Spanning Tree (MST):")
    for edge in mst:
        print(edge)

# <END-OF-CODE>
