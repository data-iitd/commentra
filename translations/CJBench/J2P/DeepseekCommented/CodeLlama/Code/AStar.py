
import heapq

class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]

    def get_neighbors(self, from_):
        return self.graph[from_]

    def add_edge(self, from_, to, weight):
        self.graph[from_].append((to, weight))
        self.graph[to].append((from_, weight))

class PathAndDistance:
    def __init__(self, distance, path):
        self.distance = distance
        self.path = path

def a_star(from_, to, graph, heuristic):
    queue = [(0, [from_])]
    while queue:
        distance, path = heapq.heappop(queue)
        current_position = path[-1]
        if current_position == to:
            return PathAndDistance(distance, path)
        for neighbor, weight in graph.get_neighbors(current_position):
            if neighbor not in path:
                updated_path = path + [neighbor]
                heapq.heappush(queue, (distance + weight + heuristic[neighbor], updated_path))
    return PathAndDistance(-1, None)

def main():
    nodes = int(input())
    edges = int(input())
    graph = Graph(nodes)
    for _ in range(edges):
        from_, to, weight = map(int, input().split())
        graph.add_edge(from_, to, weight)
    heuristic = list(map(int, input().split()))
    start = int(input())
    end = int(input())
    result = a_star(start, end, graph, heuristic)
    if result.path is not None:
        print("Shortest path:", result.path)
        print("Total distance:", result.distance)
    else:
        print("No path found")

if __name__ == "__main__":
    main()
