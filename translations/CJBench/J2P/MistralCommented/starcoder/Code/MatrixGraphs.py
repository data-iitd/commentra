
import sys

class AdjacencyMatrixGraph:
    def __init__(self, numberOfVertices):
        self.vertexCount = numberOfVertices
        self.edgeCount = 0
        self.adjMatrix = [[0 for i in range(numberOfVertices)] for j in range(numberOfVertices)]

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
        while len(queue) > 0:
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

def main():
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    numberOfVertices = data[0]
    numberOfEdges = data[1]
    graph = AdjacencyMatrixGraph(numberOfVertices)
    for i in range(2, 2 * numberOfEdges + 2, 2):
        graph.addEdge(data[i], data[i + 1])
    dfsStartVertex = data[2 * numberOfEdges + 2]
    bfsStartVertex = data[2 * numberOfEdges + 3]
    print("The graph matrix:")
    print(graph)
    print("Depth First Order:")
    print(graph.depthFirstOrder(dfsStartVertex))
    print("Breadth First Order:")
    print(graph.breadthFirstOrder(bfsStartVertex))

if __name__ == '__main__':
    main()

