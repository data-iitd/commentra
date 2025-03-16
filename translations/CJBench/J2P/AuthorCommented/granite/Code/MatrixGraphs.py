

import sys

class AdjacencyMatrixGraph:
    """
    Implementation of a graph in a matrix form Also known as an adjacency matrix
    representation [Adjacency matrix -
    Wikipedia](https://en.wikipedia.org/wiki/Adjacency_matrix)
    """

    def __init__(self, vertices, edges):
        """
        Constructor
        """
        self.vertexCount = vertices
        self.edgeCount = edges
        self.adjMatrix = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def addEdge(self, from_vertex, to_vertex):
        """
        This method adds an edge to the graph between two specified vertices
        """
        if from_vertex >= 0 and from_vertex < self.vertexCount and to_vertex >= 0 and to_vertex < self.vertexCount:
            if self.adjMatrix[from_vertex][to_vertex] == 0:
                self.adjMatrix[from_vertex][to_vertex] = 1
                self.adjMatrix[to_vertex][from_vertex] = 1
                self.edgeCount += 1
                return True
        return False

    def depthFirstOrder(self, start_vertex):
        """
        This method returns a list of the vertices in a depth first order
        beginning with the specified vertex
        """
        if start_vertex < 0 or start_vertex >= self.vertexCount:
            return []

        visited = [False for _ in range(self.vertexCount)]
        order_list = []
        self.dfs(start_vertex, visited, order_list)
        return order_list

    def dfs(self, current_vertex, visited, order_list):
        """
        Helper method for public depthFirstOrder(int) that will perform a depth
        first traversal recursively on the graph
        """
        if visited[current_vertex]:
            return

        # Visit the currentVertex by marking it as visited and adding it
        # to the orderList
        visited[current_vertex] = True
        order_list.append(current_vertex)

        for i in range(self.vertexCount):
            if self.adjMatrix[current_vertex][i] == 1:
                self.dfs(i, visited, order_list)

    def breadthFirstOrder(self, start_vertex):
        """
        This method returns a list of the vertices in a breadth first order
        beginning with the specified vertex
        """
        # If the specified startVertex is invalid, return an empty list
        if start_vertex < 0 or start_vertex >= self.vertexCount:
            return []

        # Create an array to keep track of the visited vertices
        visited = [False for _ in range(self.vertexCount)]
        # Create a list to keep track of the ordered vertices
        order_list = []
        # Create a queue for our BFS algorithm and add the startVertex
        # to the queue
        queue = []
        queue.append(start_vertex)

        # Continue until the queue is empty
        while queue:
            # Remove the first vertex in the queue
            current_vertex = queue.pop(0)
            # If we've visited this vertex, skip it
            if visited[current_vertex]:
                continue

            # We now visit this vertex by adding it to the orderList and
            # marking it as visited
            visited[current_vertex] = True
            order_list.append(current_vertex)

            for i in range(self.vertexCount):
                if self.adjMatrix[current_vertex][i] == 1:
                    queue.append(i)

        return order_list

    def __str__(self):
        """
        this gives a list of vertices in the graph and their adjacencies
        """
        sb = "    "
        for i in range(self.vertexCount):
            sb += str(i) + " "
        sb += "\n"

        for i in range(self.vertexCount):
            sb += str(i) + " : "
            for j in range(self.vertexCount):
                sb += str(self.adjMatrix[i][j]) + " "
            sb += "\n"
        return sb

if __name__ == "__main__":
    # Read number of vertices and edges
    vertices, edges = map(int, sys.stdin.readline().split())

    graph = AdjacencyMatrixGraph(vertices, edges)

    # Read edges
    for _ in range(edges):
        from_vertex, to_vertex = map(int, sys.stdin.readline().split())
        graph.addEdge(from_vertex, to_vertex)

    # Read starting vertices for DFS and BFS
    dfs_start_vertex, bfs_start_vertex = map(int, sys.stdin.readline().split())

    # Output the results
    print("The graph matrix:")
    print(graph)
    print("Depth First Order:")
    print(graph.depthFirstOrder(dfs_start_vertex))
    print("Breadth First Order:")
    print(graph.breadthFirstOrder(bfs_start_vertex))

