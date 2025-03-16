
import heapq

class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]

    def get_neighbours(self, from):
        return self.graph[from]

    def add_edge(self, from, to, weight):
        self.graph[from].append((from, to, weight))
        self.graph[to].append((to, from, weight))

class PathAndDistance:
    def __init__(self, distance, path):
        self.distance = distance
        self.path = path

def a_star(from, to, graph, heuristic):
    queue = [(0, [from])]
    while queue:
        distance, path = heapq.heappop(queue)
        current = path[-1]
        if current == to:
            return PathAndDistance(distance, path)
        for edge in graph.get_neighbours(current):
            if edge[1] not in path:
                updated_path = path + [edge[1]]
                heapq.heappush(queue, (distance + edge[2], updated_path))
    return PathAndDistance(-1, None)

def main():
    nodes = int(input())
    edges = int(input())
    graph = Graph(nodes)
    for _ in range(edges):
        from, to, weight = map(int, input().split())
        graph.add_edge(from, to, weight)
    heuristic = list(map(int, input().split()))
    start, end = map(int, input().split())
    result = a_star(start, end, graph, heuristic)
    if result.path is not None:
        print("Shortest path:", result.path)
        print("Total distance:", result.distance)
    else:
        print("No path found")

if __name__ == "__main__":
    main()

