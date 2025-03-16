import heapq
from typing import List, Tuple

class Edge:
    def __init__(self, from_: int, to: int, weight: int):
        self.from_ = from_
        self.to = to
        self.weight = weight

class PathAndDistance:
    def __init__(self, distance: int, path: List[int]):
        self.distance = distance
        self.path = path

    def get_distance(self) -> int:
        return self.distance

    def get_path(self) -> List[int]:
        return self.path

class Graph:
    def __init__(self, size: int):
        self.graph = [[] for _ in range(size)]

    def get_neighbours(self, from_: int) -> List[Edge]:
        return self.graph[from_]

    def add_edge(self, from_: int, to: int, weight: int):
        self.graph[from_].append(Edge(from_, to, weight))
        self.graph[to].append(Edge(to, from_, weight))

def a_star(from_: int, to: int, graph: Graph, heuristic: List[int]) -> PathAndDistance:
    queue = []
    heapq.heappush(queue, (0 + heuristic[from_], PathAndDistance(0, [from_])))

    while queue:
        current_distance, current_path = heapq.heappop(queue)
        current_position = current_path.path[-1]

        if current_position == to:
            return current_path

        for edge in graph.get_neighbours(current_position):
            if edge.to not in current_path.path:
                new_path = PathAndDistance(current_path.distance + edge.weight, current_path.path + [edge.to])
                heapq.heappush(queue, (new_path.distance + heuristic[new_path.path[-1]], new_path))

    return PathAndDistance(-1, [])

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    nodes = int(data[index])
    edges = int(data[index + 1])
    index += 2

    graph = Graph(nodes)

    for _ in range(edges):
        from_ = int(data[index])
        to = int(data[index + 1])
        weight = int(data[index + 2])
        graph.add_edge(from_, to, weight)
        index += 3

    heuristic = [int(data[index + i]) for i in range(nodes)]
    index += nodes

    start = int(data[index])
    end = int(data[index + 1])
    index += 2

    result = a_star(start, end, graph, heuristic)
    if result.path != [-1]:
        print(f"Shortest path: {result.path}")
        print(f"Total distance: {result.distance}")
    else:
        print("No path found")

if __name__ == "__main__":
    main()
