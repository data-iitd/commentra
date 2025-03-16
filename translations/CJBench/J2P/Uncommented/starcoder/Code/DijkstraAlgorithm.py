
import sys
import heapq

class Main:
    def __init__(self, vertexCount):
        self.vertexCount = vertexCount

    def run(self, graph, source):
        if source < 0 or source >= self.vertexCount:
            raise Exception("Incorrect source vertex")
        distances = [sys.maxsize] * self.vertexCount
        distances[source] = 0
        processed = [False] * self.vertexCount
        for count in range(self.vertexCount - 1):
            u = self.getMinDistanceVertex(distances, processed)
            processed[u] = True
            for v in range(self.vertexCount):
                if not processed[v] and graph[u][v]!= 0 and distances[u]!= sys.maxsize and distances[u] + graph[u][v] < distances[v]:
                    distances[v] = distances[u] + graph[u][v]
        return distances

    def getMinDistanceVertex(self, distances, processed):
        min = sys.maxsize
        minIndex = -1
        for v in range(self.vertexCount):
            if not processed[v] and distances[v] <= min:
                min = distances[v]
                minIndex = v
        return minIndex

if __name__ == "__main__":
    vertexCount = int(input())
    graph = [[0] * vertexCount for i in range(vertexCount)]
    for i in range(vertexCount):
        for j in range(vertexCount):
            graph[i][j] = int(input())
    source = int(input())
    dijkstra = Main(vertexCount)
    distances = dijkstra.run(graph, source)
    print("Shortest distances from source vertex " + str(source) + ":")
    for i in range(vertexCount):
        print("Vertex " + str(i) + " : " + str(distances[i]))

