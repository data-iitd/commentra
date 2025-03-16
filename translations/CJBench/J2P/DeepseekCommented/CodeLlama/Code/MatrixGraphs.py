
import sys


class AdjacencyMatrixGraph:
    def __init__(self, number_of_vertices):
        self.number_of_vertices = number_of_vertices
        self.number_of_edges = 0
        self.adjacency_matrix = [[0] * number_of_vertices for _ in range(number_of_vertices)]

    def number_of_vertices(self):
        return self.number_of_vertices

    def number_of_edges(self):
        return self.number_of_edges

    def add_edge(self, from_vertex, to_vertex):
        if from_vertex >= 0 and from_vertex < self.number_of_vertices and to_vertex >= 0 and to_vertex < self.number_of_vertices:
            if self.adjacency_matrix[from_vertex][to_vertex] == 0:
                self.adjacency_matrix[from_vertex][to_vertex] = 1
                self.adjacency_matrix[to_vertex][from_vertex] = 1
                self.number_of_edges += 1
                return True
        return False

    def depth_first_order(self, start_vertex):
        if start_vertex < 0 or start_vertex >= self.number_of_vertices:
            return []
        visited = [False] * self.number_of_vertices
        order_list = []
        self.dfs(start_vertex, visited, order_list)
        return order_list

    def dfs(self, current_vertex, visited, order_list):
        if visited[current_vertex]:
            return
        visited[current_vertex] = True
        order_list.append(current_vertex)
        for i in range(self.number_of_vertices):
            if self.adjacency_matrix[current_vertex][i] == 1:
                self.dfs(i, visited, order_list)

    def breadth_first_order(self, start_vertex):
        if start_vertex < 0 or start_vertex >= self.number_of_vertices:
            return []
        visited = [False] * self.number_of_vertices
        order_list = []
        queue = []
        queue.append(start_vertex)
        while queue:
            current_vertex = queue.pop(0)
            if visited[current_vertex]:
                continue
            visited[current_vertex] = True
            order_list.append(current_vertex)
            for i in range(self.number_of_vertices):
                if self.adjacency_matrix[current_vertex][i] == 1:
                    queue.append(i)
        return order_list

    def __str__(self):
        sb = "    "
        for i in range(self.number_of_vertices):
            sb += str(i) + " "
        sb += "\n"
        for i in range(self.number_of_vertices):
            sb += str(i) + " : "
            for j in range(self.number_of_vertices):
                sb += str(self.adjacency_matrix[i][j]) + " "
            sb += "\n"
        return sb


def main():
    scanner = sys.stdin
    number_of_vertices = int(scanner.readline())
    number_of_edges = int(scanner.readline())
    graph = AdjacencyMatrixGraph(number_of_vertices)
    for _ in range(number_of_edges):
        from_vertex, to_vertex = map(int, scanner.readline().split())
        graph.add_edge(from_vertex, to_vertex)
    dfs_start_vertex = int(scanner.readline())
    bfs_start_vertex = int(scanner.readline())
    print("The graph matrix:")
    print(graph)
    print("Depth First Order:")
    print(graph.depth_first_order(dfs_start_vertex))
    print("Breadth First Order:")
    print(graph.breadth_first_order(bfs_start_vertex))


if __name__ == "__main__":
    main()

