

import heapq

class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]

    def add_edge(self, from_node, to_node, weight):
        self.graph[from_node].append((to_node, weight))
        self.graph[to_node].append((from_node, weight))

class PathAndDistance:
    def __init__(self, distance, path):
        self.distance = distance
        self.path = path

def a_star(start, end, graph, heuristic):
    queue = []
    heapq.heappush(queue, (0, [start]))

    while queue:
        current_distance, current_path = heapq.heappop(queue)
        current_node = current_path[-1]

        if current_node == end:
            return PathAndDistance(current_distance, current_path)

        for neighbor, weight in graph.graph[current_node]:
            if neighbor not in current_path:
                new_path = current_path + [neighbor]
                new_distance = current_distance + weight
                heapq.heappush(queue, (new_distance, new_path))

    return PathAndDistance(-1, None)

if __name__ == "__main__":
    import sys

    nodes, edges = map(int, input().split())

    graph = Graph(nodes)
    for _ in range(edges):
        from_node, to_node, weight = map(int, input().split())
        graph.add_edge(from_node, to_node, weight)

    heuristic = list(map(int, input().split()))

    start, end = map(int, input().split())

    result = a_star(start, end, graph, heuristic)
    if result.path:
        print("Shortest path:", result.path)
        print("Total distance:", result.distance)
    else:
        print("No path found")

