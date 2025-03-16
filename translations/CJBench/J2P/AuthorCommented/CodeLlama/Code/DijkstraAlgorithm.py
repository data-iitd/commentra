
import sys

def dijkstra(graph, source):
    vertex_count = len(graph)
    distances = [sys.maxsize] * vertex_count
    processed = [False] * vertex_count

    distances[source] = 0

    for count in range(vertex_count - 1):
        u = get_min_distance_vertex(distances, processed)
        processed[u] = True

        for v in range(vertex_count):
            if not processed[v] and graph[u][v] != 0 and distances[u] != sys.maxsize and distances[u] + graph[u][v] < distances[v]:
                distances[v] = distances[u] + graph[u][v]

    return distances

def get_min_distance_vertex(distances, processed):
    min = sys.maxsize
    min_index = -1

    for v in range(len(distances)):
        if not processed[v] and distances[v] <= min:
            min = distances[v]
            min_index = v

    return min_index

if __name__ == "__main__":
    vertex_count = int(input())

    graph = []
    for i in range(vertex_count):
        graph.append([int(j) for j in input().split()])

    source = int(input())

    distances = dijkstra(graph, source)

    print("Shortest distances from source vertex " + str(source) + ":")
    for i in range(len(distances)):
        print("Vertex " + str(i) + " : " + str(distances[i]))

# 