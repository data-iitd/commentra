

import sys

def dijkstra(graph, source):
    vertex_count = len(graph)

    if source < 0 or source >= vertex_count:
        raise ValueError("Incorrect source vertex")

    distances = [sys.maxsize] * vertex_count
    processed = [False] * vertex_count
    distances[source] = 0

    for count in range(vertex_count - 1):
        u = get_min_distance_vertex(distances, processed)
        processed[u] = True

        for v in range(vertex_count):
            if not processed[v] and graph[u][v]!= 0 and distances[u]!= sys.maxsize and distances[u] + graph[u][v] < distances[v]:
                distances[v] = distances[u] + graph[u][v]

    return distances

def get_min_distance_vertex(distances, processed):
    min_distance = sys.maxsize
    min_index = -1

    for v in range(len(distances)):
        if not processed[v] and distances[v] <= min_distance:
            min_distance = distances[v]
            min_index = v

    return min_index

if __name__ == "__main__":
    vertex_count = int(input("Enter the number of vertices: "))

    graph = []
    for _ in range(vertex_count):
        row = list(map(int, input("Enter the weights of the edges for vertex {}: ".format(_)).split()))
        graph.append(row)

    source = int(input("Enter the source vertex: "))

    distances = dijkstra(graph, source)

    print("Shortest distances from source vertex {}:".format(source))
    for i, distance in enumerate(distances):
        print("Vertex {} : {}".format(i, distance))

