import heapq
from typing import List, Tuple

class Edge:
    def __init__(self, from_node: int, to_node: int, weight: int):
        self.from_node = from_node
        self.to_node = to_node
        self.weight = weight

class Graph:
    def __init__(self, size: int):
        self.graph = [[] for _ in range(size)]

    def get_neighbours(self, from_node: int) -> List[Edge]:
        return self.graph[from_node]

    def add_edge(self, from_node: int, to_node: int, weight: int):
        self.graph[from_node].append(Edge(from_node, to_node, weight))
        self.graph[to_node].append(Edge(to_node, from_node, weight))

class PathAndDistance:
    def __init__(self, distance: int, path: List[int]):
        self.distance = distance
        self.path = path

    def get_distance(self) -> int:
        return self.distance

    def get_path(self) -> List[int]:
        return self.path

def a_star(from_node: int, to_node: int, graph: Graph, heuristic: List[int]) -> PathAndDistance:
    # PriorityQueue to explore nodes based on their distance and estimated cost to reach the destination
    queue = []
    heapq.heappush(queue, (0 + heuristic[from_node], PathAndDistance(0, [from_node])))

    while queue:
        current_distance, current = heapq.heappop(queue)
        current_position = current.get_path()[-1]  # current node

        # Check if the destination has been reached
        if current_position == to_node:
            return current

        # Avoid cycles by checking if the next node is already in the path
        for edge in graph.get_neighbours(current_position):
            if edge.to_node not in current.get_path():
                updated_path = current.get_path() + [edge.to_node]

                # Update the distance and heuristic for the new path
                heapq.heappush(queue, (current.get_distance() + edge.weight + heuristic[edge.to_node], PathAndDistance(current.get_distance() + edge.weight, updated_path)))

    return PathAndDistance(-1, None)  # No path found

def main():
    nodes = int(input())
    edges = int(input())

    graph = Graph(nodes)
    for _ in range(edges):
        from_node, to_node, weight = map(int, input().split())
        graph.add_edge(from_node, to_node, weight)

    heuristic = [int(input()) for _ in range(nodes)]

    start, end = map(int, input().split())

    result = a_star(start, end, graph, heuristic)
    if result.get_path() is not None:
        print("Shortest path:", result.get_path())
        print("Total distance:", result.get_distance())
    else:
        print("No path found")

if __name__ == "__main__":
    main()
