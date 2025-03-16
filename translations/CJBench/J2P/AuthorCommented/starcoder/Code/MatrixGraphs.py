
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

class Main:
    def __init__(self):
        pass

    def main(self):
        scanner = Scanner(System.in)

        # Read number of vertices and edges
        vertices = scanner.nextInt()
        edges = scanner.nextInt()

        graph = AdjacencyMatrixGraph(vertices)

        # Read edges
        for i in range(edges):
            from_ = scanner.nextInt()
            to = scanner.nextInt()
            graph.addEdge(from_, to)

        # Read starting vertices for DFS and BFS
        dfs_start_vertex = scanner.nextInt()
        bfs_start_vertex = scanner.nextInt()

        # Output the results
        print("The graph matrix:")
        print(graph)
        print("Depth First Order:")
        print(graph.depthFirstOrder(dfs_start_vertex))
        print("Breadth First Order:")
        print(graph.breadthFirstOrder(bfs_start_vertex))


class AdjacencyMatrixGraph:
    def __init__(self, givenNumberOfVertices):
        self.vertexCount = givenNumberOfVertices
        self.edgeCount = 0
        self.adjMatrix = [[0 for i in range(givenNumberOfVertices)] for j in range(givenNumberOfVertices)]

    def numberOfVertices(self):
        return self.vertexCount

    def numberOfEdges(self):
        return self.edgeCount

    def addEdge(self, from_, to):
        if from_ >= 0 and from_ < self.vertexCount and to >= 0 and to < self.vertexCount:
            if self.adjMatrix[from_][to] == 0:
                self.adjMatrix[from_][to] = 1
                self.adjMatrix[to][from_] = 1
                self.edgeCount += 1
                return True
        return False

    def depthFirstOrder(self, startVertex):
        if startVertex < 0 or startVertex >= self.vertexCount:
            return []

        visited = [False for i in range(self.vertexCount)]
        orderList = []
        self.dfs(startVertex, visited, orderList)
        return orderList

    def dfs(self, currentVertex, visited, orderList):
        if visited[currentVertex]: return
        visited[currentVertex] = True

        # Visit the currentVertex by marking it as visited and adding it
        # to the orderList
        orderList.append(currentVertex)

        for i in range(self.vertexCount):
            if self.adjMatrix[currentVertex][i] == 1:
                self.dfs(i, visited, orderList)

    def breadthFirstOrder(self, startVertex):
        # If the specified startVertex is invalid, return an empty list
        if startVertex < 0 or startVertex >= self.vertexCount:
            return []

        # Create an array to keep track of the visited vertices
        visited = [False for i in range(self.vertexCount)]
        # Create a list to keep track of the ordered vertices
        orderList = []
        # Create a queue for our BFS algorithm and add the startVertex
        # to the queue
        queue = LinkedList()
        queue.add(startVertex)

        # Continue until the queue is empty
        while not queue.isEmpty():
            # Remove the first vertex in the queue
            currentVertex = queue.poll()
            # If we've visited this vertex, skip it
            if visited[currentVertex]: continue

            # We now visit this vertex by adding it to the orderList and
            # marking it as visited
            visited[currentVertex] = True
            orderList.append(currentVertex)

            for i in range(self.vertexCount):
                if self.adjMatrix[currentVertex][i] == 1:
                    queue.add(i)

        return orderList

    def __str__(self):
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


# 