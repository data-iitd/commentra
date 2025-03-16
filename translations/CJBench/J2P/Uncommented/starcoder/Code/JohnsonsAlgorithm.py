
import sys
import heapq

class Main:
    INF = sys.maxsize
    def __init__(self):
        self.vertices = 0
        self.graph = []
        self.shortestPaths = []
        self.modifiedWeights = []

    def main(self):
        self.vertices = int(input())
        for i in range(self.vertices):
            self.graph.append([int(x) for x in input().split()])
        self.modifiedWeights = self.bellmanFord()
        self.graph = self.reweightGraph(self.graph, self.modifiedWeights)
        self.shortestPaths = self.dijkstra()
        self.printDistances()

    def bellmanFord(self):
        dist = [self.INF] * (self.vertices + 1)
        dist[self.vertices] = 0
        edges = []
        for i in range(self.vertices):
            for j in range(self.vertices):
                if self.graph[i][j]!= self.INF:
                    edges.append((i, j, self.graph[i][j]))
        for i in range(self.vertices):
            edges.append((self.vertices, i, 0))
        for i in range(self.vertices):
            for u, v, w in edges:
                if dist[u]!= self.INF and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
        for u, v, w in edges:
            if dist[u]!= self.INF and dist[u] + w < dist[v]:
                raise Exception("Graph contains a negative weight cycle.")
        return dist[:self.vertices]

    def reweightGraph(self, graph, weights):
        reweightedGraph = []
        for i in range(self.vertices):
            reweightedGraph.append([self.INF] * self.vertices)
        for i in range(self.vertices):
            for j in range(self.vertices):
                if graph[i][j]!= self.INF:
                    reweightedGraph[i][j] = graph[i][j] + weights[i] - weights[j]
        return reweightedGraph

    def dijkstra(self):
        dist = [self.INF] * self.vertices
        visited = [False] * self.vertices
        dist[0] = 0
        for count in range(self.vertices - 1):
            u = self.minDistance(dist, visited)
            visited[u] = True
            for v in range(self.vertices):
                if not visited[v] and self.graph[u][v]!= self.INF and dist[u]!= self.INF and dist[u] + self.graph[u][v] < dist[v]:
                    dist[v] = dist[u] + self.graph[u][v]
        for i in range(self.vertices):
            if dist[i]!= self.INF:
                dist[i] = dist[i] - self.modifiedWeights[0] + self.modifiedWeights[i]
        return dist

    def minDistance(self, dist, visited):
        min = self.INF
        minIndex = -1
        for v in range(self.vertices):
            if not visited[v] and dist[v] <= min:
                min = dist[v]
                minIndex = v
        return minIndex

    def printDistances(self):
        print("All-pairs shortest paths:")
        for row in self.shortestPaths:
            for dist in row:
                print((dist == self.INF and "INF" or dist), end=" ")
            print()

if __name__ == "__main__":
    main = Main()
    main.main()

