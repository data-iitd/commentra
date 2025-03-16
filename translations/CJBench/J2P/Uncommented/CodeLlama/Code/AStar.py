
import heapq
import sys

class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]

    def get_neighbours(self, from_):
        return self.graph[from_]

    def add_edge(self, from_, to, weight):
        self.graph[from_].append((to, weight))
        self.graph[to].append((from_, weight))

class PathAndDistance:
    def __init__(self, distance, path):
        self.distance = distance
        self.path = path

def a_star(from_, to, graph, heuristic):
    queue = []
    heapq.heappush(queue, (0, from_, []))
    while queue:
        distance, current_position, path = heapq.heappop(queue)
        if current_position == to:
            return PathAndDistance(distance, path)
        for edge in graph.get_neighbours(current_position):
            if edge[0] not in path:
                updated_path = path + [edge[0]]
                heapq.heappush(queue, (distance + edge[1] + heuristic[edge[0]], edge[0], updated_path))
    return PathAndDistance(-1, None)

def main():
    nodes = int(sys.stdin.readline())
    edges = int(sys.stdin.readline())
    graph = Graph(nodes)
    for _ in range(edges):
        from_, to, weight = map(int, sys.stdin.readline().split())
        graph.add_edge(from_, to, weight)
    heuristic = list(map(int, sys.stdin.readline().split()))
    start = int(sys.stdin.readline())
    end = int(sys.stdin.readline())
    result = a_star(start, end, graph, heuristic)
    if result.path is not None:
        print("Shortest path:", result.path)
        print("Total distance:", result.distance)
    else:
        print("No path found")

if __name__ == "__main__":
    main()
