class Edge:
    def __init__(self, from_node, to_node, weight):
        self.from_node = from_node
        self.to_node = to_node
        self.weight = weight

    def __str__(self):
        return f"{self.from_node} - {self.to_node} : {self.weight}"


class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size

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


def kruskal(edges, vertices):
    edges.sort(key=lambda edge: edge.weight)

    uf = UnionFind(vertices)
    mst = []

    for edge in edges:
        if uf.union(edge.from_node, edge.to_node):
            mst.append(edge)

        if len(mst) == vertices - 1:
            break

    return mst


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    vertices = int(data[index])
    edges = int(data[index + 1])
    index += 2

    edge_list = []
    for i in range(edges):
        from_node = int(data[index])
        to_node = int(data[index + 1])
        weight = int(data[index + 2])
        edge_list.append(Edge(from_node, to_node, weight))
        index += 3

    mst = kruskal(edge_list, vertices)

    print("Minimum Spanning Tree (MST):")
    for edge in mst:
        print(edge)


if __name__ == "__main__":
    main()
