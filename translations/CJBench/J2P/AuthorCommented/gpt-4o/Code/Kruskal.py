class Edge:
    """Represents an edge in the graph with a source, destination, and weight."""
    def __init__(self, from_node, to_node, weight):
        self.from_node = from_node
        self.to_node = to_node
        self.weight = weight

    def __str__(self):
        return f"{self.from_node} - {self.to_node} : {self.weight}"


class UnionFind:
    """Union-Find structure to track connected components."""
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x == root_y:
            return False

        # Union by rank
        if self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        elif self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1

        return True


def kruskal(edges, vertices):
    """Main's algorithm to find the Minimum Spanning Tree (MST)."""
    edges.sort(key=lambda edge: edge.weight)  # Sort edges by weight
    uf = UnionFind(vertices)
    mst = []

    for edge in edges:
        if uf.union(edge.from_node, edge.to_node):  # Add edge if it connects two separate components
            mst.append(edge)
        if len(mst) == vertices - 1:  # Stop when MST is complete
            break

    return mst


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    vertices = int(data[0])
    edges_count = int(data[1])

    edge_list = []
    for i in range(2, 2 + edges_count):
        from_node, to_node, weight = map(int, data[i].split())
        edge_list.append(Edge(from_node, to_node, weight))

    mst = kruskal(edge_list, vertices)

    print("Minimum Spanning Tree (MST):")
    for edge in mst:
        print(edge)


if __name__ == "__main__":
    main()

# <END-OF-CODE>
