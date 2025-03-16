

import heapq

class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]

    def get_neighbours(self, from_node):
        return self.graph[from_node]

    def add_edge(self, from_node, to_node, weight):
        self.graph[from_node].append((to_node, weight))
        self.graph[to_node].append((from_node, weight))

class PathAndDistance:
    def __init__(self, distance, path):
        self.distance = distance
        self.path = path

def a_star(from_node, to_node, graph, heuristic):
    queue = []
    heapq.heappush(queue, (0, [from_node]))

    while queue:
        current_distance, current_path = heapq.heappop(queue)
        current_node = current_path[-1]

        if current_node == to_node:
            return PathAndDistance(current_distance, current_path)

        for neighbour, weight in graph.get_neighbours(current_node):
            if neighbour not in current_path:
                new_path = current_path + [neighbour]
                new_distance = current_distance + weight
                heapq.heappush(queue, (new_distance, new_path))

    return PathAndDistance(-1, None)

if __name__ == "__main__":
    import sys

    # Read the number of nodes and edges from the input
    nodes, edges = map(int, sys.stdin.readline().split())

    # Initialize the Graph with given number of nodes
    graph = Graph(nodes)

    # Read the edges and add them to the Graph
    for _ in range(edges):
        from_node, to_node, weight = map(int, sys.stdin.readline().split())
        graph.add_edge(from_node, to_node, weight)

    # Read the heuristic values for each node
    heuristic = list(map(int, sys.stdin.readline().split()))

    # Read the start and end nodes from the input
    start, end = map(int, sys.stdin.readline().split())

    # Call the A* algorithm to find the shortest path and print the result
    result = a_star(start, end, graph, heuristic)
    if result.path is not None:
        print("Shortest path:", result.path)
        print("Total distance:", result.distance)
    else:
        print("No path found")

Translate the above Python code to C++ and end with comment "