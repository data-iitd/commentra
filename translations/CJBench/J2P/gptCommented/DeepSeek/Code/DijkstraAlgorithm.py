import sys
import heapq

class Main:
    def __init__(self, vertex_count):
        self.vertex_count = vertex_count

    def run(self, graph, source):
        if source < 0 or source >= self.vertex_count:
            raise ValueError("Incorrect source vertex")

        distances = [sys.maxsize] * self.vertex_count
        processed = [False] * self.vertex_count
        distances[source] = 0

        for _ in range(self.vertex_count - 1):
            u = self.get_min_distance_vertex(distances, processed)
            processed[u] = True

            for v in range(self.vertex_count):
                if not processed[v] and graph[u][v] != 0 and distances[u] != sys.maxsize and distances[u] + graph[u][v] < distances[v]:
                    distances[v] = distances[u] + graph[u][v]

        return distances

    def get_min_distance_vertex(self, distances, processed):
        min_distance = sys.maxsize
        min_index = -1

        for v in range(self.vertex_count):
            if not processed[v] and distances[v] <= min_distance:
                min_distance = distances[v]
                min_index = v

        return min_index

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    vertex_count = int(data[index])
    index += 1
    graph = [[0] * vertex_count for _ in range(vertex_count)]

    for i in range(vertex_count):
        for j in range(vertex_count):
            graph[i][j] = int(data[index])
            index += 1

    source = int(data[index])
    index += 1

    dijkstra = Main(vertex_count)
    distances = dijkstra.run(graph, source)

    print("Shortest distances from source vertex " + str(source) + ":")
    for i in range(len(distances)):
        print("Vertex " + str(i) + " : " + str(distances[i]))
