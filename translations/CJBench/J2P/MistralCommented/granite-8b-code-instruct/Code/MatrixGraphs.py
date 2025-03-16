

import sys

class AdjacencyMatrixGraph:
    def __init__(self, vertices):
        self.vertexCount = vertices
        self.edgeCount = 0
        self.adjMatrix = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def numberOfVertices(self):
        return self.vertexCount

    def numberOfEdges(self):
        return self.edgeCount

    def addEdge(self, fromVertex, toVertex):
        if fromVertex >= 0 and fromVertex < self.vertexCount and toVertex >= 0 and toVertex < self.vertexCount:
            if self.adjMatrix[fromVertex][toVertex] == 0:
                self.adjMatrix[fromVertex][toVertex] = 1
                self.adjMatrix[toVertex][fromVertex] = 1
                self.edgeCount += 1
                return True
        return False

    def depthFirstOrder(self, startVertex):
        if startVertex < 0 or startVertex >= self.vertexCount:
            return []

        visited = [False] * self.vertexCount
        orderList = []

        self.dfs(startVertex, visited, orderList)

        return orderList

    def dfs(self, currentVertex, visited, orderList):
        if visited[currentVertex]:
            return

        visited[currentVertex] = True
        orderList.append(currentVertex)

        for i in range(self.vertexCount):
            if self.adjMatrix[currentVertex][i] == 1:
                self.dfs(i, visited, orderList)

    def breadthFirstOrder(self, startVertex):
        if startVertex < 0 or startVertex >= self.vertexCount:
            return []

        visited = [False] * self.vertexCount
        orderList = []
        queue = []

        queue.append(startVertex)

        while queue:
            currentVertex = queue.pop(0)
            if visited[currentVertex]:
                continue

            visited[currentVertex] = True
            orderList.append(currentVertex)

            for i in range(self.vertexCount):
                if self.adjMatrix[currentVertex][i] == 1:
                    queue.append(i)

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

if __name__ == "__main__":
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

    vertices, edges = map(int, input().split())
    graph = AdjacencyMatrixGraph(vertices)

    for _ in range(edges):
        fromVertex, toVertex = map(int, input().split())
        graph.addEdge(fromVertex, toVertex)

    dfsStartVertex = int(input())
    bfsStartVertex = int(input())

    print("The graph matrix:")
    print(graph)

    print("Depth First Order:")
    print(graph.depthFirstOrder(dfsStartVertex))

    print("Breadth First Order:")
    print(graph.breadthFirstOrder(bfsStartVertex))

