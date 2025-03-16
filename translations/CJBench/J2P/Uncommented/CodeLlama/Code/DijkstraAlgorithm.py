
import sys
import math

def getMinDistanceVertex(distances, processed):
    min = sys.maxsize
    minIndex = -1
    for v in range(len(distances)):
        if not processed[v] and distances[v] <= min:
            min = distances[v]
            minIndex = v
    return minIndex

def run(graph, source):
    vertexCount = len(graph)
    if source < 0 or source >= vertexCount:
        raise ValueError("Incorrect source vertex")
    distances = [sys.maxsize] * vertexCount
    processed = [False] * vertexCount
    distances[source] = 0
    for count in range(vertexCount - 1):
        u = getMinDistanceVertex(distances, processed)
        processed[u] = True
        for v in range(vertexCount):
            if not processed[v] and graph[u][v] != 0 and distances[u] != sys.maxsize and distances[u] + graph[u][v] < distances[v]:
                distances[v] = distances[u] + graph[u][v]
    return distances

def main():
    vertexCount = int(input())
    graph = [[0] * vertexCount for _ in range(vertexCount)]
    for i in range(vertexCount):
        for j in range(vertexCount):
            graph[i][j] = int(input())
    source = int(input())
    distances = run(graph, source)
    print("Shortest distances from source vertex " + str(source) + ":")
    for i in range(len(distances)):
        print("Vertex " + str(i) + " : " + str(distances[i]))

if __name__ == "__main__":
    main()

