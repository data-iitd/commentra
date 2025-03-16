import java.util.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.HashMap;
class AdjacencyList(Generic[E]):
    def __init__(self):
        self.adj = {}
    def addEdge(self, from, to):
        self.adj.setdefault(from, [])
        self.adj[from].append(to)
        self.adj.setdefault(to, [])
    def getAdjacents(self, v):
        return self.adj.get(v)
    def getVertices(self):
        return self.adj.keys()
class TopologicalSort(Generic[E]):
    def __init__(self, graph):
        self.graph = graph
    def calculateInDegree(self):
        self.inDegree = {}
        for vertex in self.graph.getVertices():
            self.inDegree[vertex] = 0
            for adjacent in self.graph.getAdjacents(vertex):
                self.inDegree[adjacent] = self.inDegree.get(adjacent, 0) + 1
    def topSortOrder(self):
        self.calculateInDegree()
        q = Queue()
        for entry in self.inDegree.items():
            if entry[1] == 0:
                q.put(entry[0])
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
    scanner = Scanner(System.in)
    vertices = scanner.nextInt()
    edges = scanner.nextInt()
    graph = AdjacencyList()
    for i in range(edges):
        from_ = scanner.next()
        to = scanner.next()
        graph.addEdge(from_, to)
    topSort = TopologicalSort(graph)
    try:
        sortedOrder = topSort.topSortOrder()
        print("Topological Order:")
        for s in sortedOrder:
            print(s, end=" ")
        print()
    except Exception as e:
        print(e.getMessage())
    scanner.close()
if __name__ == "__main__":
    main()
