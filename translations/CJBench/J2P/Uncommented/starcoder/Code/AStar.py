
import heapq
import sys

class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]

    def get_neighbours(self, from_):
        return self.graph[from_]

    def add_edge(self, from_, to_, weight):
        self.graph[from_].append((to_, weight))
        self.graph[to_].append((from_, weight))

class PathAndDistance:
    def __init__(self, distance, path):
        self.distance = distance
        self.path = path

    def get_distance(self):
        return self.distance

    def get_path(self):
        return self.path

def a_star(from_, to, graph, heuristic):
    queue = []
    heapq.heappush(queue, PathAndDistance(0, [from_]))
    while queue:
        current = heapq.heappop(queue)
        current_position = current.get_path()[-1]
        if current_position == to:
            return current
        for edge in graph.get_neighbours(current_position):
            if edge[0] not in current.get_path():
                updated_path = current.get_path() + [edge[0]]
                heapq.heappush(queue, PathAndDistance(current.get_distance() + edge[1], updated_path))
    return PathAndDistance(-1, None)

def main():
    scanner = sys.stdin
    nodes = int(scanner.readline())
    edges = int(scanner.readline())
    graph = Graph(nodes)
    for _ in range(edges):
        from_, to_, weight = map(int, scanner.readline().split())
        graph.add_edge(from_, to_, weight)
    heuristic = [int(scanner.readline()) for _ in range(nodes)]
    start, end = map(int, scanner.readline().split())
    result = a_star(start, end, graph, heuristic)
    if result.get_path() is not None:
        print("Shortest path: " + str(result.get_path()))
        print("Total distance: " + str(result.get_distance()))
    else:
        print("No path found")

if __name__ == "__main__":
    main()

