
import queue

class AdjacencyList:
    def __init__(self):
        self.adj = {}

    def addEdge(self, from_v, to_v):
        if from_v not in self.adj:
            self.adj[from_v] = []
        self.adj[from_v].append(to_v)

        if to_v not in self.adj:
            self.adj[to_v] = []

    def getAdjacents(self, v):
        return self.adj.get(v, [])

    def getVertices(self):
        return self.adj.keys()

class TopologicalSort:
    def __init__(self, graph):
        self.graph = graph
        self.inDegree = {}

    def calculateInDegree(self):
        self.inDegree = {}
        for v in self.graph.getVertices():
            self.inDegree[v] = 0
            for adjacent in self.graph.getAdjacents(v):
                self.inDegree[adjacent] = self.inDegree.get(adjacent, 0) + 1

    def topSortOrder(self):
        self.calculateInDegree()
        q = queue.Queue()

        for v in self.inDegree:
            if self.inDegree[v] == 0:
                q.put(v)

        answer = []
        processedVertices = 0

        while not q.empty():
            current = q.get()
            answer.append(current)
            processedVertices += 1

            for adjacent in self.graph.getAdjacents(current):
                self.inDegree[adjacent] -= 1
                if self.inDegree[adjacent] == 0:
                    q.put(adjacent)

        if processedVertices!= len(self.graph.getVertices()):
            raise Exception("Graph contains a cycle, topological sort not possible")

        return answer

def main():
    vertices, edges = map(int, input().split())

    graph = AdjacencyList()
    for _ in range(edges):
        from_v, to_v = input().split()
        graph.addEdge(from_v, to_v)

    topSort = TopologicalSort(graph)
    try:
        sortedOrder = topSort.topSortOrder()
        print("Topological Order:")
        for s in sortedOrder:
            print(s, end=" ")
        print()
    except Exception as e:
        print(e)

if __name__ == "__main__":
    main()

