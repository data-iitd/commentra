

vertex_count = int(input())
graph = [[0 for _ in range(vertex_count)] for _ in range(vertex_count)]
for i in range(vertex_count):
    graph[i] = list(map(int, input().split()))
source = int(input())

class Main:
    def __init__(self, vertex_count):
        self.vertex_count = vertex_count

    def run(self, graph, source):
        if source < 0 or source >= self.vertex_count:
            raise ValueError("Incorrect source vertex")
        distances = [float('inf')] * self.vertex_count
        processed = [False] * self.vertex_count
        distances[source] = 0
        for count in range(self.vertex_count - 1):
            u = self.get_min_distance_vertex(distances, processed)
            processed[u] = True
            for v in range(self.vertex_count):
                if not processed[v] and graph[u][v]!= 0 and distances[u]!= float('inf') and distances[u] + graph[u][v] < distances[v]:
                    distances[v] = distances[u] + graph[u][v]
        return distances

    def get_min_distance_vertex(self, distances, processed):
        min_distance = float('inf')
        min_index = -1
        for v in range(self.vertex_count):
            if not processed[v] and distances[v] <= min_distance:
                min_distance = distances[v]
                min_index = v
        return min_index

dijkstra = Main(vertex_count)
distances = dijkstra.run(graph, source)
print("Shortest distances from source vertex {}:".format(source))
for i in range(len(distances)):
    print("Vertex {} : {}".format(i, distances[i]))

