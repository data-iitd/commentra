class AdjacencyMatrixGraph:
    EDGE_EXIST = 1
    EDGE_NONE = 0

    def __init__(self, given_number_of_vertices):
        self.vertex_count = given_number_of_vertices
        self.edge_count = 0
        self.adj_matrix = [[self.EDGE_NONE for _ in range(given_number_of_vertices)] for _ in range(given_number_of_vertices)]

    def number_of_vertices(self):
        return self.vertex_count

    def number_of_edges(self):
        return self.edge_count

    def add_edge(self, from_vertex, to_vertex):
        if 0 <= from_vertex < self.vertex_count and 0 <= to_vertex < self.vertex_count:
            if self.adj_matrix[from_vertex][to_vertex] == self.EDGE_NONE:
                self.adj_matrix[from_vertex][to_vertex] = self.EDGE_EXIST
                self.adj_matrix[to_vertex][from_vertex] = self.EDGE_EXIST
                self.edge_count += 1
                return True
        return False

    def depth_first_order(self, start_vertex):
        if start_vertex < 0 or start_vertex >= self.vertex_count:
            return []

        visited = [False] * self.vertex_count
        order_list = []
        self._dfs(start_vertex, visited, order_list)
        return order_list

    def _dfs(self, current_vertex, visited, order_list):
        if visited[current_vertex]:
            return

        visited[current_vertex] = True
        order_list.append(current_vertex)

        for i in range(self.vertex_count):
            if self.adj_matrix[current_vertex][i] == self.EDGE_EXIST:
                self._dfs(i, visited, order_list)

    def breadth_first_order(self, start_vertex):
        if start_vertex < 0 or start_vertex >= self.vertex_count:
            return []

        visited = [False] * self.vertex_count
        order_list = []
        queue = [start_vertex]

        while queue:
            current_vertex = queue.pop(0)
            if visited[current_vertex]:
                continue

            visited[current_vertex] = True
            order_list.append(current_vertex)

            for i in range(self.vertex_count):
                if self.adj_matrix[current_vertex][i] == self.EDGE_EXIST and not visited[i]:
                    queue.append(i)

        return order_list

    def __str__(self):
        sb = "    " + " ".join(str(i) for i in range(self.vertex_count)) + "\n"
        for i in range(self.vertex_count):
            sb += f"{i} : " + " ".join(str(self.adj_matrix[i][j]) for j in range(self.vertex_count)) + "\n"
        return sb


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    vertices = int(data[0])
    edges = int(data[1])
    
    graph = AdjacencyMatrixGraph(vertices)

    for i in range(2, 2 + edges):
        from_vertex, to_vertex = map(int, data[i].split())
        graph.add_edge(from_vertex, to_vertex)

    dfs_start_vertex = int(data[2 + edges])
    bfs_start_vertex = int(data[3 + edges])

    print("The graph matrix:")
    print(graph)

    print("Depth First Order:")
    print(graph.depth_first_order(dfs_start_vertex))

    print("Breadth First Order:")
    print(graph.breadth_first_order(bfs_start_vertex))


if __name__ == "__main__":
    main()

# <END-OF-CODE>
