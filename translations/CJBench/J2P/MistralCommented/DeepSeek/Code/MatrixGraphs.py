class AdjacencyMatrixGraph:
    EDGE_EXIST = 1
    EDGE_NONE = 0

    def __init__(self, givenNumberOfVertices):
        self.vertexCount = givenNumberOfVertices
        self.edgeCount = 0
        self.adjMatrix = [[AdjacencyMatrixGraph.EDGE_NONE] * givenNumberOfVertices for _ in range(givenNumberOfVertices)]

    def numberOfVertices(self):
        return self.vertexCount

    def numberOfEdges(self):
        return self.edgeCount

    def addEdge(self, from_, to_):
        if 0 <= from_ < self.vertexCount and 0 <= to_ < self.vertexCount:
            if self.adjMatrix[from_][to_] == AdjacencyMatrixGraph.EDGE_NONE:
                self.adjMatrix[from_][to_] = AdjacencyMatrixGraph.EDGE_EXIST
                self.adjMatrix[to_][from_] = AdjacencyMatrixGraph.EDGE_EXIST
                self.edgeCount += 1
                return True
        return False

    def depthFirstOrder(self, startVertex):
        if startVertex < 0 or startVertex >= self.vertexCount:
            return []

        visited = [False] * self.vertexCount
        orderList = []

        def dfs(currentVertex):
            if visited[currentVertex]:
                return
            visited[currentVertex] = True
            orderList.append(currentVertex)
            for i in range(self.vertexCount):
                if self.adjMatrix[currentVertex][i] == AdjacencyMatrixGraph.EDGE_EXIST:
                    dfs(i)

        dfs(startVertex)
        return orderList

    def breadthFirstOrder(self, startVertex):
        if startVertex < 0 or startVertex >= self.vertexCount:
            return []

        visited = [False] * self.vertexCount
        orderList = []
        queue = [startVertex]

        while queue:
            currentVertex = queue.pop(0)
            if not visited[currentVertex]:
                visited[currentVertex] = True
                orderList.append(currentVertex)
                for i in range(self.vertexCount):
                    if self.adjMatrix[currentVertex][i] == AdjacencyMatrixGraph.EDGE_EXIST:
                        queue.append(i)

        return orderList

    def __str__(self):
        sb = ["    "]
        for i in range(self.vertexCount):
            sb.append(str(i) + " ")
        sb.append("\n")

        for i in range(self.vertexCount):
            sb.append(str(i) + " : ")
            for j in range(self.vertexCount):
                sb.append(str(self.adjMatrix[i][j]) + " ")
            sb.append("\n")

        return "".join(sb)


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    vertices = int(data[index])
    index += 1
    edges = int(data[index])
    index += 1

    graph = AdjacencyMatrixGraph(vertices)

    for i in range(edges):
        from_ = int(data[index])
        to_ = int(data[index + 1])
        index += 2
        graph.addEdge(from_, to_)

    dfsStartVertex = int(data[index])
    index += 1
    bfsStartVertex = int(data[index])
    index += 1

    print("The graph matrix:")
    print(graph)

    print("Depth First Order:")
    print(graph.depthFirstOrder(dfsStartVertex))

    print("Breadth First Order:")
    print(graph.breadthFirstOrder(bfsStartVertex))
