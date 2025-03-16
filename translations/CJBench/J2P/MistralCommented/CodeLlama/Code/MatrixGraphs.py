
import sys

def main():
    # Read the number of vertices and edges from the input
    vertices, edges = map(int, sys.stdin.readline().split())

    # Create an instance of AdjacencyMatrixGraph with the given number of vertices
    graph = AdjacencyMatrixGraph(vertices)

    # Iterate through each edge and add it to the graph
    for _ in range(edges):
        from_, to = map(int, sys.stdin.readline().split())
        graph.add_edge(from_, to)

    # Read the starting vertex for Depth First Search (DFS) and Breadth First Search (BFS)
    dfs_start_vertex, bfs_start_vertex = map(int, sys.stdin.readline().split())

    # Print the graph matrix to the console
    print("The graph matrix:")
    print(graph)

    # Print the header for the Depth First Order output
    print("Depth First Order:")
    # Call the depthFirstOrder method and print the result to the console
    print(graph.depth_first_order(dfs_start_vertex))

    # Print the header for the Breadth First Order output
    print("Breadth First Order:")
    # Call the breadthFirstOrder method and print the result to the console
    print(graph.breadth_first_order(bfs_start_vertex))

class AdjacencyMatrixGraph:
    def __init__(self, given_number_of_vertices):
        self.vertex_count = given_number_of_vertices
        self.edge_count = 0
        self.adj_matrix = [[0] * given_number_of_vertices for _ in range(given_number_of_vertices)]

    def number_of_vertices(self):
        return self.vertex_count

    def number_of_edges(self):
        return self.edge_count

    def add_edge(self, from_, to):
        if from_ >= 0 and from_ < self.vertex_count and to >= 0 and to < self.vertex_count:
            if self.adj_matrix[from_][to] == 0:
                self.adj_matrix[from_][to] = 1
                self.adj_matrix[to][from_] = 1
                self.edge_count += 1
                return True
        return False

    def depth_first_order(self, start_vertex):
        if start_vertex < 0 or start_vertex >= self.vertex_count:
            return []

        visited = [False] * self.vertex_count
        order_list = []

        self.dfs(start_vertex, visited, order_list)

        return order_list

    def dfs(self, current_vertex, visited, order_list):
        if visited[current_vertex]:
            return

        visited[current_vertex] = True
        order_list.append(current_vertex)

        for i in range(self.vertex_count):
            if self.adj_matrix[current_vertex][i] == 1:
                self.dfs(i, visited, order_list)

    def breadth_first_order(self, start_vertex):
        if start_vertex < 0 or start_vertex >= self.vertex_count:
            return []

        visited = [False] * self.vertex_count
        order_list = []
        queue = []

        queue.append(start_vertex)

        while queue:
            current_vertex = queue.pop(0)
            if visited[current_vertex]:
                continue

            visited[current_vertex] = True
            order_list.append(current_vertex)

            for i in range(self.vertex_count):
                if self.adj_matrix[current_vertex][i] == 1:
                    queue.append(i)

        return order_list

    def __str__(self):
        sb = "    "

        for i in range(self.vertex_count):
            sb += str(i) + " "

        sb += "\n"

        for i in range(self.vertex_count):
            sb += str(i) + " : "
            for j in range(self.vertex_count):
                sb += str(self.adj_matrix[i][j]) + " "
            sb += "\n"

        return sb

if __name__ == "__main__":
    main()

