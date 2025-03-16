
class AdjacencyList:
    def __init__(self):
        self.adj = {}
    def addEdge(self, from, to):
        if from not in self.adj:
            self.adj[from] = []
        self.adj[from].append(to)
        if to not in self.adj:
            self.adj[to] = []
    def getAdjacents(self, v):
        return self.adj[v]
    def getVertices(self):
        return self.adj.keys()
class TopologicalSort:
    def __init__(self, graph):
        self.graph = graph
    def calculateInDegree(self):
        self.inDegree = {}
        for v in self.graph.getVertices():
            self.inDegree[v] = 0
            for adjacent in self.graph.getAdjacents(v):
                self.inDegree[adjacent] = self.inDegree.get(adjacent, 0) + 1
    def topSortOrder(self):
        self.calculateInDegree()
        q = []
        for entry in self.inDegree.items():
            if entry[1] == 0:
                q.append(entry[0])
        answer = []
        processedVertices = 0
        while len(q) > 0:
            current = q.pop(0)
            answer.append(current)
            processedVertices += 1
            for adjacent in self.graph.getAdjacents(current):
                self.inDegree[adjacent] -= 1
                if self.inDegree[adjacent] == 0:
                    q.append(adjacent)
        if processedVertices!= len(self.graph.getVertices()):
            raise Exception("Graph contains a cycle, topological sort not possible")
        return answer
if __name__ == "__main__":
    import sys
    vertices, edges = map(int, input().split())
    graph = AdjacencyList()
    for i in range(edges):
        from_, to = input().split()
        graph.addEdge(from_, to)
    topSort = TopologicalSort(graph)
    try:
        sortedOrder = topSort.topSortOrder()
        print("Topological Order:")
        for s in sortedOrder:
            print(s, end=" ")
        print()
    except Exception as e:
        print(e)
    sys.exit(0)
