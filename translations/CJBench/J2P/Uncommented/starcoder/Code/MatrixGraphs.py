
import sys
import queue

class AdjacencyMatrixGraph:
    def __init__(self, numberOfVertices):
        self.vertexCount = numberOfVertices
        self.edgeCount = 0
        self.adjMatrix = [[0 for i in range(numberOfVertices)] for j in range(numberOfVertices)]

    def addEdge(self, fromVertex, toVertex):
        if fromVertex >= 0 and fromVertex < self.vertexCount and toVertex >= 0 and toVertex < self.vertexCount:
            if self.adjMatrix[fromVertex][toVertex] == 0:
                self.adjMatrix[fromVertex][toVertex] = 1
                self.adjMatrix[toVertex][fromVertex] = 1
                self.edgeCount += 1
                return True
        return False

    def numberOfVertices(self):
        return self.vertexCount

    def numberOfEdges(self):
        return self.edgeCount

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
        queue = queue.Queue()
        queue.put(startVertex)
        while not queue.empty():
            currentVertex = queue.get()
            if visited[currentVertex]:
                continue
            visited[currentVertex] = True
            orderList.append(currentVertex)
            for i in range(self.vertexCount):
                if self.adjMatrix[currentVertex][i] == 1:
                    queue.put(i)
        return orderList

    def __str__(self):
        sb = []
        sb.append("    ")
        for i in range(self.vertexCount):
            sb.append(str(i)).append(" ")
        sb.append("\n")
        for i in range(self.vertexCount):
            sb.append(str(i)).append(" : ")
            for j in range(self.vertexCount):
                sb.append(str(self.adjMatrix[i][j])).append(" ")
            sb.append("\n")
        return "".join(sb)

def main():
    graph = AdjacencyMatrixGraph(int(sys.stdin.readline().strip()))
    for i in range(int(sys.stdin.readline().strip())):
        fromVertex, toVertex = [int(x) for x in sys.stdin.readline().strip().split()]
        graph.addEdge(fromVertex, toVertex)
    dfsStartVertex, bfsStartVertex = [int(x) for x in sys.stdin.readline().strip().split()]
    print("The graph matrix:")
    print(graph)
    print("Depth First Order:")
    print(graph.depthFirstOrder(dfsStartVertex))
    print("Breadth First Order:")
    print(graph.breadthFirstOrder(bfsStartVertex))

if __name__ == "__main__":
    main()

# 