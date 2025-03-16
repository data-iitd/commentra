class Edge:
    def __init__(self, from_vertex, to_vertex, weight):
        self.from_vertex = from_vertex
        self.to_vertex = to_vertex
        self.weight = weight

    def __str__(self):
        return f"{self.from_vertex} - {self.to_vertex} : {self.weight}"


class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x == root_y:
            return False
        if self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        elif self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1
        return True


def kruskal(edges, vertices):
    edges.sort(key=lambda edge: edge.weight)
    uf = UnionFind(vertices)
    mst = []

    for edge in edges:
        if uf.union(edge.from_vertex, edge.to_vertex):
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
        from_vertex = int(data[index])
        to_vertex = int(data[index + 1])
        weight = int(data[index + 2])
        edge_list.append(Edge(from_vertex, to_vertex, weight))
        index += 3

    mst = kruskal(edge_list, vertices)
    print("Minimum Spanning Tree (MST):")
    for edge in mst:
        print(edge)


if __name__ == "__main__":
    main()
