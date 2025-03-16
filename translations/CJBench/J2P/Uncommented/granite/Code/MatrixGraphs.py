

import sys
class AdjacencyMatrixGraph:
    def __init__(self, givenNumberOfVertices):
        self.vertexCount = givenNumberOfVertices
        self.edgeCount = 0
        self.adjMatrix = [[0 for _ in range(givenNumberOfVertices)] for _ in range(givenNumberOfVertices)]
    def numberOfVertices(self):
        return self.vertexCount
    def numberOfEdges(self):
        return self.edgeCount
    def addEdge(self, from, to):
        if from >= 0 and from < self.vertexCount and to >= 0 and to < self.vertexCount:
            if self.adjMatrix[from][to] == 0:
                self.adjMatrix[from][to] = 1
                self.adjMatrix[to][from] = 1
                self.edgeCount += 1
                return True
        return False
    def depthFirstOrder(self, startVertex):
        if startVertex < 0 or startVertex >= self.vertexCount:
            return []
        visited = [False for _ in range(self.vertexCount)]
        orderList = []
        self.dfs(startVertex, visited, orderList)
        return orderList
    def dfs(self, currentVertex, visited, orderList):
        if visited[currentVertex]: return
        visited[currentVertex] = True
        orderList.append(currentVertex)
        for i in range(self.vertexCount):
            if self.adjMatrix[currentVertex][i] == 1:
                self.dfs(i, visited, orderList)
    def breadthFirstOrder(self, startVertex):
        if startVertex < 0 or startVertex >= self.vertexCount:
            return []
        visited = [False for _ in range(self.vertexCount)]
        orderList = []
        queue = []
        queue.append(startVertex)
        while queue:
            currentVertex = queue.pop(0)
            if visited[currentVertex]: continue
            visited[currentVertex] = True
            orderList.append(currentVertex)
            for i in range(self.vertexCount):
                if self.adjMatrix[currentVertex][i] == 1:
                    queue.append(i)
        return orderList
    def __str__(self):
        sb = ["    " + str(i) + " " for i in range(self.vertexCount)]
        sb.append("\n")
        for i in range(self.vertexCount):
            sb.append(str(i) + " : ")
            for j in range(self.vertexCount):
                sb.append(str(self.adjMatrix[i][j]) + " ")
            sb.append("\n")
        return "".join(sb)
if __name__ == "__main__":
    scanner = sys.stdin
    vertices = int(scanner.readline())
    edges = int(scanner.readline())
    graph = AdjacencyMatrixGraph(vertices)
    for i in range(edges):
        from_, to_ = map(int, scanner.readline().split())
        graph.addEdge(from_, to_)
    dfsStartVertex = int(scanner.readline())
    bfsStartVertex = int(scanner.readline())
    print("The graph matrix:")
    print(graph)
    print("Depth First Order:")
    print(graph.depthFirstOrder(dfsStartVertex))
    print("Breadth First Order:")
    print(graph.breadthFirstOrder(bfsStartVertex))
